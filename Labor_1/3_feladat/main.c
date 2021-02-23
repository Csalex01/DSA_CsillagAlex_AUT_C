#include <stdio.h>

int ossz(int a, int b);

int main()
{
    int a, b;

    printf("a: ");
    scanf("%i", &a);

    printf("b: ");
    scanf("%i", &b);

    printf("%i + %i = %i", a, b, ossz(a, b));
}

int ossz(int a, int b)
{
    return a + b;
}