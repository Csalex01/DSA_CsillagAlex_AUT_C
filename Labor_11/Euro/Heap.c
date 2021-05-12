//
// Created by csill on 5/12/2021.
//

#include "Heap.h"

Heap* createHeap(int max) {
    Heap* heap = (struct Heap*)malloc(sizeof(struct Heap));

    if(!heap) {
        printf("Failed to allocate memory for Heap.");
        return NULL;
    }

    heap->size = 0;
    heap->maxSize = max;
    *heap->data = createExchange();

    return heap;
}

Exchange* deleteMax(Heap* heap) {
    Exchange* tmp = heap->data[0];
    heap->data[0] = heap->data[heap->size];
    heap->data[heap->size] = tmp;

    heap->size--;

    return tmp;
}

void insert(Heap* heap, Exchange* exchange) {
    heap->size++;
    heap->data[heap->size] = exchange;
    up(heap, heap->size);
}

void up(Heap* heap, int i) {
    while(i > 0 && !compare(heap->data[i / 2], heap->data[i])) {
        Exchange* tmp = heap->data[i / 2];
        heap->data[i / 2] = heap->data[i];
        heap->data[i] = tmp;

        i /= 2;
    }
}

void down(Heap* heap, int i) {
    while(2 * i < heap->size) {
        int j = 2 * i;

        if(j < heap->size && !compare(heap->data[j], heap->data[j + 1]))
            i++;

        if(!compare(heap->data[j], heap->data[i]))
            break;

        Exchange* tmp = heap->data[i];
        heap->data[i] = heap->data[j];
        heap->data[j] = tmp;

        i = j;
    }
}

void heapSort(Heap* heap, int n) {
    for(int i = n / 2; i >= 0; i--)
        down(heap, i);

    for(int i = 0; i < n; i++) {
        deleteMax(heap);
        down(heap, 1);
    }
}


Heap* readFromFile(char* fileName) {
    FILE* fin = fopen(fileName, "rt");

    if(!fin) {
        printf("Failed to open file %s.", fileName);
        return NULL;
    }

    int n;
    fscanf(fin, "%i", &n);

    Heap* heap = createHeap(n);

    if(!heap) {
        return NULL;
    }

    for(int i = 0; i < n; i++) {
        Exchange* tmp = createExchange();

        fscanf(fin, "%i", &tmp->year);
        fscanf(fin, "%i", &tmp->month);

        int exchangeRate;
        fscanf(fin, "%i", &exchangeRate);

        tmp->penny = exchangeRate % 100;
        exchangeRate /= 100;
        tmp->forint = exchangeRate;

        insert(heap, tmp);
    }

    fclose(fin);
    fin = NULL;

    return heap;
}