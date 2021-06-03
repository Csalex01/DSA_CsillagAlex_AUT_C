#include <stdio.h>
#include <string.h>

#include "1_Feladat/Stack.h"
#include "2_Feladat/BinarySearchTree.h"

int main() {
    /// 1. FELADAT
    printf("1. Feladat (Stack)\n\n");

    char word[101] = "agyfasz";

    printf("Szo: %s", word);
//    scanf("%s", word);

    Stack *stack = createStack(strlen(word));

    printf("\nA verem: %s.", (isEmpty(stack) ? "ures" : "nem ures"));

    for (int i = 0; i < strlen(word); i++)
        push(stack, word[i]);

    printf("\nA verem tartalma: ");
    for(int i = stack->sp; i >= 0; i--)
        printf("%c, ", stack->data[i]);
    printf("\b\b ");

    printf("\nA verem: %s.", (isEmpty(stack) ? "ures" : "nem ures"));

    printf("\nA verem legfelso eleme: %c", top(stack));

    int x = 4;

//    printf("\n\nX: ");
//    scanf("%i", &x);

    for(int i = 0; i < x; i++)
        pop(stack);

    printf("\nA verem tartalma: ");
    for(int i = stack->sp; i >= 0; i--)
        printf("%c, ", stack->data[i]);
    printf("\b\b ");


    destroyStack(stack);

    /// 2. FELADAT
    printf("\n\n2. Feladat (Binary Search Tree)\n\n");

    printf("Szo: ");
    scanf("%s", word);

    BST* tree = NULL;

    for (int i = 0; i < strlen(word); i++)
        insert(&tree, word[i]);

    printf("\nA binaris fa: ");
    traverse(tree);

    printf("\n\nA fa melysege (magassaga): %i", depth(tree));

    char c = 'a';

    printf("\nC: %c", c);
//    scanf("%c", &c);

    deleteFromBST(tree, c);

    printf("\nA binaris fa: ");
    traverse(tree);

    return 0;
}
