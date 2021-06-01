//
// Created by csill on 6/1/2021.
//

#include "LinkedList.h"

LinkedList *createLinkedList() {
    struct LinkedList *list = (struct LinkedList *) malloc(sizeof(struct LinkedList));

    if (!list) {
        printf("Error while allocating newNode!");
        return NULL;
    }

    list->data = INT_MIN;
    list->next = NULL;

    return list;
}

void insertIntoLinkedList(struct LinkedList **front, int data, int index) {
    struct LinkedList *newNode = createLinkedList();
    newNode->data = data;

    if (front == NULL || index == 0) {
        newNode->next = *front;
        *front = newNode;
    } else {
        struct LinkedList *p = *front;

        int i = 1;

        while (p->next != NULL && i < index) {
            p = p->next;
            i++;
        }

        newNode->next = p->next;
        p->next = newNode;
    }
}

void increaseIndex(struct LinkedList *front, int index) {
    printf("\nINDEX %i\n", index);

    struct LinkedList *tmp = front;

    int i = 0;

    while (i <= index && tmp) {
        printf("%i ", i);

        if (tmp->next)
            tmp = tmp->next;

        i++;
    }

    tmp->data++;
}

void traverseLinkedList(struct LinkedList *front) {
    if (!front) {
        printf("\n");
        return;
    }

    printf("%i ", front->data);

    if (front->next)
        traverseLinkedList(front->next);
}