#include <stdio.h>
#include <assert.h>
#include "operacoesprimitivos.h"

#define cast(a, b) *((a*)b)

void ImprimeInt(void* n) {
    assert(n != NULL);
    printf("%d", cast(int, n));
}

void ImprimeFloat(void* n) {
    assert(n != NULL);
    printf("%.2f", cast(float, n));
}

void ImprimeDouble(void* n) {
    assert(n != NULL);
    printf("%.2lf", cast(double, n));
}

void ImprimeChar(void* c) {
    assert(c != NULL);
    printf("%c", cast(char, c));
}