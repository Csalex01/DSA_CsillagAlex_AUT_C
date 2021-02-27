//
// Created by csill on 2/27/2021.
//

#include <stdio.h>

#include "functions.h"

void initializeArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%i]: ", i);
        scanf("%i", &arr[i]);
    }
}

void printArr(int *arr, int n) {
    printf("Arr: ");

    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

int peak(int *arr, int n) {
    if (n < 3)
        return -1;

    int max = arr[0];
    int max_i = -1;

    for(int i = 1; i < n - 1; i++)
        if(arr[i - 1] < arr[i] && arr[i + 1] < arr[i] && max < arr[i]) {
            max = arr[i];
            max_i = i;
        }

    if(arr[n - 1] > max)
        max_i = n - 1;

    return max_i;
}