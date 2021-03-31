//
// Created by csill on 3/31/2021.
//

#ifndef FELADAT_1_LINKED_LIST_H
#define FELADAT_1_LINKED_LIST_H

#include <stdbool.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* create();

void insert(Node** front, int data, int index);
void traverse(Node* front);
void destroy(Node* front);

int* statistics(Node* front);

int getKthDigit(Node* front, int k, int currPos);
int listLength(Node* front, int size);

bool isAscending(Node* front);

#endif //FELADAT_1_LINKED_LIST_H
