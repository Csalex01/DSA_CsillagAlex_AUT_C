#ifndef HUNI_BINARYSEARCHTREE_H
#define HUNI_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct BST {
    char data;

    struct BST* left;
    struct BST* right;

} BST;

struct BST* createBST(char c);

struct BST* deleteBST(struct BST* tree, char data);

struct BST* minValueBST(struct BST* tree);

int depthBST(struct BST* tree);

void insertBST(struct BST** tree, char c);

void traverseBST(struct BST* tree);

void destroyBST(struct BST* tree);

#endif //HUNI_BINARYSEARCHTREE_H
