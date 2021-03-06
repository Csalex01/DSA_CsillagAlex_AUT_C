#include <stdio.h>

#include "functions.h"

int main() {

    unsigned int secs;

    printf("Seconds: ");
    scanf("%u", &secs);

    printInHMS(secs);

    return 0;
}
