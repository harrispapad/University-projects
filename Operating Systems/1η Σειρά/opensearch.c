#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int counter = 0;
extern char *input_file;
extern char *output_file;
extern char cw;
int fdi;
int fdo;

void open_file(){
        
	fdi = open(input_file, O_RDONLY); //άνοιγμα αρχείου ανάγνωσης
        if (fdi == -1){
                perror("Error opening input file");
                exit(1);
        }
}


void search(){
	int *i;
        i = (int*) malloc(1 * sizeof(int));
        *i = 0;

        char *c;
        c = (char*) malloc(1 * sizeof(char));

        char buff[1];

        ssize_t sz;

	do {                                    //διατρέχουμε όλο το αρχείο χαρακτήρα-χαρακτήρα 
                sz = read(fdi, &buff[*i], 1);

                if(sz == -1) {
                        perror("Error reading input file");
                        exit(1);
                }

                *c = buff[*i];          //αναζήτηση χαρακτήρα
                if (*c == cw)
                        counter++;
        } while(sz > 0);

        if(close(fdi) == -1){
                perror("Error closing input file");
                exit(1);
        }
	
free(i);
free(c);	
}

void write_result(){
        int fdo = open(output_file, O_CREAT | O_RDWR | O_TRUNC, 00700); //άνοιγμα αρχείου εγγραφής
        if (fdo == -1){
                perror("Error opening output file");
                exit(1);
        }


	char buffer[70];

	int len = snprintf(buffer, sizeof(buffer), "The character '%c' was found %d times in your file!", cw, counter);

        ssize_t out = write(fdo, buffer, len);

        if(out == -1) {
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
