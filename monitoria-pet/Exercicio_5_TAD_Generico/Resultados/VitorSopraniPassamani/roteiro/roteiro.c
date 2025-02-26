#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "roteiro.h"

struct Roteiro {
    Midia** midias;
    int qtdMidias;
};

Roteiro *roteiro_construct() {
    Roteiro* r = (Roteiro*)malloc(sizeof(Roteiro));
    assert(r != NULL);

    r->midias = (Midia**)malloc(0);
    r->qtdMidias = 0;

    return r;
}

void roteiro_inserir_midia(Roteiro* r, void *dado, PrintFunction print_fn, FreeFunction free_fn) {
    assert(r != NULL);
    assert(dado != NULL);
    assert(print_fn != NULL);
    assert(free_fn != NULL);

    //  Ajustando o "vetor" de midias:
    r->qtdMidias++;
    r->midias = (Midia**)realloc(r->midias, r->qtdMidias * sizeof(Midia*));

    //  Gerando e armazenando a midia na posição correta:
    r->midias[r->qtdMidias -1] = midia_construct(dado, print_fn, free_fn);
}

void roteiro_imprimir_midias(Roteiro *r) {
    assert(r != NULL);
    if (r->qtdMidias == 0) {
        printf("SEM MIDIAS PARA IMPRIMIR\n");
        return;
    }

    printf("IMPRIMINDO MIDIAS\n");
    for (int i = 0; i < r->qtdMidias; i++) {
        printf("MIDIA %d: ", i + 1);
        midia_print(r->midias[i]);
        printf("\n");
    }
}

void roteiro_destroy(Roteiro *r) {
    if (r != NULL) {
        if (r->midias != NULL) {
            for (int i = 0; i < r->qtdMidias; i++)
                midia_destroy(r->midias[i]);
            
            free(r->midias);
        }
        free(r);
    }
}