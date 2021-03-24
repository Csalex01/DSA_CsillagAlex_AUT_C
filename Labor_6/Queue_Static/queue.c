//
// Created by csill on 3/24/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "queue.h"

QUEUE *create(int capacity) {
    QUEUE *queue = (QUEUE *) malloc(sizeof(QUEUE));

    if (!queue) {
        printf("Failed to allocate memory for QUEUE!");
        return NULL;
    }

    queue->maxSize = capacity;
    queue->front = queue->rear = -1;

    queue->items = (int *) malloc(queue->maxSize * sizeof(int));

    if (!queue->items) {
        printf("Failed to allocate QUEUE items!");
        free(queue);

        return NULL;
    }

    return queue;
}

bool isEmpty(QUEUE *queue) {
    return queue->front == -1 || queue->front > queue->rear;
}

bool isFull(QUEUE *queue) {
    return queue->rear == queue->maxSize - 1;
}

int get(QUEUE *queue) {
    if(isEmpty(queue)) {
        printf("QUEUE EMPTY\n");
        return INT_MIN;
    }

    int tmp = frontElement(queue);
    queue->front++;

    return tmp;
}

int frontElement(QUEUE *queue) {
    if (!isEmpty(queue))
        return queue->items[queue->front];

    printf("QUEUE EMPTY\n");
    return INT_MIN;
}

void put(QUEUE *queue, int n) {
    if (isFull(queue)) {
        printf("QUEUE FULL\n");
        return;
    }

    if (queue->front == -1 && queue->rear == -1) {
        queue->front = 0;
    }

    queue->items[++queue->rear] = n;
}
