//
// Created by csill on 2/21/2021.
//

#include "functions.h"
#include <math.h>

int positive(int* arr, int len) {
    int counter = 0;

    for(int i = 0; i < len; i++)
        if(arr[i] >= 0)
            counter++;

    return counter;
}

int negative(int* arr, int len) {
    int counter = 0;

    for(int i = 0; i < len; i++)
        if(arr[i] < 0)
            counter++;

    return counter;
}

int even(int* arr, int len) {
    int counter = 0;

    for(int i = 0; i < len; i++)
        if(abs(arr[i]) % 2 == 0)
            counter++;

    return counter;
}

int odd(int* arr, int len) {
    int counter = 0;

    for(int i = 0; i < len; i++)
        if(abs(arr[i]) % 2 != 0)
            counter++;

    return counter;
}