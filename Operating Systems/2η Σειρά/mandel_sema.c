/*
 * mandel.c
 *
 * A program to draw the Mandelbrot Set on a 256-color xterm.
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <semaphore.h>
#include "mandel-lib.h"
#include <pthread.h>
#include <signal.h>


#define MANDEL_MAX_ITERATION 1000000
#define NEXT(x) ((x + 1) % NUM_THREADS)

int NUM_THREADS;
sem_t *proc;
/***************************
 * Compile-time parameters *
 ***************************/

/*
 * Output at the terminal is is x_chars wide by y_chars long
*/
int y_chars = 50;
int x_chars = 90;

/*
 * The part of the complex plane to be drawn:
 * upper left corner is (xmin, ymax), lower right corner is (xmax, ymin)
*/
double xmin = -1.8, xmax = 1.0;
double ymin = -1.0, ymax = 1.0;
	
/*
 * Every character in the final output is
 * xstep x ystep units wide on the complex plane.
 */
double xstep;
double ystep;

/*
 * This function computes a line of output
 * as an array of x_char color values.
 */
void compute_mandel_line(int line, int color_val[])
{
	/*
	 * x and y traverse the complex plane.
	 */
	double x, y;

	int n;
	int val;

	/* Find out the y value corresponding to this line */
	y = ymax - ystep * line;

	/* and iterate for all points on this line */
	for (x = xmin, n = 0; n < x_chars; x+= xstep, n++) {

		/* Compute the point's color value */
		val = mandel_iterations_at_point(x, y, MANDEL_MAX_ITERATION);
		if (val > 255)
			val = 255;

		/* And store it in the color_val[] array */
		val = xterm_color(val);
		color_val[n] = val;
	}
}

/*
 * This function outputs an array of x_char color values
 * to a 256-color xterm.
 */
void output_mandel_line(int fd, int color_val[])
{
        int i;

        char point ='@';
        char newline='\n';
        for (i = 0; i < x_chars; i++) {
                /* Set the current color, then output the point */
                set_xterm_color(fd, color_val[i]); 
                if (write(fd, &point, 1) != 1) {
                        perror("compute_and_output_mandel_line: write point");
                        exit(1);
                }
        }

        /* Now that the line is done, output a newline character */
        if (write(fd, &newline, 1) != 1) {
                perror("compute_and_output_mandel_line: write newline");
                exit(1);
        }
}

void *compute_and_output_mandel_line(void *args)
{
	/*
	 * A temporary array, used to hold color values for the line being drawn
	 */
	int color_val[x_chars];
	int thread_num = *((int*) args);

	for (int i = thread_num; i < y_chars; i += NUM_THREADS) {
		compute_mandel_line(i, color_val);
		sem_wait(&proc[thread_num]);
		output_mandel_line(1, color_val);
		sem_post(&proc[NEXT(thread_num)]);
	}

return NULL;
}


int main(int argc, char *argv[]) {
    	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <num_threads>\n", argv[0]);
        	return 1;
    	}
 
	NUM_THREADS = atoi(argv[1]); 
	proc = (sem_t *)malloc(NUM_THREADS * sizeof(sem_t)); 
	
	if (proc == NULL) {
     	   	fprintf(stderr, "Memory allocation failed\n");
        	return 1;
    	}


    	for (int i = 0; i < NUM_THREADS; i++)
        	sem_init(&proc[i], 0, (i == 0) ? 1 : 0);

    	pthread_t threads[NUM_THREADS];
    	int thread_args[NUM_THREADS];

    	xstep = (xmax - xmin) / x_chars;
    	ystep = (ymax - ymin) / y_chars;

    	for (int i = 0; i < NUM_THREADS; i++) {
       		thread_args[i] = i;
    		pthread_create(&threads[i], NULL, compute_and_output_mandel_line, &thread_args[i]);
    	}

    	for (int i = 0; i < NUM_THREADS; i++) {
        	if (pthread_join(threads[i], NULL) != 0) {
            	fprintf(stderr, "Error joining thread %d\n", i);
           	return 1;
        	}
    	}

	free(proc);
return 0;
}
