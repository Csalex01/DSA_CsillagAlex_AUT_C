#include <stdio.h>
#include "matrix_functions.h"

int main() {
    Matrix* matrix;

    readMatrix("input.txt", &matrix);
    printMatrix(matrix);

    return 0;
}
