#include <stdio.h>

#include "BinarySearchTree.h"

int main() {

    root *tree = create(20);

    insert(&tree, 10);
    insert(&tree, 30);
    insert(&tree, 15);
    insert(&tree, 25);

    preorder(tree);
    printf("\n");

    inorder(tree);
    printf("\n");

    postorder(tree);

    return 0;
}
