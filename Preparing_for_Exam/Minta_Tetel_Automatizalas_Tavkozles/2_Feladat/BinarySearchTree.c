//
// Created by csill on 6/3/2021.
//

#include "BinarySearchTree.h"

struct BST *createBST(char data) {
    struct BST *tree = (struct BST *) malloc(sizeof(struct BST));

    if (!tree) {
        printf("Hiba a memoria allokacioban! (BST#1)");
        return NULL;
    }

    tree->data = data;
    tree->left = tree->right = NULL;

    return tree;
}

struct BST* minValueNode(struct BST* tree) {
    struct BST* current = tree;

    while(current && current->left != NULL)
        current = current->left;

    return current;
}

struct BST* deleteFromBST(struct BST* tree, char data) {
    if(tree == NULL)
        return tree;

    if(data < tree->data)
        tree->left = deleteFromBST(tree->left, data);

    else if(data > tree->data)
        tree->right = deleteFromBST(tree->right, data);

    else {

        if(tree->left == NULL) {
            struct BST* tmp = tree->right;
            free(tree);
            return tmp;
        } else if(tree->right == NULL) {
            struct BST* tmp = tree->left;
            free(tree);
            return tmp;
        }

        struct BST* tmp = minValueNode(tree->right);

        tree->data = tmp->data;

        tree->right = deleteFromBST(tree->right, tmp->data);
    }

    return tree;
}

int depth(struct BST* tree) {
    if(tree == NULL)
        return 0;

    int lDepth = depth(tree->left);
    int rDepth = depth(tree->right);

    if(lDepth > rDepth)
        return  lDepth + 1;
    else
        return rDepth + 1;
}

void insert(struct BST **tree, char data) {
    if (*tree == NULL) {
        *tree = createBST(data);
        return;
    }

    if ((*tree)->data > data)
        insert(&((*tree)->left), data);
    else if ((*tree)->data < data)
        insert(&((*tree)->right), data);
}

void traverse(struct BST *tree) {
    if (!tree)
        return;

    traverse(tree->left);

    printf("%c ", tree->data);

    traverse(tree->right);
}

void destroy(struct BST* tree) {
    if(!tree)
        return;

    destroy(tree->left);

    free(tree);

    destroy(tree->right);
}