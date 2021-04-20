//
// Created by csill on 4/20/2021.
//

#ifndef INC_2021_I_PARCIALIS_A_LINKED_LIST_H
#define INC_2021_I_PARCIALIS_A_LINKED_LIST_H

#include <stdio.h>

typedef struct {
    int data;
    struct NodeLinkedList *next;
} NodeLinkedList;

NodeLinkedList *create();

void insertNodeLinkedList(NodeLinkedList **front, int data, int index);

void printLinkedList(NodeLinkedList *front, FILE *output_even, FILE *output_odd);

void destroyLinkedList(NodeLinkedList *front);

#endif //INC_2021_I_PARCIALIS_A_LINKED_LIST_H
