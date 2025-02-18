#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tadgen.h"

struct generic {
    int numElementos;
    Type type;
    void* elementos;
};

tGeneric* CriaGenerico(Type type, int numElem) {
    tGeneric* gen = (tGeneric*)malloc(sizeof(tGeneric));
    assert(gen != NULL);

    gen->type = type;
    gen->numElementos = numElem;

    if (gen->type == FLOAT) {
        gen->elementos = (float*)malloc(sizeof(float) * gen->numElementos);
    } else if (gen->type == INT) {
        gen->elementos = (float*)malloc(sizeof(int) * gen->numElementos);
    } else {
        printf("Erro na definição do tipo de dado.\n");
        exit(1);
    }

    assert(gen->elementos != NULL);

    return gen;
}

void DestroiGenerico(tGeneric* gen) {
    if (gen != NULL) {
        if (gen->elementos != NULL)
            free(gen->elementos);
        free(gen);
    }
}

void LeGenerico(tGeneric* gen) {
    assert(gen != NULL);

    printf("\nDigite o vetor:\n");

    if (gen->type == INT) {
        for (int i = 0; i < gen->numElementos; i++) {
            scanf("%d ", &((int*)gen->elementos)[i]);
        }
    } else if (gen->type == FLOAT) {
        for (int i = 0; i < gen->numElementos; i++) {
            scanf("%f ", &((float*)gen->elementos)[i]);
        }
    } else {
        printf("Erro na definição do tipo de dado.\n");
        exit(1);
    }
}

void ImprimeGenerico(tGeneric* gen) {
    assert(gen != NULL);

    if (gen->type == INT) {
        for (int i = 0; i < gen->numElementos - 1; i++) {
            printf("%d ", ((int*)gen->elementos)[i]);
        }
        printf("%d", ((int*)gen->elementos)[gen->numElementos - 1]);
    } else if (gen->type == FLOAT) {
        for (int i = 0; i < gen->numElementos - 1; i++) {
            printf("%.2f ", ((float*)gen->elementos)[i]);
        }
        printf("%.2f", ((float*)gen->elementos)[gen->numElementos - 1]);
    } else {
        printf("Erro na definição do tipo de dado.\n");
        exit(1);
    }
}