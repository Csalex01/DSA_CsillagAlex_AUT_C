//
// Created by csill on 2/24/2021.
//

#include <stdlib.h>
#include <stdio.h>

#include "functions.h"

void printArr(int* arr, int n) {
    printf("A tomb: ");
    for(int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

void fillArr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

int linearSearch(int* arr, int n, int number) {
    for(int i = 0; i < n; i++)
        if(arr[i] == number)
            return i;
    return -1;
}