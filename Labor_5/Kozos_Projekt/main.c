#include <stdio.h>
#include "functions.h"

int main() {
    Matrix* matrix;

    readMatrix("input.txt", &matrix);

    find_element(matrix, 100);
    modulus_element(matrix);

    int sum = number_sum(matrix);

    double scattering = scattering_matrix(matrix);

    printf("Sum: %i\n", sum);
    printf("Scattering: %lf", scattering);

    return 0;
}
