//
// Created by csill on 3/6/2021.
//

#include <stdio.h>
#include <math.h>
#include "functions.h"

void quad(double a, double b, double c) {
    double delta = b * b - 4 * a * c;

    if(delta < 0)
        return;

    double x1, x2;

    if(delta == 0) {
        x1 = -b / (2 * a);
        x2 = x1;
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
    }

    printf("x1: %lf\nx2: %lf", x1, x2);
}