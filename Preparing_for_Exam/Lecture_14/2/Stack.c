//
// Created by csill on 5/29/2021.
//

#include "Stack.h"

struct Stack *createStack() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));

    if (!stack) {
        printf("Error while allocating memory for Stack!");
        return NULL;
    }

    stack->next = NULL;

    return stack;
}

struct Stack *readStackFromFile(char *fileName) {
    FILE *fin = fopen(fileName, "rt");

    if (!fin) {
        printf("Error while opening file %s!", fileName);
        return NULL;
    }

    int year, month, day;
    int counter = 0;

    struct Stack *stack = NULL;

    while (true) {
        if (fscanf(fin, "%i", &year) == EOF ||
            fscanf(fin, "%i", &month) == EOF ||
            fscanf(fin, "%i", &day) == EOF)
            break;

        if(year < 1900 || year > 2000)
            counter++;

        if(counter >= 5)
            break;

        push(&stack, year, month, day);
    }

    fclose(fin);

    return stack;
}

struct Stack* pop(struct Stack** stack) {
    if(isEmpty(*stack))
        return NULL;

    struct Stack* aux = *stack;
    *stack = (*stack)->next;

    return aux;
}

bool isEmpty(struct Stack* stack) {
    return stack == NULL;
}

void push(Stack **topPtr, int year, int month, int day) {
    Stack *newNode = createStack();

    if (!newNode) {
        printf("Error while allocating new node!");
        return;
    }

    newNode->year = year;
    newNode->month = month;
    newNode->day = day;

    newNode->next = *topPtr;
    *topPtr = newNode;
}


void traverseStack(struct Stack *stack) {
    if (!stack)
        return;

    printf("%i %i %i\n", stack->year, stack->month, stack->day);

    traverseStack(stack->next);
}