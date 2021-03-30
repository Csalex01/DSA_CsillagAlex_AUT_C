//
// Created by csill on 3/30/2021.
//

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Node* create() {
    Node* node = (Node*)calloc(1, sizeof(Node));

    if(!node) {
        printf("Error while allocating node!");
        return NULL;
    }

    node->data = INT_MIN;
    node->next = NULL;

    return node;
}

bool isEmpty(Node* front) {
    return front == NULL;
}

int delete(Node** front) {
    if(isEmpty(*front))
        return INT_MIN;

    Node* aux = *front;
    int auxData = aux->data;

    front = (Node **) (*front)->next;
    free(aux);

    return auxData;
}

void insert(Node** front, Node** last, int data) {
    Node* node = create();

    if(!node) {
        printf("Failed to create node while inserting data!");
        return;
    }

    node->data = data;

    if(isEmpty(*front))
        *front = *last = node;
    else {
        (*last)->next = (struct Node *) node;
        (*last) = node;
    }
}

void traverse(Node* front) {
    if(front == NULL)
        return;

    printf("%i ", front->data);
    traverse((Node *) front->next);

}

int getIndex(Node* front, int index, int currPos) {
    if(front == NULL)
        return INT_MIN;

    if(currPos == index)
        return front->data;

    return getIndex((Node *) front->next, index, currPos + 1);
}