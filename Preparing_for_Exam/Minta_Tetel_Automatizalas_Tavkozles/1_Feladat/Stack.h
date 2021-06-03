//
// Created by csill on 6/3/2021.
//

#ifndef MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_STACK_H
#define MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct Stack {
    int maxSize;
    int sp;

    char* data;
} Stack;

struct Stack* createStack(int capacity);

bool isEmpty(struct Stack* stack);

bool isFull(struct Stack* stack);

void pop(struct Stack* stack);

char top(struct Stack* stack);

void push(struct Stack* stack, char data);

void destroyStack(struct Stack* stack);

#endif //MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_STACK_H
