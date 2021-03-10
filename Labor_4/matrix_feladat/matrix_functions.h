//
// Created by csill on 3/10/2021.
//

#ifndef MATRIX_FELADAT_MATRIX_FUNCTIONS_H
#define MATRIX_FELADAT_MATRIX_FUNCTIONS_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int cols);

void readMatrix(const char* fileName, Matrix **array);
void printMatrix(Matrix* array);

#endif //MATRIX_FELADAT_MATRIX_FUNCTIONS_H
