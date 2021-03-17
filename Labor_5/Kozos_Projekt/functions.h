//
// Created by csill on 3/17/2021.
//

#ifndef KOZOS_PROJEKT_FUNCTIONS_H
#define KOZOS_PROJEKT_FUNCTIONS_H

typedef struct {
    int rows;
    int cols;
    int** data;
} Matrix;

Matrix* createMatrix(int rows, int cols);

void readMatrix(const char* fileName, Matrix** array);

// Sárkány Illés-Sámuel
void find_element(Matrix* array, int element);

// Ráduly Botond
void modulus_element(Matrix* array);

// Pál Szilárd
int number_sum(Matrix* array);

// Nagy Krisztián
double scattering_matrix(Matrix* array);

#endif //KOZOS_PROJEKT_FUNCTIONS_H
