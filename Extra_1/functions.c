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

int peak(const int *arr, int n) {
    /**
     * Ha a tömb hossza kisebb mint 3, nincs ahogy egy domb létrejőjjön.
     * Például: 121, 131, 154, 352, stb...
     */
    if (n < 3)
        return -1;

    /**
     * Feltételezzük, hogy az első elem a legnagyobb.
     */
    int max = arr[0];
    int max_i = -1;

    /**
     * A feltételezett csúcs mindkét oldalát nézi, ha a baloldali elem
     * kisebb, és a jobboldali elem nagyobb mint a kurrens elem, akkor
     * csúcsról beszélünk.
     */
    for (int i = 1; i < n - 1; i++)
        if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i] && max < arr[i]) {
            max = arr[i];
            max_i = i;
        }

    /**
     * A tömb utolsó elemét külön le kell kezelni, mivel a for-cikluson belül
     * csak (n-2)-ig néztük (0-tól indexelve).
     */
    if (arr[n - 1] > max)
        max_i = n - 1;

    /**
     * Visszatérítsük a legmagasabb csúcs indexét.
     */
    return max_i;
}