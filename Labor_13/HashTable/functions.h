//
// Created by csill on 5/19/2021.
//

#ifndef HASHTABLE_FUNCTIONS_H
#define HASHTABLE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>

int search(int k, const int* T, int m);

void insert(int k, int* T, int m);

void delete(int k, int* T, int m);

void print(int* T, int m);

#endif //HASHTABLE_FUNCTIONS_H