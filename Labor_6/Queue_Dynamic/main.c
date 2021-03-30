#include <stdio.h>

#include "queue.h"

int main() {
    Node* front;
    Node* last;

    front = last = NULL;

    for(int i = 0; i < 10; i++)
        insert(&front, &last, i);


//    printf("%i", front->data);
    traverseIterative(front);
    printf("\n");

    printf("%i", getIndex(front, 5, 0));
}
