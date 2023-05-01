# Multiplicacion de matrices

<br>

## **Seqential**

`mult_matrices_sequential.c` does it in a sequential manner.
```
 gcc mult_matrices_sequential.c -o mult.out
 ./mult.out
```

<br>

## **Parallel**

`mult_matrices_parallel.c` &ensp; divides generation/calculation of all the points use to make the pi stimation between all the threads
```
 gcc -fopenmp mult_matrices_parallel.c -o mult_parralel.out
 ./mult_parralel.out
```

To specify the amount of threads you want to use, run:
```
 OMP_NUM_THREADS=12 ./mult_parralel.out
```