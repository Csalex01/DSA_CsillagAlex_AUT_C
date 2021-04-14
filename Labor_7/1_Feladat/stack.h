//
// Created by csill on 4/14/2021.
//

#ifndef INC_1_FELADAT_STACK_H
#define INC_1_FELADAT_STACK_H

#include <stdbool.h>

typedef struct {
    char data;
    struct Node* next;
} Node;

Node* createStack();

Node* readFromFile(char* fileName);

void push(Node** topPtr, char data);

bool isEmpty(Node* topPtr);

int pop(Node** topPtr);

#endif //INC_1_FELADAT_STACK_H