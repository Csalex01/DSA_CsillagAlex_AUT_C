#include <stdio.h>
#include "matrix_functions.h"

int main() {
    Matrix* matrix;

    readMatrix("input.txt", &matrix);
    printMatrix(matrix);

    deleteRow(matrix, matrix->rows - 1);
//    deleteRow(matrix, 0);
    printMatrix(matrix);

    printf("Minimum: %i", minimum(matrix));

    return 0;
}
