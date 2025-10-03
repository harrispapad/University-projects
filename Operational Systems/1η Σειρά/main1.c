#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "opensearch.h"

int main (int argc, char *argv[]){

        input_file = argv[1];
        output_file = argv[2];
        cw = argv[3][0];

        open_file();
	
	search();

	write_result();

	close_file();


return 0;
}
