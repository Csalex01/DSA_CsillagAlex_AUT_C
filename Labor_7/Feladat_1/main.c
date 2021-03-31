#include <stdio.h>

#include "linked_list.h"

int main() {

    int N = 1223334444;
    int k = 2;

    Node *front = NULL;

    while(N > 0) {
        insert(&front, N % 10, 0);
        N /= 10;
    }

    printf("A lista: ");
    traverse(front);

    printf("A lista %i.-ik eleme: %i\n", k, getKthDigit(front, k, 0));
    printf("A lista hossza: %i\n", listLength(front, 0));
    printf("Novekvo sorrendben vannak-e a szamjegyek? %i\n", isAscending(front));

    int* stats = statistics(front);

    printf("Elofordulasi statisztika: \n");
    for(int i = 0; i < 10; i++)
        printf("%i - %i\n", i, stats[i]);

    return 0;
}
