#include <stdio.h>

void LUdecomposition(float a[10][10], float l[10][10], float u[10][10], int n) {

   int i = 0, j = 0, k = 0;

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         if (j < i)
         l[j][i] = 0;
         else {
            l[j][i] = a[j][i];
            for (k = 0; k < i; k++) {
               l[j][i] = l[j][i] - l[j][k] * u[k][i];
            }
         }
      }

      for (j = 0; j < n; j++) {
         if (j < i)
            u[i][j] = 0;
         else if (j == i)
            u[i][j] = 1;
         else {
            u[i][j] = a[i][j] / l[i][i];
            for (k = 0; k < i; k++) {
               u[i][j] = u[i][j] - ((l[i][k] * u[k][j]) / l[i][i]);
            }
         }
      }
   }
}


int main() {

   float a[10][10], l[10][10], u[10][10], multiply[10][10];
   int n = 0, i = 0, j = 0, sum = 0, c, d, k;

   printf("Enter size of square matrix : \n");
   scanf("%d", &n);

   printf("Enter matrix values: \n");

   for (i = 0; i < n; i++)
   for (j = 0; j < n; j++)
   scanf("%f", &a[i][j]);

   LUdecomposition(a, l, u, n);
   printf("L Decomposition: \n");

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%f ", l[i][j]);
      }
      printf("\n");
   }

   printf("U Decomposition: \n");

   for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
         printf("%f ", u[i][j]);
      }
      printf("\n");
   }
/*
   for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++) {
        for (k = 0; k < n; k++) {
          sum = sum + l[c][k]*u[k][d];
        }

        multiply[c][d] = sum;
        sum = 0;
      }
    }

     printf("Product of the matrices:\n");

    for (c = 0; c < n; c++) {
      for (d = 0; d < n; d++)
        printf("%f\t", multiply[c][d]);

      printf("\n");
    }

*/

   return 0;
}
