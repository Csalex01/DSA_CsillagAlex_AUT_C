//
// Created by csill on 2/24/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

void fillArr(int* arr, int n) {
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

void printArr(int* arr, int n) {
    printf("A tomb: ");
    for(int i = 0; i < n; i++)
        printf("%i ", arr[i]);
    printf("\n");
}

int helper(const void* p1, const void* p2) {
    return *(int*)p1 - *(int*)p2;
}


int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);


        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
}