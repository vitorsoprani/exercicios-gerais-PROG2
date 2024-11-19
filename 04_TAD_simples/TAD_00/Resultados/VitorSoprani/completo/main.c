#include <stdio.h>
#include "ponto.h"

int main() {
    Ponto p1, p2;
    float xP1, yP1, xP2, yP2;

    scanf("%f %f %f %f", &xP1, &yP1, &xP2, &yP2);
    
    p1 = pto_cria(xP1, yP1);
    p2 = pto_cria(xP2, yP2);

    printf("%g", pto_distancia(p1, p2));
    return 0;
}