#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

const int N = 1000000000;

int main() {

    srand(time(NULL));

    int *arr = (int *) malloc(N * sizeof(int));
//    int number = rand() % N;

    printf("%i", N);

    fillArr(arr, N, N);

    int number = arr[N - 1] / 2;

    clock_t start = clock();
    int result = linearSearch(arr, N, number);
    clock_t stop = clock();

    double diff = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("A keresett elem: %i\n", number);
    printf("A keresett elem indexe: %i\n", result);
    printf("Lefutasi ido: %f", diff);

    free(arr);

    return 0;
}
