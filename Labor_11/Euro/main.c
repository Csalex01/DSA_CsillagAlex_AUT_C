#include <stdio.h>

#include "Heap.h"

int main() {
    Exchange* exchange1 = createExchange(1999, 1, 249, 33);
    Exchange* exchange2 = createExchange(2000, 2, 250, 34);

    Heap* heap = createHeap(10);
    insert(heap, exchange1);
    insert(heap, exchange2);

//    for(int i = 0; i < heap->size; i++)
//        printf("%i", heap->data[i].forint);


    return 0;
}
