//
// Created by csill on 5/29/2021.
//

#include "BinarySearchTree.h"

struct BinarySearchTree *createBST(int data) {
    struct BinarySearchTree *tree = (struct BinarySearchTree *) malloc(sizeof(struct BinarySearchTree));

    if (!tree) {
        printf("Error while allocating memory for BST!");
        return NULL;
    }

    tree->data = data;
    tree->left = NULL;
    tree->right = NULL;

    return tree;
}

void insert(struct BinarySearchTree **tree, int data) {
    if ((*tree) == NULL) {
        (*tree) = createBST(data);
    } else {
        if ((*tree)->data > data)
            insert(&((*tree)->left), data);
        else if ((*tree)->data < data)
            insert(&((*tree)->right), data);
    }
}


void traverse(struct BinarySearchTree *tree) {
    if (tree->left)
        traverse(tree->left);

    printf("%i ", tree->data);

    if (tree->right)
        traverse(tree->right);
}


void printBetweenTwoLevels(struct BinarySearchTree *tree, int n, int m, int i) {
    if (tree == NULL || i > m)
        return;

    if (i < n) {
        printBetweenTwoLevels(tree, n, m, i + 1);
    } else {
        if (i > n && i <= m)
            printf("%i ", tree->data);

        printBetweenTwoLevels(tree->left, n, m, i + 1);
        printBetweenTwoLevels(tree->right, n, m, i + 1);
    }
}