#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

#include "opensearch.h"

extern int x;

void father(){
	printf("This is process %d.\n", getpid());
	int status;
	waitpid((-1), &status, 0);
	printf("I am done waiting.\n");
}

void child(){
	printf("Hello! I am process %d and my father is process %d.\n", getpid(), getppid());
	//x = 20;

	//search();
	//write_result();
	
	//char *args[] = {"./a1", "toystory.txt", "output.txt", "a", NULL};
        //execv("./a1", args);
                //perror("execv");

}

