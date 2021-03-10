//
// Created by csill on 3/9/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "functions.h"

IntArray *createArray(int dimension) {
    IntArray *tmp = (IntArray *) malloc(sizeof(dimension));

    if (!tmp) {
        printf("Could not allocate memory!");
        return NULL;
    }

    tmp->size = dimension;
    tmp->elements = (int *) malloc(dimension * sizeof(int));

    if (!tmp->elements) {
        printf("Could not allocate array!");
        free(tmp);
        return NULL;
    }

    return tmp;
}

int findElement(IntArray *array, int element) {
    for (int i = 0; i < array->size; i++)
        if (array->elements[i] == element)
            return i;

    return -1;
}

int minimum(IntArray *array) {
    int min = array->elements[0];
    for (int i = 0; i < array->size; i++)
        if (array->elements[i] < min)
            min = array->elements[i];
    return min;
}

int maximum(IntArray *array) {
    int max = array->elements[0];
    for (int i = 0; i < array->size; i++)
        if (array->elements[i] > max)
            max = array->elements[i];
    return max;
}

void readArray(const char *fileName, IntArray **array) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Could not open file! (%s)", fileName);
        return;
    }

    int n;
    fscanf(fin, "%i", &n);

    IntArray *buffer = createArray(n);

    if (!buffer) {
        printf("Could not allocate buffer!");
        fclose(fin);
        free(fin);
        free(buffer);
        return;
    }

    for (int i = 0; i < buffer->size; i++)
        fscanf(fin, "%i", &buffer->elements[i]);

    *array = buffer;
    fclose(fin);
}

void fillArray(IntArray *array, int dimension, int first, int last) {
    srand(time(NULL));

    for (int i = 0; i < dimension; i++)
        array->elements[i] = (rand() % last + 1) + first;
}

void printArray(IntArray *array) {
    printf("Array: ");
    for (int i = 0; i < array->size; i++)
        printf("%i ", array->elements[i]);
    printf("\n");
}

void printArrayToFile(const char *fileName, IntArray *array) {
    FILE *fout = fopen(fileName, "wt");

    if (!fout) {
        printf("Could not open output file!");
        return;
    }

    fprintf(fout, "%i\n", array->size);
    for (int i = 0; i < array->size; i++)
        fprintf(fout, "%i ", array->elements[i]);
}

void sortArray(IntArray *array) {
    if (array->size == 0 || array->size == 1)
        return;

    for (int i = 0; i < array->size - 1; i++)
        for (int j = 0; j < array->size - i - 1; j++)
            if (array->elements[j] > array->elements[j + 1]) {
                int tmp = array->elements[j];
                array->elements[j] = array->elements[j + 1];
                array->elements[j + 1] = tmp;
            }

}

void deleteElement(IntArray *array, int element) {
    int index = findElement(array, element);

    if (index == -1)
        return;

    for (int i = index; i < array->size - 1; i++)
        array->elements[i] = array->elements[i + 1];

    array->elements[array->size - 1] = 0;
    array->size--;
}

void copy(IntArray *arrayTo, IntArray *arrayFrom) {
    if (!arrayFrom || arrayTo->size > arrayFrom->size)
        return;

    arrayTo->elements = (int *) malloc(arrayTo->size * sizeof(int));

    for (int i = 0; i < arrayTo->size; i++)
        arrayTo->elements[i] = arrayFrom->elements[i];
}