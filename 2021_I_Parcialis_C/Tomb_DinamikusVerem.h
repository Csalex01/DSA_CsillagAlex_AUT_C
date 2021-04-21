//
// Created by csill on 4/21/2021.
//

#ifndef INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUSVEREM_H
#define INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUSVEREM_H

#include <stdbool.h>

/// Tömb

typedef struct {
    int nr;
    int *numbers;
} P;

P* createP();
P* readArrayFromFile(char* fileName);

void printP(P* array);

/// Verem

typedef struct NType {
    int n;
    struct NType *k;
} NType;

NType* createStack();
NType* readStackFromFile(char* fileName);

bool isEmpty(NType* topPtr);

int pop(NType** stack);

void push(NType** stack, int n);
void printStack(NType* stack);

/// Feladatok
float atlagokFeleStack(NType* stack);
float atlagokFeleTomb(P* array);

bool mindenSzamPozitivStack(NType* stack);
bool mindenSzamPozitivTomb(P* array);

int paratlanSzamStack(NType* stack);
int paratlanSzamTomb(P* array);

#endif //INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUSVEREM_H
