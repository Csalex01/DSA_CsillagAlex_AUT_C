//
// Created by csill on 3/24/2021.
//

#ifndef QUEUE_STATIC_QUEUE_H
#define QUEUE_STATIC_QUEUE_H

#include <stdbool.h>

typedef struct {
    int maxSize;
    int front, rear;
    int* items;
} QUEUE;

QUEUE* create(int capacity);

bool isEmpty(QUEUE* queue);
bool isFull(QUEUE* queue);

int get(QUEUE* queue);
int frontElement(QUEUE* queue);

void put(QUEUE* queue, int n);


#endif //QUEUE_STATIC_QUEUE_H
