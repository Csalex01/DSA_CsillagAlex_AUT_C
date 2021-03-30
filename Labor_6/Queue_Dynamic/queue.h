//
// Created by csill on 3/30/2021.
//

#ifndef QUEUE_DYNAMIC_QUEUE_H
#define QUEUE_DYNAMIC_QUEUE_H

#include <stdbool.h>

typedef struct {
    int data;
    struct Node *next;
} Node;

Node* create();

bool isEmpty(Node* front);

int delete(Node** front);

void insert(Node** front, Node** last, int data);

void traverse(Node* front);

int getIndex(Node* front, int index, int currPos);

#endif //QUEUE_DYNAMIC_QUEUE_H
