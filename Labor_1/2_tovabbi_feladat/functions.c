//
// Created by csill on 2/21/2021.
//

float sum(float* arr, int len) {
    float sum = 0;

    for(int i = 0; i < len; i++)
        sum += arr[i];

    return sum;
}

float product(float* arr, int len) {
    float prod = 1;

    for(int i = 0; i < len; i++)
        prod *= arr[i];

    return prod;
}

float average(float* arr, int len) {
    float sum = 0;

    for(int i = 0; i < len; i++)
        sum += arr[i];

    return sum / len;
}