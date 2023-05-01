#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

#define DIM 1024

void imprimir(double *m)
{
  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
      printf("%8.2f ", *(m + i * DIM + j));
    printf("\n");
  }
}

void mult_mat(double *c, double *a, double *b)
{
  clock_t start_time, end_time;
  double total_time;

  start_time = clock();
#pragma omp parallel
  {
    int i, j, k;
#pragma omp for
    for (i = 0; i < DIM; i++)
      for (j = 0; j < DIM; j++)
      {
        *(c + i * DIM + j) = 0.0;
        for (k = 0; k < DIM; k++)
          *(c + i * DIM + j) += *(a + i * DIM + k) * *(b + k * DIM + j);
      }
  }
  end_time = clock();

  total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
  printf("Total execution time: %lf seconds. \n", total_time);
}

int main(int argc, char *argv[])
{
  double *a, *b, *c;

  a = (double *)malloc(sizeof(double) * DIM * DIM);
  assert(a != NULL);
  b = (double *)malloc(sizeof(double) * DIM * DIM);
  assert(b != NULL);
  c = (double *)malloc(sizeof(double) * DIM * DIM);
  assert(c != NULL);

  for (int i = 0; i < DIM; i++)
  {
    for (int j = 0; j < DIM; j++)
    {
      *(b + i * DIM + j) = i * DIM + j;
      *(a + i * DIM + j) = 0.0;
    }
    *(a + i * DIM + i) = 1.0;
  }

  mult_mat(c, a, b);
  // imprimir(c);
  return 0;
}
