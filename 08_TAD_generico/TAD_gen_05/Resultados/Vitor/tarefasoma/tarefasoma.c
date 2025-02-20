#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tarefasoma.h"

// Faz o casting para tSoma*
#define cast(x) ((tSoma*)x)

struct soma {
    float n1;
    float n2;
};

tSoma* CriaTarefaSoma(float n1, float n2) {
    tSoma* sum = (tSoma*)malloc(sizeof(tSoma));
    assert(sum != NULL);

    sum->n1 = n1;
    sum->n2 = n2;

    return sum;
}

void ExecutaTarefaSoma(void* sum) {
    assert(sum != NULL);
    printf("\nO resultado da soma de %.2f com %.2f eh: %.2f",
        cast(sum)->n1, cast(sum)->n2, cast(sum)->n1 + cast(sum)->n2);

}

void DestroiTarefaSoma(void* sum) {
    if (sum != NULL)
        free(sum);
}