//
// Created by csill on 6/3/2021.
//

#include "Stack.h"

struct Stack* createStack(int capacity) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));

    if(!newStack) {
        printf("Hiba a memoria allokacioban! (Verem#1)");
        return NULL;
    }

    newStack->maxSize = capacity;
    newStack->sp = -1;

    newStack->data = (char*)malloc(newStack->maxSize * sizeof(char));

    if(!newStack->data) {
        printf("Hiba a memoria allokacioban! (Verem#2)");

        free(newStack->data);
        free(newStack);

        return NULL;
    }

    return newStack;
}

bool isEmpty(struct Stack* stack) {
    return stack->sp == -1;
}

bool isFull(struct Stack* stack) {
    return stack->sp == stack->maxSize - 1;
}

void pop(struct Stack* stack) {
    if(isEmpty(stack)) {
        printf("A verem ures!\n");
        return;
    }

    stack->data[stack->sp] = '\0';
    stack->sp--;
}

char top(struct Stack* stack) {
    if(!isEmpty(stack))
        return stack->data[stack->sp];
}

void push(struct Stack* stack, char data) {
    if(isFull(stack))
        return;

    stack->sp++;
    stack->data[stack->sp + 1] = '\0';
    stack->data[stack->sp] = data;
}

void destroyStack(struct Stack* stack) {
//    free(stack->data);
    free(stack);

    stack = NULL;
}