#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    
	FILE *fptr = fopen(argv[1], "r");
    
        int size;
        fscanf(fptr, "%d", &size);

    	int *numbers = (int *)malloc(size * sizeof(int));
    	int i = 0;
    	int total_count = 0;
	while (i < size) {
		fscanf(fptr, "%d", &numbers[i]);
        	total_count += numbers[i];
		i++;
	}
			
	int k = 1;
	int j = size - 1;
	int rest = numbers[0];
	int sub_seq;
	int diff;
	int min = 10000;
	
	printf("Total count = %d\n", total_count);

	do {
		sub_seq = total_count - rest;
		printf("rest = %d\n", rest);
		diff = abs(total_count - 2 * rest);
		printf("diff = %d\n", diff);
		if (min > diff)
			min = diff;
		if (sub_seq > rest){
			rest += numbers[k];
			k++;
			printf("k = %d\n", k);
		}
		else{
			sub_seq += numbers[j];
			j--;
			printf("j = %d\n", j);
		}
		printf("sub_seq = %d\n", sub_seq);
	} while(k != (j+1));


	printf("%d\n", min);
    

    	fclose(fptr);
    	free(numbers);

return 0;
}
