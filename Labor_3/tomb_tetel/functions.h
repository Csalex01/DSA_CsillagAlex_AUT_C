//
// Created by csill on 3/9/2021.
//

#ifndef TOMB_TETEL_FUNCTIONS_H
#define TOMB_TETEL_FUNCTIONS_H

typedef struct {
    int size;
    int* elements;
} IntArray;

IntArray* createArray(int dimension);

int findElement(IntArray* array, int element);
int minimum(IntArray* array);
int maximum(IntArray* array);

void readArray(const char* fileName, IntArray **array);
void fillArray(IntArray* array, int dimension, int first, int last);
void printArray(IntArray* array);
void printArrayToFile(const char* fileName, IntArray* array);
void sortArray(IntArray* array);
void deleteElement(IntArray* array, int element);
void copy(IntArray* arrayTo, IntArray* arrayFrom);

#endif //TOMB_TETEL_FUNCTIONS_H
