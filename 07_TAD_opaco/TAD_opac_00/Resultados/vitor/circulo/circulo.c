#include <stdlib.h>
#include <assert.h>
#include "circulo.h"

struct circulo {
    tPonto centro;
    float raio;
};

tCirculo Circulo_Cria(float x, float y, float r) {
    tCirculo c = (tCirculo)malloc(sizeof(struct circulo));
    assert(c != NULL);

    c->raio = r;
    Circulo_Atribui_Centro(c, Pto_Cria(x, y));

    return c;
}

void Circulo_Apaga(tCirculo c) {
    if (c != NULL) {
        Pto_Apaga(c->centro);
        free(c);
    }
}

tPonto Circulo_Acessa_Centro(tCirculo c) {
    assert(c != NULL);
    assert(c->centro != NULL);

    return c->centro;
}

float Circulo_Acessa_Raio(tCirculo c) {
    assert(c != NULL);

    return c->raio;
}

void Circulo_Atribui_Centro(tCirculo c, tPonto p) {
    assert(c != NULL);
    assert(p != NULL);

    c->centro = p;
}

void Circulo_Atribui_Raio(tCirculo c, float r) {
    //ATENÇÃO: é de responsabilidade do usuário liberar o centro do circulo antes de chamar essa função.
    //não sei como fazer para checar se o centro está alocado.
    assert(c != NULL);

    c->raio = r;
}

int Circulo_Interior(tCirculo c, tPonto p) {
    assert(c != NULL);
    assert(p != NULL);

    return(Pto_Distancia(c->centro, p) <= Circulo_Acessa_Raio(c));
}