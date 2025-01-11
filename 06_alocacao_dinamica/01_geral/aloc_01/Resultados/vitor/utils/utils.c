#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int* CriaVetor(int tamanho) {
    int* vetor = (int*)malloc(tamanho * sizeof(int));

    if (vetor == NULL) {
        printf("[ERRO] - na funcao CriaVetor:\n\tO vetor não pode ser alocado.\n");
        exit(1);
    }

    return vetor;
}

void LeVetor(int* vetor, int tamanho) {
    if (vetor == NULL) {
        printf("[ERRO] - na funcao LeVetor:\n\tPonteiro fornecido é NULL.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

float CalculaMedia(int* vetor, int tamanho) {
    float media = 0;

    if (vetor == NULL) {
        printf("[ERRO] - na funcao CalculaMedia:\n\tPonteiro fornecido é NULL.\n");
        exit(1);
    }

    for (int i = 0; i < tamanho; i++) {
        media += (float)vetor[i] / (float)tamanho;
    }

    return media;
}

void LiberaVetor(int* vetor) {
    if (vetor == NULL) {
        return;
    }

    free(vetor);
}