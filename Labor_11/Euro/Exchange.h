//
// Created by csill on 5/12/2021.
//

#ifndef EURO_EXCHANGE_H
#define EURO_EXCHANGE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int year;
    int month;

    int forint;
    int penny;
} Exchange;

Exchange* createExchange(int year, int month, int forint, int penny);

bool compare(Exchange* ex1, Exchange* ex2);

#endif //EURO_EXCHANGE_H
