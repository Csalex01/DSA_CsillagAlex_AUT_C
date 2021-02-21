//
// Created by csill on 2/21/2021.
//

#include "functions.h"
#include <stdio.h>

int printArray(float* arr, int len) {
    printf("The array: ");

    for(int i = 0; i < len; i++)
        printf("%0.3f, ", arr[i]);
    printf("\b\b \n");
}

void reverseArr(float* arr, int len) {
    printf("The reversed array: ");
    for(int i = len - 1; i >= 0; i--)
        printf("%0.3f, ", arr[i]);
    printf("\b\b \n");
}