#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int counter = 0;
int fdi;
int fdo;
char cw;
char *input_file;
char *output_file;


void open_file();
void search();
void write_result();
void close_file();


int main (int argc, char *argv[]){

        //έλεγχος ότι καλείται σωστά το πρόγραμμα και τα ορίσματα
        if(argc != 4){			
                printf("Syntax: ./q1 input_file output_file character\n");
                exit(3);
        }

        input_file = argv[1];
        output_file = argv[2];
        cw = argv[3][0];

        open_file();
	
	search();

	write_result();

	close_file();


return 0;
}

void open_file(){

        fdi = open(input_file, O_RDONLY); //άνοιγμα αρχείου ανάγνωσης
        if (fdi == -1){
                perror("Error opening input file");
                exit(1);
        }
}


void search(){
	char c;
        char buff[1];

        ssize_t sz;

        do {                                    //διατρέχουμε όλο το αρχείο χαρακτήρα-χαρακτήρα 
                sz = read(fdi, &buff[0], 1);

                if(sz == -1) {
                        perror("Error reading input file");
                        exit(1);
                }

                c = buff[0];          //αναζήτηση χαρακτήρα
                if (c == cw)
                        counter++;
        } while(sz > 0);

        if(close(fdi) == -1){
                perror("Error closing input file");
                exit(1);
        }


}


void write_result(){
        int fdo = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 00700); //άνοιγμα αρχείου εγγραφής
        if (fdo == -1){
                perror("Error opening output file");
                exit(1);
        }


        char buffer[70];

        int len = snprintf(buffer, sizeof(buffer), "The character '%c' was found %d times in your file!\n", cw, counter);

        if(write(fdo, buffer, len) == -1){
                perror("Error writing output file");
                exit(1);
        }
}



void close_file(){
        if(close(fdo) == -1){
                perror("Error closing output file");
                exit(1);
        }
}

