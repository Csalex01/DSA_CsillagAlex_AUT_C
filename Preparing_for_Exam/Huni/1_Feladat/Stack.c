#include "Stack.h"

struct Stack *createStack(int capacity) {
    struct Stack* newStack = (struct Stack*)malloc(sizeof(struct Stack));

    if(!newStack) {
        printf("Hiba a memoriaallokacioban (#1)!");
        return NULL;
    }

    newStack->sp = -1;
    newStack->maxSize = capacity;
    newStack->data = (char*)calloc(newStack->maxSize, sizeof(char));

    if(!newStack->data) {
        printf("Hiba a memoriaallokacioban (#2)!");

        free(newStack);
        newStack = NULL;

        return NULL;
    }

    return newStack;
}

bool isEmptyStack(struct Stack *stack) {
    return stack->sp == -1;
}

bool isFullStack(struct Stack *stack) {
    return stack->sp == stack->maxSize - 1;
}

char popStack(struct Stack *stack) {
    if(isEmptyStack(stack))
        return '\0';

    char tmp = topStack(stack);

    stack->data[stack->sp] = '\0';

    stack->sp--;

    return tmp;
}

char topStack(struct Stack *stack) {
    if(isEmptyStack(stack))
        return '\0';

    return stack->data[stack->sp];
}

void pushStack(struct Stack *stack, char c) {
    if(isFullStack(stack))
        return;

    stack->sp++;
    stack->data[stack->sp] = c;
}

void destroyStack(struct Stack *stack) {
    free(stack->data);
    stack->data = NULL;

    free(stack);
    stack = NULL;
}