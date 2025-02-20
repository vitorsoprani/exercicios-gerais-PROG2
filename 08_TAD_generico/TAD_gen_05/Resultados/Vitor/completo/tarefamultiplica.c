#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tarefamultiplica.h"

#define cast(x) ((tMult*)x)

struct mult {
    float n1;
    float n2;
};


tMult* CriaTarefaMultiplicar(float n1, float n2) {
    tMult* mult = (tMult*)malloc(sizeof(tMult));
    assert(mult != NULL);

    mult->n1 = n1;
    mult->n2 = n2;

    return mult;
}

void ExecutaTarefaMultiplicar(void* mult) {
    assert(mult != NULL);

    printf("\nO resultado da multiplicacao de %.2f com %.2f eh: %.2f",
        cast(mult)->n1, cast(mult)->n2, cast(mult)->n1 * cast(mult)->n2);
}

void DestroiTarefaMultiplicar(void* mult) {
    if (mult != NULL)
        free(mult);
}