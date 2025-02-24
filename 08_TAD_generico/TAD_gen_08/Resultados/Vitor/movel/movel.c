#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "movel.h"

#define MAX_TAM_NOME 30

#define DEBUG 1

struct Movel {
    char* nome;
};

tMovel *CriaMovel(char *nome) {
    tMovel* m = (tMovel*)malloc(sizeof(tMovel));
    assert(m != NULL);

    m->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(m->nome, nome);

    return m;
}

void DestroiMovel(tMovel *m) {
    if (m != NULL) {
        if (m->nome != NULL)
            free(m->nome);
        free(m);
    }
}

tMovel *LeMovel() {
    char nome[MAX_TAM_NOME];

    scanf(" ");

    fgets(nome, MAX_TAM_NOME, stdin);

    return CriaMovel(nome);
}

void ImprimeMovel(tMovel *m) {
    #if DEBUG
        assert(m != NULL);
    #else
        if (m == NULL) return;
    #endif

    printf("%s", m->nome);
}