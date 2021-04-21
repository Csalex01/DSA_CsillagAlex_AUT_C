//
// Created by csill on 4/21/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Tomb_DinamikusVerem.h"

/*
 * Ez a függvény lefoglal egy P adatstruktúrának helyet a memóriában
 */
P *createP(int capacity) {
    /// Lefoglalja a helyet
    P *newP = (P *) calloc(capacity, sizeof(P));

    /// Hibaellenőrzés
    if (!newP) {
        printf("Hiba a memoriaallokacio kozben!");
        return NULL;
    }

    /// newP mezőonek értékadása
    newP->nr = capacity;
    newP->numbers = (int *) calloc(capacity, sizeof(int));

    /// Hibaellenőrzés
    if (!newP->numbers) {
        printf("Hiba a memoriaallokacio kozben!");

        /// Memóriafelszabadítás
        free(newP);
        newP = NULL;

        return NULL;
    }

    return newP;
}

/*
 * Ez a függvény beolvas egy tomböt egy fájlból
 */
P *readArrayFromFile(char *fileName) {
    /// Megnyissa a fájlt
    FILE *fin = fopen(fileName, "rt");

    /// Hibakezelés
    if (!fin) {
        printf("Hiba az allomany megnyitasakor!");
        return NULL;
    }

    /// Ideiglenes változó adott mérettel
    P *newP = createP(30);

    int i = 0;

    /// Feltölti a tömböt, fájl végéig olvas
    while (fscanf(fin, "%i", &(newP->numbers[i])) != EOF) {
        i++;
    }

    return newP;
}

/*
 * Ez a függvény kiírja a tömböt a standard outputra
 */
void printP(P *array) {
    printf("Array: ");
    for (int i = 0; i < array->nr; i++)
        printf("%i ", array->numbers[i]);
    printf("\n");
}

/*
 * Ez a függvény létrehoz egy verem struktúrát a memóriában
 */

NType *createStack() {
    NType *node = (NType *) calloc(1, sizeof(NType));

    if (!node) {
        printf("Error while allocating node!");
        return NULL;
    }

    node->k = NULL;

    return node;
}

/*
 * Ez a függvény beolvas egy vermet egy fájlból.
 * Nagyon hasonlít az eddig megírt függvényhez.
 */
NType *readStackFromFile(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Hiba az allomany megnyitasakor!");
        return NULL;
    }

    NType *stack = createStack();

    int tmp;

    while (fscanf(fin, "%i", &tmp) != EOF) {
        push(&stack, tmp);
    }

    return stack;
}

/*
 * Ez a függvény beszúr egy elemet a verem tetejére
 */
void push(NType **stack, int n) {
    NType *newNType = createStack();

    if (!newNType) {
        printf("Error while allocating new node!");
        return;
    }

    newNType->n = n;
    newNType->k = *stack;
    *stack = newNType;
}

/*
 * Megmondja, hogy üres-e egy verem vagy nem
 */
bool isEmpty(NType *topPtr) {
    return topPtr->k == NULL;
}

/*
 * Ez a függvény leveszi és visszatéríti a verem legfelső elemét
 */
int pop(NType **stack) {
    if (isEmpty(*stack))
        return INT_MIN;

    NType *aux = *stack;
    int auxData = aux->n;
    *stack = aux->k;

    free(aux);

    return auxData;
}

/*
 * Ez a függvény kiírja a képernyőre a vermet
 */
void printStack(NType *stack) {
    if (stack == NULL)
        return;

    printf("%i ", stack->n);

    if (stack->k)
        printStack(stack->k);
}

float atlagokFeleStack(NType *stack) {
    NType *tmp = stack;

    float atlag = 0;
    int db = 0;

    while (tmp->k != NULL) {
        atlag += tmp->n;
        tmp = tmp->k;
        db++;
    }

    return (atlag / db) / 2;
}

float atlagokFeleTomb(P *array) {
    float atlag = 0;

    for (int i = 0; i < array->nr; i++)
        atlag += array->numbers[i];

    return (atlag / array->nr) / 2;
}

bool mindenSzamPozitivStack(NType *stack) {
    NType *tmp = stack;

    while (tmp->k != NULL) {
        if (tmp->n < 0)
            return false;
        tmp = tmp->k;
    }

    return true;
}

bool mindenSzamPozitivTomb(P *array) {
    for (int i = 0; i < array->nr; i++)
        if (array->numbers[i] < 0)
            return false;

    return true;
}

int paratlanSzamStack(NType* stack) {
    NType* tmp = stack;
    int db = 0;

    while(tmp->k != NULL) {
        if(tmp->n % 2)
            db++;
        tmp = tmp->k;
    }

    return db;
}

int paratlanSzamTomb(P* array) {
    int db = 0;

    for(int i = 0; i < array->nr; i++)
        if(array->numbers[i] % 2)
            db++;

    return db;
}