//
// Created by csill on 5/12/2021.
//

#ifndef EURO_HEAP_H
#define EURO_HEAP_H

#include "Exchange.h"

typedef struct Heap {
    Exchange** data;
    int size;
    int maxSize;
} Heap;

Heap* createHeap(int max);

Heap* readFromFile(char* fileName);

Exchange* deleteMax(Heap* heap);

void insert(Heap* heap, Exchange* exchange);

void up(Heap* heap, int i);

void down(Heap* heap, int i);

void heapSort(Heap* heap, int n);

Heap* readFromFile(char* fileName);

#endif //EURO_HEAP_H
