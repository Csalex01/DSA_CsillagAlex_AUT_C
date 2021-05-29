//
// Created by csill on 5/29/2021.
//

#ifndef LECTURE_14_BINARYSEARCHTREE_H
#define LECTURE_14_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct BinarySearchTree {
    int data;

    struct BinarySearchTree *left;
    struct BinarySearchTree *right;

} BinarySearchTree;

struct BinarySearchTree* createBST(int data);

void insert(struct BinarySearchTree** tree, int data);

void traverse(struct BinarySearchTree* tree);

void printBetweenTwoLevels(struct BinarySearchTree* tree, int n, int m, int i);

#endif //LECTURE_14_BINARYSEARCHTREE_H
