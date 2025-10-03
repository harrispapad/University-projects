#include "stdio.h"
#include "stdlib.h"

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int size;
    fscanf(fptr, "%d", &size);

    if (size <= 0) {
        printf("Invalid size.\n");
        fclose(fptr);
        return 1;
    }

    int *numbers = (int *)malloc(size * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        return 1;
    }

    int i = 0;
    int total_count = 0;
    while (i < size) {
        fscanf(fptr, "%d", &numbers[i]);
        total_count += numbers[i];
        i++;
    }

    int k = 1;
    int j = size - 1;
    int fair_seq = total_count - numbers[0];
    int diff;
    int min = 10000;

    while (k != j) {
        diff = total_count - fair_seq;
        if (min > diff)
            min = diff;
        if (diff > fair_seq) {
            fair_seq -= numbers[k]; // Use k instead of i
            k++;
        } else {
            fair_seq -= numbers[j];
            j--;
        }
    }

    printf("%d\n", min);

    fclose(fptr);
    free(numbers);

    return 0;
}

