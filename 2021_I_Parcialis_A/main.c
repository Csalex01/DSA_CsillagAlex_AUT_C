#include <stdio.h>
#include <string.h>

#include "linked_list.h"
#include "stack.h"

int main() {
    /**
     * 1. FELADAT
     *
     * Tároljátok egy egyszeresen láncolt listában egy legtöbb 10 jegyű szám számjegyeit
     * előfordulásuk sorrendjében. Írassátok ki a páros illetve páratlan számjegyeket
     * egy-egy állományba.
     *
     * Írjátok meg a következő függvényeket: create, insert, print, destroy.
     * */
    int n;

    printf("n: ");
    scanf("%i", &n);

    NodeLinkedList *front = NULL;

    while (n > 0) {
        insertNodeLinkedList(&front, n % 10, 0);
        n /= 10;
    }

    FILE *output_even = fopen("output_even.txt", "wt");
    FILE *output_odd = fopen("output_odd.txt", "wt");

    if (!output_even || !output_odd) {
        printf("Error while opening files!");
        return -1;
    }

    printLinkedList(front, output_even, output_odd);

    fclose(output_even);
    fclose(output_odd);

    destroyLinkedList(front);
    /** -------------------- */

    /**
     * 2. FELADAT
     *
     * Tároljátok egy félstatikus veremben egy legtöbb 10 betűből álló szó karaktereit
     * előfordulásuk sorrendjében. Írassátok ki a magánhangzókat egy állományba.
     *
     * Írjátok meg a következő függvényeket: create, insert, print, destroy.
     */

    char input[11];

    printf("input: ");
    scanf("%s", input);

    NodeStack *stack = createNodeStack(10);

    for(int i = i = 0; i < strlen(input); i++)
        insertNodeStack(stack, input[i]);

    FILE *output_vowels = fopen("output_vowels.txt", "wt");

    if(!output_vowels) {
        printf("Error while opening files!");
        return -2;
    }

    printStack(stack, output_vowels);

    fclose(output_vowels);

    /** -------------------- */

    return 0;
}
