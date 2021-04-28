#include <stdlib.h>
#include <stdio.h>
#include "BinarySearchTree.h"

root *create(int a) {

    root *ag = (root *) (malloc(sizeof(root)));

    if (!ag) {
        printf("Sikertelen lefoglalas");
        return 0;
    }

    ag->adat = a;
    ag->jobb = NULL;
    ag->bal = NULL;

    return ag;
}

void insert(root **fa, int a) {
    if ((*fa) == NULL) {
        (*fa) = create(a);
    } else {
        if ((*fa)->adat > a)
            insert(&((*fa)->bal), a);
        else
            insert(&((*fa)->jobb), a);
    }
}

void inorder(root *fa) {
    if (fa->bal)
        inorder(fa->bal);

    printf("%3d ", fa->adat);

    if (fa->jobb)
        inorder(fa->jobb);
}

void preorder(root *fa) {
    printf("%3d ", fa->adat);
    if (fa->bal)
        preorder(fa->bal);
    if (fa->jobb)
        preorder(fa->jobb);
}

void postorder(root *fa) {
    if (fa->bal)
        postorder(fa->bal);
    if (fa->jobb)
        postorder(fa->jobb);
    printf("%3d ", fa->adat);
}