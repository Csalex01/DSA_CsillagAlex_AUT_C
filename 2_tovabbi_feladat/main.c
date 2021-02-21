#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "functions.h"

int main() {
    srand(time(NULL));

    int len = 10;
    float* arr = (float*)malloc(len * sizeof(float));

    for(int i = 0; i < len; i++) {
        float num = (float)(rand() % 100);
        float denum = (float)(rand() % 20);
        arr[i] = num / denum;
    }

    printf("Sum: %f\n", sum(arr, len));
    printf("Product: %f\n", product(arr, len));
    printf("Average: %f\n", average(arr, len));

    free(arr);

    return 0;
}
