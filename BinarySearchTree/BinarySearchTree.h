#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

typedef struct root {
    int adat;
    struct root *bal;
    struct root *jobb;
} root;

root *create(int a);

void insert(root **fa, int a);

void inorder(root *fa);

void preorder(root *fa);

void postorder(root *fa);

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H