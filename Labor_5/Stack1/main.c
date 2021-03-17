#include <stdio.h>
#include "functions.h"

int main() {

    Stack *stack = create(20);

    for(int i = 1; i <= 10; i++) {
        if(!isFull(stack)) {
            push(stack, i);
        }
    }

    while(!isEmpty(stack)) {
        printf("%i ", pop(stack));
    }

    return 0;
}
