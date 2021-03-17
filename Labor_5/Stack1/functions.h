//
// Created by csill on 3/17/2021.
//

#ifndef STACK1_FUNCTIONS_H
#define STACK1_FUNCTIONS_H

#include <stdbool.h>

typedef struct {
    int maxSize;
    int sp;
    int *items;
} Stack;

Stack *create(int capacity);

bool isEmpty(Stack *stack);

bool isFull(Stack *stack);

int pop(Stack *stack);

int top(Stack *stack);

void push(Stack *stack, int n);

#endif //STACK1_FUNCTIONS_H