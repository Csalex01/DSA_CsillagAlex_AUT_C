#include <stdio.h>

#include "Heap.h"

int main() {
    Exchange* exchange = createExchange();
    exchange->year = 1999;
    exchange->month = 1;
    exchange->forint = 249;
    exchange->penny = 33;


    Heap* heap = createHeap(10);
    insert(heap, exchange);

    for(int i = 0; i < heap->size; i++)
        printf("%i", heap->data[i]->forint);


    return 0;
}
