//
// Created by csill on 4/20/2021.
//

#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

NodeLinkedList *createNodeLinkedList() {
    NodeLinkedList *newNodeLinkedList = (NodeLinkedList *) calloc(1, sizeof(NodeLinkedList));

    if (!newNodeLinkedList) {
        printf("Error while allocating newNodeLinkedList!");
        return NULL;
    }

    newNodeLinkedList->data = INT_MIN;
    newNodeLinkedList->next = NULL;

    return newNodeLinkedList;
}

void insertNodeLinkedList(NodeLinkedList **front, int data, int index) {
    NodeLinkedList *newNodeLinkedList = createNodeLinkedList();
    newNodeLinkedList->data = data;

    if (front == NULL || index == 0) {
        newNodeLinkedList->next = (struct NodeLinkedList *) *front;
        *front = newNodeLinkedList;
    } else {
        NodeLinkedList *p = *front;
        int i = 1;

        while (p->next != NULL && i < index) {
            p = (NodeLinkedList *) p->next;
            i++;
        }

        newNodeLinkedList->next = p->next;
        p->next = (struct NodeLinkedList *) newNodeLinkedList;
    }
}

void printLinkedList(NodeLinkedList *front, FILE *output_even, FILE *output_odd) {
    if (!front || !output_even || !output_odd)
        return;

    if (front->data % 2)
        fprintf(output_odd, "%i ", front->data);
    else
        fprintf(output_even, "%i ", front->data);

    printLinkedList((NodeLinkedList *) front->next, output_even, output_odd);
}

void destroyLinkedList(NodeLinkedList *front) {
    if (front->next)
        destroyLinkedList((NodeLinkedList *) front->next);

    free(front);
    front = NULL;
}