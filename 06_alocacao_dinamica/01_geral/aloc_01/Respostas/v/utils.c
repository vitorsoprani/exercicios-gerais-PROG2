#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "utils.h"

int* CriaVetor(int tamanho) {
    int* vetor = NULL;
    vetor = (int*)malloc(tamanho * sizeof(int));

    assert(vetor != NULL);

    return vetor;
}

void LeVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", (vetor + i));
    }
}

float CalculaMedia(int* vetor, int tamanho) {
    float media = 0;

    for (int i = 0; i < tamanho; i++) {
        media += ((float)*(vetor + i)) / ((float)tamanho);
    }

    return media;
}

void LiberaVetor(int* vetor) {
    free(vetor);
}
