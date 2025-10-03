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
	int j = 1;
	int sub_seq = numbers[1];
	int diff;
	int min = 10000;

	do {
		diff = abs(total_count - 2 * sub_seq);
		if (diff < min) min = diff;

		if (k == j) {
			if (k == (size - 1)) break;
			j++;
			sub_seq += numbers[j];
		}
		else if (j >= (size - 1) || sub_seq >= (total_count - sub_seq)) {
			sub_seq -= numbers[k];
			k++;
		}
		else {
			j++;
			sub_seq += numbers[j];
		}

	} while(k != (size));

	printf("%d\n", min);
    

    	fclose(fptr);
    	free(numbers);

return 0;
}
