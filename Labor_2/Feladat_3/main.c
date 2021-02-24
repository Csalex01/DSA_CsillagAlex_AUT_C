#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

#define N 100

int main() {
    srand(time(NULL));

    int* arr = (int*)malloc(N * sizeof(int));
    int number = rand() % 100;

    fillArr(arr, N);
    printArr(arr, N);

    qsort(arr, N, sizeof(int), helper);

    printArr(arr, N);

    printf("A keresett elem: %i\n", number);
    printf("A keresett elem indexe: %i", binarySearch(arr, 0, N, number));

    free(arr);

    return 0;
}
