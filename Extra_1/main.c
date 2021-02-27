#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
    int n;

    printf("n: ");
    scanf("%i", &n);

    int *arr = (int *) malloc(n * sizeof(int));

    if (!arr) {
        printf("Error while allocating memory for array!");
        return -1;
    }

    initializeArr(arr, n);
    printArr(arr, n);


    int peakIndex = peak(arr, n);

    if (peakIndex > 0)
        printf("Max peak index: %i (%i)", peakIndex, arr[peakIndex]);
    else
        printf("No peak found!");

    free(arr);

    return 0;
}
