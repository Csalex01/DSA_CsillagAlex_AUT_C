#include "BinarySearchTree.h"

struct BST *createBST(char c) {
    struct BST *newTree = (struct BST *) malloc(sizeof(struct BST));

    if (!newTree) {
        printf("Hiba a memoriaallokacioban (#3)!");
        return NULL;
    }

    newTree->data = c;
    newTree->left = NULL;
    newTree->right = NULL;

    return newTree;
}

struct BST *deleteBST(struct BST *tree, char data) {
    if (tree == NULL)
        return tree;

    if (data < tree->data)
        tree->left = deleteBST(tree->left, data);

    else if (data > tree->data)
        tree->right = deleteBST(tree->right, data);

    else {
        if (tree->left == NULL) {
            struct BST *tmp = tree->right;
            free(tree);
            return tmp;
        } else if (tree->right == NULL) {
            struct BST *tmp = tree->left;
            free(tree);
            return tmp;
        }

        struct BST* tmp = minValueBST(tree->right);

        tree->data = tmp->data;

        tree->right = deleteBST(tree->right, tmp->data);
    }

    return tree;
}

struct BST *minValueBST(struct BST *tree) {
    struct BST* curr = tree;

    while(curr && curr->left != NULL)
        curr = curr->left;

    return curr;
}

int depthBST(struct BST *tree) {
    if (!tree)
        return 0;

    int depthLeft = depthBST(tree->left);
    int depthRight = depthBST(tree->right);

    if (depthLeft > depthRight)
        return depthLeft + 1;
    else
        return depthRight + 1;
}

void insertBST(struct BST **tree, char c) {
    if (*tree == NULL)
        *tree = createBST(c);

    else {
        if (c < (*tree)->data)
            insertBST(&((*tree)->left), c);

        else if (c > (*tree)->data)
            insertBST(&((*tree)->right), c);
    }
}

void traverseBST(struct BST *tree) {
    if (tree->left)
        traverseBST(tree->left);

    printf("%c ", tree->data);

    if (tree->right)
        traverseBST(tree->right);
}

void destroyBST(struct BST *tree) {
    if (tree->left)
        destroyBST(tree->left);

    if (tree->right)
        destroyBST(tree->right);

    free(tree);
}