//
// Created by csill on 3/6/2021.
//

#include <math.h>
#include "functions.h"

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}