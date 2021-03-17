//
// Created by csill on 3/17/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "functions.h"

Stack *create(int capacity) {
    Stack *stack = (Stack *) malloc(sizeof(Stack));

    if (!stack) {
        printf("Error while allocating stack!");
        return NULL;
    }

    stack->maxSize = capacity;
    stack->sp = -1;
    stack->items = (int *) malloc(stack->maxSize * sizeof(int));

    if (!stack->items) {
        printf("Error while allocating stack items!");
        return NULL;
    }

    return stack;
}

bool isEmpty(Stack *stack) {
    return stack->sp == -1;
}

bool isFull(Stack *stack) {
    return stack->sp == stack->maxSize - 1;
}


int top(Stack *stack) {
    return stack->items[stack->sp];
}

int pop(Stack *stack) {
    int n = top(stack);
//    int n = stack->items[stack->sp];
    stack->sp--;
    return n;
}

void push(Stack *stack, int n) {
    stack->sp++;
    stack->items[stack->sp] = n;
}