#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int main() {
    int m;
    int n;

    printf("m: ");
    scanf("%i", &m);

    printf("n: ");
    scanf("%i", &n);

    int* T = (int*)malloc(m * sizeof(int));

    for(int i = 0; i < m; i++)
        T[i] = -1;

    for(int i = 0; i < n; i++) {
        int tmp;
        printf("arr[%i]: ", i);
        scanf("%i", &tmp);

        insert(tmp, T, m);
    }

    int element;

    printf("element: ");
    scanf("%i", &element);

    int index = search(element, T, m);

    printf("index: %i\n", index);

    print(T, m);

    delete(element, T, m);

    print(T, m);
}
