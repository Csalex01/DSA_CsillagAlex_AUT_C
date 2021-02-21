#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    srand(time(NULL));

    int len = 10;
    float* arr = (float*)malloc(len * sizeof(float));

    for(int i = 0; i < len; i++)
    {
        float num = (float)(rand() % 100);
        float denum = (float) (rand() % 20);
        arr[i] = num / denum;
    }

    printArray(arr, len);
    reverseArr(arr, len);

    free(arr);

    return 0;
}
