#include <stdio.h>

#include "queue.h"

int main() {
    Node* front;
    Node* last;

    front = last = NULL;

    insert(&front, &last, 10);
    insert(&front, &last, 20);
    insert(&front, &last, 30);

//    printf("%i", front->data);
    traverse(front);

    printf("%i", getIndex(front, 1, 0));
}
