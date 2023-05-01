# Multiplicacion de matrices

<br>

## **Sequential**

`mult_matrices_sequential.c`
```
 gcc mult_matrices_sequential.c -o mult.out
 ./mult.out
```

<br>

## **Parallel**

`mult_matrices_parallel.c`
```
 gcc -fopenmp mult_matrices_parallel.c -o mult_parralel.out
 ./mult_parralel.out
```

To specify the amount of threads you want to use, run:
```
 OMP_NUM_THREADS=12 ./mult_parralel.out
```