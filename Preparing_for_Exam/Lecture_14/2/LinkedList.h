//
// Created by csill on 6/1/2021.
//

#ifndef LECTURE_14_LINKEDLIST_H
#define LECTURE_14_LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct LinkedList {
    int data;
    struct LinkedList* next;
} LinkedList;

struct LinkedList* createLinkedList();

void insertIntoLinkedList(struct LinkedList** front, int data, int index);

void increaseIndex(struct LinkedList* front, int index);

void traverseLinkedList(struct LinkedList* front);

#endif //LECTURE_14_LINKEDLIST_H
