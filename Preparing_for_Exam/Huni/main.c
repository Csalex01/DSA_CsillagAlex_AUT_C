#include <stdio.h>
#include <string.h>

#include "1_Feladat/Stack.h"
#include "2_Feladat/BinarySearchTree.h"

int main() {

    /// 1. Feladat
    printf("\n----------\n1. Feladat\n----------\n\n");

    char szo[100];
    printf("Szo: ");
    scanf("%s", szo);
    printf("\n");

    Stack* stack = createStack(strlen(szo));

    printf("A verem: %s\n", (isEmptyStack(stack)) ? "ures" : "nem ures");

    for(int i = 0; i < stack->maxSize; i++) pushStack(stack, szo[i]);

    printf("A verem: %s\n", (isEmptyStack(stack)) ? "ures" : "nem ures");
    printf("A verem tetejen levo karakter: %c\n", topStack(stack));

    int x;
    printf("\nx: ");
    scanf("%i", &x);
    printf("\n");

    for(int i = 0; i < x; i++) {
        if(popStack(stack) == '\0') {
            printf("Nem lehet tobb elemet kivenni a verembol!");
            break;
        }
    }

    while(!isEmptyStack(stack))
        printf("%c\n", popStack(stack));

    destroyStack(stack);

    /// 2. Feladat
    printf("\n----------\n2. Feladat\n----------\n\n");

    char szo2[100];
    printf("Szo: ");
    scanf("%s", szo2);
    printf("\n");

    BST* tree = NULL;

    for(int i = 0; i < strlen(szo2); i++)
        insertBST(&tree, szo2[i]);

    printf("A fa: ");
    traverseBST(tree);
    printf("\n");

    printf("A fa melysege: %i\n", depthBST(tree));

    char c;

    printf("Add meg a karaktert amit ki szeretnel torulni: ");
    scanf(" %c", &c);

    deleteBST(tree, c);

    printf("A fa: ");
    traverseBST(tree);
    printf("\n");

    destroyBST(tree);

    return 0;
}
