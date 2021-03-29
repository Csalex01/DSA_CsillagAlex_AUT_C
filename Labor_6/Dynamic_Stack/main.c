#include <stdio.h>

#include "stack.h"

int main() {

    Node* topPtr = create();

    if(!topPtr) {
        printf("Error while allocating topPtr (main)!");
        return -1;
    }

    push(&topPtr, 10);
    push(&topPtr, 20);
    push(&topPtr, 30);

    printf("%i\n", pop(&topPtr));
    printf("%i\n", pop(&topPtr));
    printf("%i\n", pop(&topPtr));

    return 0;
}
