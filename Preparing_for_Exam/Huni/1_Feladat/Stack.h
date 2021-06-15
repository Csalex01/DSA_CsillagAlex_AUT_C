#ifndef HUNI_STACK_H
#define HUNI_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
    char *data;

    int sp;
    int maxSize;
} Stack;

struct Stack *createStack(int capacity);

bool isEmptyStack(struct Stack *stack);

bool isFullStack(struct Stack *stack);

char popStack(struct Stack *stack);

char topStack(struct Stack *stack);

void pushStack(struct Stack *stack, char c);

void destroyStack(struct Stack *stack);

#endif //HUNI_STACK_H
