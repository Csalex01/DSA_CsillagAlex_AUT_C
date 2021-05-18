//
// Created by csill on 5/12/2021.
//

#include "Exchange.h"

Exchange* createExchange(int year, int month, int forint, int penny) {
    Exchange* exchange = (Exchange*)malloc(sizeof(Exchange));

    if(!exchange) {
        printf("Failed to allocate memory for Exchange.");
        return NULL;
    }

    exchange->year = year;
    exchange->month = month;

    exchange->forint = forint;
    exchange->penny = penny;

    return exchange;
}

bool compare(Exchange* ex1, Exchange* ex2) {
    if(ex1->forint > ex2->forint)
        return true;
    else if(ex1->forint <= ex2->forint)
        return false;

    if(ex1->penny > ex2->penny)
        return true;
    else if(ex1->penny <= ex2->penny)
        return false;

    return false;
}