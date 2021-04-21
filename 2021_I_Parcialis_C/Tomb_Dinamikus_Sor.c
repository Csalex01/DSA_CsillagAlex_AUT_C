//
// Created by csill on 4/21/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "Tomb_Dinamikus_Sor.h"


/*
 * Ez a függvény lefoglal egy F adatstruktúrának helyet a memóriában
 */
F *createF(int capacity) {
    /// Lefoglalja a helyet
    F *newF = (F *) calloc(capacity, sizeof(F));

    /// Hibaellenőrzés
    if (!newF) {
        printf("Hiba a memoriaallokacio kozben!");
        return NULL;
    }

    /// newF mezőonek értékadása
    newF->c = capacity;
    newF->num = (int *) calloc(capacity, sizeof(int));

    /// Hibaellenőrzés
    if (!newF->num) {
        printf("Hiba a memoriaallokacio kozben!");

        /// Memóriafelszabadítás
        free(newF);
        newF = NULL;

        return NULL;
    }

    return newF;
}

/*
 * Ez a függvény beolvas egy tomböt egy fájlból
 */
F* readArrayFromFileF(char* fileName) {
    /// Megnyissa a fájlt
    FILE *fin = fopen(fileName, "rt");

    /// Hibakezelés
    if (!fin) {
        printf("Hiba az allomany megnyitasakor!");
        return NULL;
    }

    /// Ideiglenes változó adott mérettel
    F *newF = createF(30);

    int i = 0;

    /// Feltölti a tömböt, fájl végéig olvas
    while (fscanf(fin, "%i", &(newF->num[i])) != EOF) {
        i++;
    }

    /// Visszatéríti a tömböt
    return newF;
}

/*
 * Ez a függvény kiírja a tömböt a standard outputra
 */
void printF(F *array) {
    printf("Array: ");
    for (int i = 0; i < array->c; i++)
        printf("%i ", array->num[i]);
    printf("\n");
}

/*
 * Ez a függvény létrehoz egy várakozási sort a memóriában
 */
N_Type* createQueue() {
    /// Legoflalja a helyet
    N_Type* node = (N_Type*)calloc(1, sizeof(N_Type));

    /// Hibaellenőrzés
    if(!node) {
        printf("Error while allocating node!");
        return NULL;
    }

    /// Mezők inicializálása
    node->e = INT_MIN;
    node->k = NULL;

    /// Visszatéríti a sort
    return node;
}

/*
 * Ez a függvény beolvas egy sort egy fájlból.
 * Nagyon hasonlít az eddig megírt függvényhez.
 */
void readFromFileQueue(char* fileName, N_Type* front, N_Type* last) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Hiba az allomany megnyitasakor!");
        return;
    }

    int tmp;

    while(fscanf(fin, "%i", &tmp) != EOF) {
        insertQueue(tmp, &front, &last);
    }

}

/*
 * Megmondja, hogy üres-e egy sor vagy nem
 */
bool isEmptyQueue(N_Type* front) {
    return front == NULL;
}

/*
 * Beszúr egy sorba egy elemet
 */
void insertQueue(N_Type** front, N_Type** last, int data) {
    /// Átmeneti node
    N_Type* node = createQueue();

    /// Hibakezelés
    if(!node) {
        printf("Failed to create node while inserting data!");
        return;
    }

    node->e = data;

    /// Ha üres akkor a front és a last pointer ugyan arra mutat
    if(isEmptyQueue(*front))
        *front = *last = node;
    else {
        /// Különben az utolsó mutat az átmeneti node-ra és felveszi a "k" mezője a címét
        (*last)->k = (struct N_Type *) node;
        (*last) = node;
    }
}

/*
 * Ez a függvény iteratívan bejárja a sort
 */
void traverse(N_Type* front) {
    if(front == NULL)
        return;

    N_Type* next = front;

    while(next != NULL) {
        printf("%i ", next->e);
        next = (N_Type *) next->k;
    }
}

/*
 * Visszatéríti az első 19-el osztható elem gyökét, egyszerű lineáris keresés.
 */
float elso19gyokTomb(F* array) {
    for(int i = 0; i < array->c; i++)
        if(array->num[i] >= 0 && array->num[i] % 19 == 0)
            return sqrt(array->num[i]);

    return -1;
}

/*
 * Visszatéríti a sor átlagának a négyzetét
 */
float atlagokNegyzeteTomb(F* array) {
    float atlag = 0;

    for(int i = 0; i < array->c; i++)
        atlag += array->num[i];

    /// Függvény használata (hatványozás)
    return pow(atlag / array->c, 2);
}

/*
 * Visszatéríti-e, hogy minden egyes elem nagyobb-e mint 10
 */
bool mindenSzamNagyobb10Tomb(F* array) {
    for(int i = 0; i < array->c; i++)
        if(array->num[i] <= 10)
            return false;

    return true;
}