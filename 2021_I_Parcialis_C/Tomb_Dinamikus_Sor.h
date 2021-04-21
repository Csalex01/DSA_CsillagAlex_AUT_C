//
// Created by csill on 4/21/2021.
//

#ifndef INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUS_SOR_H
#define INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUS_SOR_H

/// Tomb

typedef struct {
    int c;
    int *num;
} F;

F *createF();

F *readArrayFromFileF(char *fileName);

void printF(F *array);

/// Sor

typedef struct N_Type {
    int e;
    struct N_Type *k;
} N_Type;

N_Type *createQueue();

void readFromFileQueue(char *fileName, N_Type *front, N_Type *last);

bool isEmptyQueue(N_Type *front);

void insertQueue(N_Type **front, N_Type **last, int data);

void traverse(N_Type *front);

/// Feladatok

float elso19gyokTomb(F *array);

float elso19gyokQueue(N_Type *front);

float atlagokNegyzeteTomb(F *array);

float atlagokNegyzeteQueue(N_Type *front);

bool mindenSzamNagyobb10Tomb(F* array);
bool mindenSzamNagyobb10Queue(N_Type *front);


#endif //INC_2021_I_PARCIALIS_C_TOMB_DINAMIKUS_SOR_H
