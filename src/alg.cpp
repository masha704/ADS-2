// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
    if (n == 0) {
        return 1;
    }
    double res = value;
    for (uint16_t i = 0; i < n-1; i++) {
        res *= value;
    }
    return res;
}

uint64_t fact(uint16_t n) {
    if (n < 0) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    if (n < 0) {
        return 0;
    }
    return pown(x, n) / (double)fact(n);
}

double expn(double x, uint16_t count) {
    if (count <= 0) {
        return 1;
    }
    return calcItem(x, count) + expn(x, count - 1);
}

double sinn(double x, uint16_t count) {
    if (count == 1) {
        return x;
    }
    return pown(-1, count - 1) * calcItem(x, count * 2 - 1) + sinn(x, count - 1);
}

double cosn(double x, uint16_t count) {
    if (count == 1) {
        return x;
    }
    return pown(-1, count - 1) * calcItem(x, 2 * count - 2) + cosn(x, count - 1);
}
