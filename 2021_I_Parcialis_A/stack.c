//
// Created by csill on 4/20/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "stack.h"

NodeStack *createNodeStack(int capacity) {
    NodeStack *stack = (NodeStack *) malloc(sizeof(NodeStack));

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

bool isEmpty(NodeStack *stack) {
    return stack->sp == -1;
}

bool isFull(NodeStack *stack) {
    return stack->sp == stack->maxSize - 1;
}


char top(NodeStack *stack) {
    return stack->items[stack->sp];
}

char pop(NodeStack *stack) {
    char n = top(stack);
    stack->sp--;
    return n;
}

void insertNodeStack(NodeStack *stack, char n) {
    if (!isFull(stack)) {
        stack->sp++;
        stack->items[stack->sp] = n;
    }
}

void printStack(NodeStack *stack, FILE *output_vowels) {
    if (!stack || !output_vowels) {
        return;
    }

    while(!isEmpty(stack)) {
        char tmp = pop(stack);

        if (strchr("aeiouAEIOU", tmp))
            fprintf(output_vowels, "%c ", tmp);
    }
}