#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main() {

    IntArray *array = createArray(10);

    if (!array) {
        printf("Could not allocate array!");
        return -1;
    }

    int numberToFind = 3;

//    readArray("input.txt", &array);
    fillArray(array, array->size, 0, 50);
    printArray(array);
//    printArrayToFile("output.txt", array);

    int index = findElement(array, numberToFind);

    if (index >= 0)
        printf("Found %i @ %i.\n", numberToFind, index);
    else
        printf("Could not find %i.\n", numberToFind);

    sortArray(array);
    printArray(array);

    deleteElement(array, index);
    printArray(array);

    printf("Minimum: %i\n", minimum(array));
    printf("Maximum: %i\n", maximum(array));

    IntArray *copyArray = (IntArray *) malloc(sizeof(IntArray));
    if (!copyArray) {
        printf("Failed to allocate buffer of original array!");
    } else {
        copyArray->size = 5;
        copy(copyArray, array);
        printArray(copyArray);
    }
    return 0;
}
