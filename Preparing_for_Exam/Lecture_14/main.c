#include <stdio.h>
#include <time.h>


#include "1/BinarySearchTree.h"

#include "2/Stack.h"
#include "2/LinkedList.h"

int main() {
    /// 1. Feladat
    printf("1. feladat\n\n");
    srand(time(NULL));

    BinarySearchTree* tree = NULL;

//    for(int i = 0; i < 10; i++) {
//        int n = rand() % 20 + 1;
//        insert(&tree, n);
//        printf("%i ", n);
//    }
//    printf("\n");

    insert(&tree, 10);
    insert(&tree, 5);
    insert(&tree, 15);
    insert(&tree, 7);
    insert(&tree, 12);
    insert(&tree, 9);
    insert(&tree, 11);
    insert(&tree, 4);
    insert(&tree, 16);

    traverse(tree);

    printf("\n");

    printBetweenTwoLevels(tree, 2, 4, 0);

    printf("\n\n");

    /// 2. feladat
    printf("2. feladat\n\n");

    struct Stack* stack = readStackFromFile("input_2.txt");

    printf("Stack: \n");
    traverseStack(stack);

    LinkedList* front = NULL;

    for(int i = 0; i < 10; i++)
        insertIntoLinkedList(&front, 0, i);

    while(!isEmpty(stack)) {
        int year = pop(&stack)->year;
        int index = (year % 100) / 10;

        increaseIndex(front, index);
    }

    printf("\nLinkedList: \n");
    traverseLinkedList(front);

    return 0;
}
