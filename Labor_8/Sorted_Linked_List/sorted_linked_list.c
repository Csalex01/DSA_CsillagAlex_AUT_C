//
// Created by csill on 4/17/2021.
//

#include <stdlib.h>
#include <stdio.h>

#include "sorted_linked_list.h"

Node* create() {
    Node* newNode = (Node*)calloc(1, sizeof(Node));

    if(!newNode) {
        printf("Error while allocating newNode!");
        return NULL;
    }

    newNode->data = INT_MIN;
    newNode->next = NULL;

    return newNode;
}

void insert(Node** front, int data) {
    Node* newNode = create();
    newNode->data = data;

    if(*front == NULL || (*front)->data >= newNode->data) {
        newNode->next = (struct Node *) *front;
        *front = newNode;
    } else {
        Node* p = *front;

        while(p->next != NULL /* NEM MEGY! */) {
            p = (Node *) p->next;
        }
    }
}

int* statistics(Node* front) {
    int* stats = (int*)calloc(listLength(front, 0), sizeof(int));

    if(!stats) {
        printf("Failed to allocate memory for statstics!");
        return NULL;
    }

    for(int i = 0; i < listLength(front, 0); i++) {
        stats[getKthDigit(front, i, 0)]++;
    }

    return stats;
}

int getKthDigit(Node* front, int k, int currPos) {
    if(k == currPos) {
        return front->data;
    }

    return getKthDigit((Node *) front->next, k, currPos + 1);
}

int listLength(Node* front, int size) {
    if(!front) {
        return size;
    }

    listLength((Node *) front->next, size + 1);
}

void traverse(Node* front) {
    if(!front) {
        printf("\n");
        return;
    }

    printf("%i ", front->data);
    traverse((Node *) front->next);
}

void destroy(Node* front) {
    if(front->next)
        destroy((Node *) front->next);

    free(front);
    front = NULL;
}

bool isAscending(Node* front) {
    Node* tmp = front;

    int prevValue = tmp->data;
    tmp = (Node *) tmp->next;

    while(tmp) {
        if(tmp->data <= prevValue)
            return false;

        prevValue = tmp->data;
        tmp = (Node *) tmp->next;
    }

    return true;
}