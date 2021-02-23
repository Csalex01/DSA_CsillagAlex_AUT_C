#include <stdio.h>
#include "functions.h"

int main() {
    int a = 1, b = 2, c = 5;

    printf("%i\n", max(a, b, c));
    printf("%i", min(a, b, c));

    return 0;
}
