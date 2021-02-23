#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    int len = 10;
    int* arr = (int*)malloc(len * sizeof(int));

    for(int i = 0; i < len; i++) {
        arr[i] = rand() % 100;

        if(rand() % 2 == 0)
            arr[i] *= (-1);
    }

    printf("Positive: %i\n", positive(arr, len));
    printf("Negative: %i\n", negative(arr, len));
    printf("Even: %i\n", even(arr, len));
    printf("Odd: %i\n", odd(arr, len));

    free(arr);

    return 0;
}
