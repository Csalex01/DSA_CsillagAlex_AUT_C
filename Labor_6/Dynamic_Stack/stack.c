#include <stdlib.h>
#include <stdio.h>

#include "stack.h"

Node* create() {
    Node* node = (Node*)malloc(sizeof(Node));

    if(!node) {
        printf("Error while allocating node!");
        return NULL;
    }

    node->next = NULL;

    return node;
}

void push(Node** topPtr, int data) {
    Node* newNode = create();

    if(!newNode) {
        printf("Error while allocating new node!");
        return;
    }

    newNode->data = data;
    newNode->next = *topPtr;
    *topPtr = newNode;
}

bool isEmpty(Node* topPtr) {
    return topPtr->next == NULL;
}

int top(Node* topPtr) {
    if(!isEmpty(topPtr))
        return topPtr->data;
}

int pop(Node** topPtr) {
    if(isEmpty(*topPtr))
        return INT_MIN;

    Node* aux = *topPtr;
    int auxData = aux->data;
    *topPtr = aux->next;

    free(aux);

    return auxData;
}