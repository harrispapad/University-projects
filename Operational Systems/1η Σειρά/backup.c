#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "opensearch.h"
#include "proc.h"

int x = 10;
char cw;
char *input_file;
char *output_file;


int main (int argc, char *argv[]){

        input_file = argv[1];
        output_file = argv[2];
        cw = argv[3][0];

        open_file();

        pid_t p = fork();

        if (p < 0){
                perror("Fork");
                exit(1);
        }

        else if (p == 0) {
                child();
        }

        else {
                father();
        }

        close_file();

        printf("x = %d\n", x);

return 0;
}

