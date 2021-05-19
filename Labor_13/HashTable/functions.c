//
// Created by csill on 5/19/2021.
//

#include "functions.h"

int search(int k, const int *T, int m) {
    int j, i = 0;

    do {
        j = (k + i) % m;

        if (T[j] == k)
            return j;

        else
            i++;

    } while (T[j] != -1 && i != m);

    return -1;
}

void insert(int k, int *T, int m) {
    int j, i = 0;

    do {
        j = (k + i) % m;

        if (T[j] == -1) {
            T[j] = k;
            return;
        } else
            i++;

    } while (i != m);

    printf("Overflow!");
}

void delete(int k, int *T, int m) {
    int j, i = 0;

    do {
        j = (k + i) % m;

        if (T[j] == k) {
            T[j] = -1;
            return;

        } else
            i++;

    } while (T[j] != -1 && i != m);

    if (i != m)
        printf("Element not found! (%i)\n", k);
}


void print(int *T, int m) {
    for (int i = 0; i < m; i++)
        printf("%i ", T[i]);
    printf("\n");
}