////
//// Created by csill on 4/14/2021.
////
//
//#include <stdlib.h>
//#include <stdio.h>
//
//#include "queue.h"
//
//Node *create() {
//    Node *newNode = (Node *) malloc(sizeof(Node));
//
//    if (!newNode) {
//        printf("Error while allocationg newNode!");
//        return NULL;
//    }
//
//    newNode->next = NULL;
//
//    return newNode;
//}
//
//void readFromFile(Node **uppercase, Node **lowercase, char *fileName) {
//    FILE *fin = fopen(fileName, "rt");
//
//    if (!fin) {
//        printf("Failed to open file: %s", fileName);
//
//        uppercase = NULL;
//        lowercase = NULL;
//
//        return;
//    }
//
//    *uppercase = create();
//    *lowercase = create();
//
//    char data;
//    int lowercaseIndex = 0;
//    int uppercaseIndex = 0;
//
//    while (fscanf(fin, "%c ", &data) != EOF)
//        if (data >= 'a' && data <= 'z')
//            insert(lowercase, data, lowercaseIndex++);
//        else
//            insert(uppercase, data, uppercaseIndex++);
//
//    if(lowercaseIndex > uppercaseIndex)
//        printf("LOWERCASE");
//    else
//        printf("UPPERCASE");
//    printf("\n");
//
//}
//
//void insert(Node **front, char data, int index) {
//    Node *newNode = create();
//    newNode->data = data;
//
//    if (front == NULL || index == 0) {
//        newNode->next = (struct Node *) *front;
//        *front = newNode;
//    } else {
//        Node *p = *front;
//
//        int i = 1;
//        while (p->next != NULL && i < index) {
//            p = (Node *) p->next;
//            i++;
//        }
//
//        newNode->next = p->next;
//        p->next = (struct Node *) newNode;
//    }
//}
//
//void traverse(Node *front) {
//    while(front->next != NULL) {
//        printf("%c ", front->data);
//        front = (Node *) front->next;
//    }
//}