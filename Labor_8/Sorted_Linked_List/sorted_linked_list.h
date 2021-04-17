//
// Created by csill on 4/17/2021.
//

#ifndef SORTED_LINKED_LIST_SORTED_LINKED_LIST_H
#define SORTED_LINKED_LIST_SORTED_LINKED_LIST_H

#include <stdbool.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

Node* create();

void insert(Node** front, int data);
void traverse(Node* front);
void destroy(Node* front);

int* statistics(Node* front);

int getKthDigit(Node* front, int k, int currPos);
int listLength(Node* front, int size);

bool isAscending(Node* front);

#endif //SORTED_LINKED_LIST_SORTED_LINKED_LIST_H
