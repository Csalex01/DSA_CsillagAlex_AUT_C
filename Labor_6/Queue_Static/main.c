#include <stdio.h>

#include "queue.h"
#include "menu.h"

int main() {
    int capacity;

    printf("Size of queue: ");
    scanf("%i", &capacity);

    QUEUE *queue = create(capacity);

    if(!queue) {
        printf("Failed to allocate memory for QUEUE (main)");
        return -1;
    }

    int choice;

    do {
        printf("----- Menu -----\n");
        printf("1. Insert new item to queue\n");
        printf("2. Remove item from queue\n");
        printf("3. First item in the queue\n");
        printf("4. Exit\n");
        printf("---------------\n");


        do {
            printf("Choice: ");
            scanf("%i", &choice);
        } while(choice < 1 || choice > 4);

        switch (choice) {
            case 1:
                insertNewItemToQueue(queue);
                break;
            case 2:
                removeFromQueue(queue);
                break;
            case 3:
                firstItemInQueue(queue);
                break;
            case 4:
                return 0;
        }

    } while(true);
}
