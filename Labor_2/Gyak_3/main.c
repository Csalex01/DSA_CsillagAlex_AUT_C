#include <stdio.h>
#include "functions.h"

int main() {
    double a, b, c;

    printf("a: ");
    scanf("%lf", &a);
    printf("b: ");
    scanf("%lf", &b);
    printf("c: ");
    scanf("%lf", &c);

    quad(a, b, c);
}
