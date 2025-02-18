#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "gerenciadorpacotes.h"

#define MAX_PACOTES_INICIAL 1
#define MULTIPLICADOR_MAX_PACOTES   2

struct gerenciadorpacotes {
    int qtdPacotes;
    int maxPacotes;
    tPacote** pacotes;
};

tGerenciador* CriaGerenciador() {
    tGerenciador* geren = (tGerenciador*)malloc(sizeof(tGerenciador));
    assert(geren != NULL);

    geren->maxPacotes = MAX_PACOTES_INICIAL;
    geren->qtdPacotes = 0;

    geren->pacotes = (tPacote**)malloc(sizeof(tPacote*) * geren->maxPacotes);

    // SETA COMO NULL AS POSIÇÕES 
    for (int i = 0; i < geren->maxPacotes; i++) {
        geren->pacotes[i] = NULL;
    }

    return geren;
}

void AdicionaPacoteNoGerenciador(tGerenciador* geren, tPacote* pac) {
    assert(geren != NULL);
    assert(pac != NULL);

    if (geren->qtdPacotes == geren->maxPacotes) {
        geren->maxPacotes *= MULTIPLICADOR_MAX_PACOTES;
        geren->pacotes = realloc(geren->pacotes, sizeof(tPacote*) * geren->maxPacotes);

        // SETA COMO NULL AS POSIÇÕES RECEM ALOCADAS.
        for (int i = geren->qtdPacotes; i < geren->maxPacotes; i++) {
            geren->pacotes[i] = NULL;
        }
    }

    geren->pacotes[geren->qtdPacotes] = pac;
    geren->qtdPacotes++;
}

void DestroiGerenciador(tGerenciador* geren) {
    if (geren != NULL) {
        if (geren->pacotes != NULL) {
            for (int i = 0; i < geren->qtdPacotes; i++)
                DestroiPacote(geren->pacotes[i]);
            free(geren->pacotes);
        }
        free(geren);
    }
}

void ImprimirPacoteNoIndice(tGerenciador* geren, int idx) {
    assert(geren != NULL);

    if (idx < 0 || idx >= geren->qtdPacotes) {
        printf("IMPOSSIVEL IMPRIMIR: Indice invalido.\n");
        exit(1);
    }

    ImprimePacote(geren->pacotes[idx]);
}

void ImprimirTodosPacotes(tGerenciador* geren) {
    assert(geren != NULL);

    for (int i = 0; i < geren->qtdPacotes; i++) {
        ImprimirPacoteNoIndice(geren, i);
    }
}