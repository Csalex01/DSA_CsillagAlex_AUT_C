//
// Created by csill on 3/6/2021.
//

#include <stdio.h>

#include "functions.h"

void printInHMS(unsigned int seconds) {
    unsigned int h = seconds / 3600;
    unsigned int m = (seconds - (3600 * h)) / 60;
    unsigned int s = (seconds - (3600 * h)) - (m * 60);

    printf("%u:%u:%u", h, m, s);
}