//
// Created by csill on 2/24/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "functions.h"

void printArr(int* arr, int n) {
    printf("A tomb: ");
    for(int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

void fillArr(int* arr, int n, int max) {
    for(int i = 0; i < n; i++)
        arr[i] = rand() % max;
}

int linearSearch(int* arr, int n, int number) {
    clock_t begin = clock();
    clock_t end;

    int foundIndex = -1;

    for(int i = 0; i < n && foundIndex == -1; i++)
        if(arr[i] == number) {
            end = clock();
            foundIndex = i;
        }

//    end = clock();
    double diff = (double)(end - begin);

    printf("%ld %ld \n", begin, end);

    printf("Futasi ido: %f\n", diff);

    return foundIndex;

}