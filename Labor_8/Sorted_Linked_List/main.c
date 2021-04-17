#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorted_linked_list.h"

int main() {

    srand(time(NULL));

    Node* front = NULL;

    for(int i = 0; i < 20; i++)
        insert(&front, rand() % 20);


    traverse(front);

    return 0;
}
