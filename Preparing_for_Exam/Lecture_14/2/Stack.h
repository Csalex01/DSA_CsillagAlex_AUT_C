//
// Created by csill on 5/29/2021.
//

#ifndef LECTURE_14_STACK_H
#define LECTURE_14_STACK_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Stack {
    int year;
    int month;
    int day;

    struct Stack* next;
} Stack;

struct Stack* createStack();

struct Stack* readStackFromFile(char* fileName);

bool isEmpty(struct Stack* stack);

void push(Stack** topPtr, int year, int month, int day);

void traverseStack(struct Stack* stack);

#endif //LECTURE_14_STACK_H
