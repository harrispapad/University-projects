#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define P 5

void handle_sigint(int sig){
	printf("Number of workers: %d\n", P);
}

int main(int argc, char *argv[]){
	if (argc != 4){		//έλεγχος παραμέτρων εισόδου
                printf("Syntax: ./q3 'input_file' 'output_file' 'character'\n");
                exit(1);
        }	

	struct sigaction father_sa;     //χειρισμός sigint με εκτύπωση μηνύματος
        father_sa.sa_handler = handle_sigint;
        if (sigaction(SIGINT, &father_sa, NULL) == -1) {
                perror("Error handling signal");
                exit(1);
        }

	
	char *input_file = argv[1];
	char *output_file = argv[2];
	char cw = argv[3][0];

	int fdi;	//file descriptor αρχείου εισόδου
	int fdo;	//file descriptor αρχείου εξόδου
	char c;

	fdi = open(input_file, O_RDONLY);	//άνοιγμα αρχείου εισόδου
        if(fdi == -1) {
                perror("Error opening input file.\n");
                exit(1);
        }

	fdo = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 00700);	//άνοιγμα αρχείου εξόδου
        if(fdo == -1) {
                perror("Error opening output file.\n");
                exit(1);
        }

	long int size = lseek(fdi, 0, SEEK_END);	//εύρεση μεγέθους αρχείου
	long int split = size / P;			//χωρισμός στα παιδιά
	long int mod = size % P;			//υπόλοιπο διαίρεσης

	int pipefds[P][2];	
	for(int i = 0; i < P; i++){			//δημιουργία pipes, ένα για κάθε παιδί
        	if(pipe(pipefds[i]) == -1){
                	perror("Error during making pipe\n");
                	exit(1);
                }
	}

	pid_t p;
	int child_counter;

	for(int i = 0; i < P; i++) {			//δημιουργία P παιδιών
                p = fork();     
                if(p < 0) {
                        perror("Error during Fork.\n");
                        exit(1);
                }
                else if(p == 0) {
                      	struct sigaction child_sa;      //χειρισμός sigint για τα παιδιά με αγνόηση σήματος
                        child_sa.sa_handler = SIG_IGN;
                        if (sigaction(SIGINT, &child_sa, NULL) == -1) {
                                perror("Error registering child signal handler");
                                exit(1);
                        }
			
			child_counter = 0;
			ssize_t sz;
			char buff[split];
        		off_t offset = i * split;	//μετακίνηση offset εκεί που έμεινε ο προηγούμενος
			if (i == P - 1)			//το υπόλοιπο της διαίρεσης πάει στο τελευταίο παιδί
				split += mod;

                	sz = pread(fdi, buff, split, offset);

                	if (sz == -1) {
                        	perror("Error reading input file.\n");
                        	exit(1);
                	}
				
			for (int j = 0; j < sz; j++){	//αναζήτηση χαρακτήρα στο κομμάτι του κάθε παιδιού
                		c = buff[j];
               	 		if(c == cw)
                        		child_counter++;
			}
	
			printf("Child number: %d found: %d.\n",getpid(), child_counter);

			//Εγγραφή στο pipe
        		if (write(pipefds[i][1], &child_counter, sizeof(child_counter)) == -1){ 
                		perror("Error writing to pipe.\n");
                		exit(1);
        		}
			
			close(pipefds[i][1]);	//κλείνουμε άκρο εγγραφής

                        exit(0);
                }
        
	sleep(1);	
	}

	wait(NULL);

	int total_counter = 0;

	for(int i = 0; i < P; i++) {
     		 if(read(pipefds[i][0], &child_counter, sizeof(child_counter)) == -1){
                                perror("Error reading from pipe.\n");
                                exit(1);
                 }

		total_counter += child_counter;
		close(pipefds[i][0]);		//κλείνουμε άκρο ανάγνωσης
	}
 
 	char buffer[70];
	//μήνυμα για αρχείο εξόδου
        int len = snprintf(buffer, sizeof(buffer), "The character '%c' was found %d times in your file!\n", cw, total_counter);

        if(write(fdo, buffer, len) == -1) {
                perror("Error writing output file.\n");
                exit(1);
        }

	
	//κλείνουμε αρχείο εισόδου
	if(close(fdi) == -1) {
                perror("Error closing input file.\n");
                exit(1);
        }

	//κλείνουμε αρχείο εξόδου
	if(close(fdo) == -1) {
                perror("Error closing output file.\n");
                exit(1);
        }


return 0;
}
