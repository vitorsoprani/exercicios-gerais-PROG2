#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "ponto.h"

struct ponto {
    float x;
    float y;
};

tPonto Pto_Cria(float x, float y) {
    tPonto p = (tPonto)malloc(sizeof(struct ponto));
    assert(p != NULL);

    Pto_Atribui_x(p, x);
    Pto_Atribui_y(p, y);

    return p;
}

void Pto_Apaga(tPonto p) {
    if (p != NULL)
        free(p);
}

float Pto_Acessa_x(tPonto p) {
    assert(p != NULL);

    return p->x;
}

float Pto_Acessa_y(tPonto p) {
    assert(p != NULL);

    return p->y;
}

void Pto_Atribui_x(tPonto p, float x) {
    assert(p != NULL);

    p->x = x;
}

void Pto_Atribui_y(tPonto p, float y) {
    assert(p != NULL);

    p->y = y;
}

float Pto_Distancia(tPonto p1, tPonto p2) {
    assert(p1 != NULL);
    assert(p2 != NULL);

    float deltaX, deltaY, distancia;

    deltaX = Pto_Acessa_x(p1) - Pto_Acessa_x(p2);
    deltaY = Pto_Acessa_y(p1) - Pto_Acessa_y(p2);

    distancia = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    return distancia;
}