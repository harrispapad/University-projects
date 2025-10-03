#include <stdio.h>
#include <stdlib.h>

int main() {
   int rows, i, j, blank;
   printf("Enter an integer number ");
   scanf("%d", &rows);
   for (i = rows; i >= 1; --i) {
      for (blank = 0; blank < rows - i; ++blank)
         printf("  ");
      for (j = i; j <= 2 * i - 1; ++j)
         printf("* ");
      for (j = 0; j < i - 1; ++j)
         printf("* ");
      printf("\n");
   }

int k=0;
   for (i = 1; i <= rows; ++i, k = 0) {
      for (blank = 1; blank <= rows - i; ++blank) {
         printf("  ");
      }
      while (k != 2 * i - 1){
         printf("* ");
         ++k;
      }
      printf("\n");
   }
   return 0;
}
