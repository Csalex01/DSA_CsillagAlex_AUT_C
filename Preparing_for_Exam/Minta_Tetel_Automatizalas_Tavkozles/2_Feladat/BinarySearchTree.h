//
// Created by csill on 6/3/2021.
//

#ifndef MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_BINARYSEARCHTREE_H
#define MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct BST {
    char data;
    struct BST *left;
    struct BST *right;
} BST;

struct BST *createBST(char data);

struct BST* minValueNode(struct BST* tree);

struct BST* deleteFromBST(struct BST* tree, char data);

int depth(struct BST* tree);

void insert(struct BST **tree, char data);

void traverse(struct BST *tree);

void destroy(struct BST* tree);

#endif //MINTA_TETEL_AUTOMATIZALAS_TAVKOZLES_BINARYSEARCHTREE_H
