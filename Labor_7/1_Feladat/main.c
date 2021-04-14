#include <stdio.h>

//#include "queue.h"
#include "stack.h"

/**

 1.	Adott egy szöveges allomany, amelynek az első sorában betűk vannak szóközökkel elválasztva.
    Készítsünk egy-egy egyszeresen láncolt listat, kulon a nagybetukkel es kulon a kisbetukkel.
    Irassuk ki a listakat. Melyik lista tartalmaz tobb elemet?

 2. Az állományban levő számokat helyezzétek be egy dinamikus verembe.
    Írjátok ki a számok átlagát

 3. Írj egy programot, amely létrehoz egy ventilátor típust (gyártó, termékszám) és
    állományból beolvassa n ventilátor adatait.
    Van-e két azonos gyártótól ventilátor? (használj statikus tömböt).

 */

int main() {

    /**
        1.

        Node* uppercase = NULL;
        Node* lowercase = NULL;

        readFromFile(&uppercase, &lowercase, "input_queue.txt");

        traverse(uppercase);
        printf("\n");
        traverse(lowercase);
     */

    /**
     * 2.
     */

    Node* topPtr = readFromFile("input_stack.txt");

    int sum = 0;
    int counter = 0;

    while(!isEmpty(topPtr)) {
        sum += pop(&topPtr);
        counter++;
    }

    printf("Average: %c", (char)(sum / counter));

    return 0;
}
