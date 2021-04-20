//
// Created by csill on 4/20/2021.
//

#ifndef INC_2021_I_PARCIALIS_A_STACK_H
#define INC_2021_I_PARCIALIS_A_STACK_H

#include <stdbool.h>

typedef struct {
    int maxSize;
    int sp;
    int *items;
} NodeStack;

NodeStack *createNodeStack(int capacity);

bool isEmpty(NodeStack *stack);

bool isFull(NodeStack *stack);

char pop(NodeStack *stack);

void insertNodeStack(NodeStack *stack, char n);

void destroyNodeStack(NodeStack *stack);

void printStack(NodeStack *stack, FILE *output_vowels);

#endif //INC_2021_I_PARCIALIS_A_STACK_H