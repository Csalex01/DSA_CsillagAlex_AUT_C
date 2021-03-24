//
// Created by csill on 3/24/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void insertNewItemToQueue(QUEUE *queue) {
    printf("---------------\n1.\n");

    int n;

    printf("Enter a number you want to insert: ");
    scanf("%i", &n);

    if (!isFull(queue))
        put(queue, n);
}

void removeFromQueue(QUEUE *queue) {
    printf("---------------\n2.\n");

    int tmp = get(queue);

    if (tmp != INT_MIN)
        printf("Removed item from queue: %i\n\n", tmp);
}

void firstItemInQueue(QUEUE *queue) {
    printf("---------------\n3.\n");

    int tmp = frontElement(queue);

    if (tmp != INT_MIN)
        printf("First item in the queue: %i.\n\n", tmp);
}