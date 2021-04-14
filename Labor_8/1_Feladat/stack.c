//
// Created by csill on 4/14/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

Node *createStack() {
    Node *node = (Node *) malloc(sizeof(Node));

    if (!node) {
        printf("Error while allocating node!");
        return NULL;
    }

    node->next = NULL;

    return node;
}

Node *readFromFile(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Failed to open file: %s", fileName);
        return NULL;
    }

    Node *stack = createStack();

    char tmp;

    while (fscanf(fin, "%c ", &tmp) != EOF)
        if ((tmp >= 'a' && tmp <= 'z') || (tmp >= 'A' && tmp <= 'Z'))
            push(&stack, tmp);

    return stack;
}

void push(Node **topPtr, char data) {
    Node *newNode = createStack();

    if (!newNode) {
        printf("Error while allocating new node!");
        return;
    }

    newNode->data = data;
    newNode->next = (struct Node *) *topPtr;
    *topPtr = newNode;
}

bool isEmpty(Node *topPtr) {
    return topPtr->next == NULL;
}

int pop(Node **topPtr) {
    if (isEmpty(*topPtr))
        return INT_MIN;

    Node *aux = *topPtr;
    char auxData = aux->data;
    *topPtr = (Node *) aux->next;

    free(aux);

    return auxData;
}