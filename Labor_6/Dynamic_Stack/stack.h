//
// Created by csill on 3/29/2021.
//

#ifndef DYNAMIC_STACK_STACK_H
#define DYNAMIC_STACK_STACK_H

#include <stdbool.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* create();

void push(Node** topPtr, int data);

int top(Node* topPtr);
int pop(Node** topPtr);

bool isEmpty(Node* topPtr);

#endif //DYNAMIC_STACK_STACK_H
