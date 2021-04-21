#include <stdio.h>

#include "Tomb_DinamikusVerem.h"
#include "Tomb_Dinamikus_Sor.h"

int main() {

    /// 1. Feladat

    printf("1.\n");

    P* tomb = readArrayFromFile("input_1.txt");
    NType* stack = readStackFromFile("input_1.txt");

    printf("Atlagok fele (stack): %.2f\n", atlagokFeleStack(stack));
    printf("Atlagok fele (tomb): %.2f\n", atlagokFeleTomb(tomb));

    printf("Minden szam pozitiv? (stack) %i\n", mindenSzamPozitivStack(stack));
    printf("Minden szam pozitiv? (tomb) %i\n", mindenSzamPozitivTomb(tomb));

    printf("Paratlan szamok (stack): %i\n", paratlanSzamStack(stack));
    printf("Paratlan szamok (tomb): %i\n", paratlanSzamTomb(tomb));

    /// 2. Feladat

    printf("\n2.\n");

    F* tombF = readArrayFromFileF("input_1.txt");

    N_Type* front;
    N_Type* last;

    front = last = NULL;

    // readFromFileQueue("input_1.txt", (N_Type *) &front, (N_Type *) &last);

    printF(tombF);
    printf("\n");
    traverse(front);

    printf("Elso 19-cel oszthato szam gyoke (tomb): %.2f\n", elso19gyokTomb(tombF));
    printf("A sorozatban az atlag negyzete (tomb): %.2f\n", atlagokNegyzeteTomb(tombF));
    printf("A sorozatban minden elem nagyobb-e mint 10? %i\n", mindenSzamNagyobb10Tomb(tombF));

    return 0;
}
