#include <stdio.h>
#include "vetor.h"

void LeDadosParaVetor(int* vet, int tam) {
    for (int i = 0; i < tam; i++)
        scanf("%d", &vet[i]);
}

void ImprimeDadosDoVetor(int* n, int tam) {
    for (int i = 0; i < tam; i++)
        printf("%d ", n[i]);

    printf("\n");
}

void TrocaSeAcharMenor(int* vet, int tam, int* paraTrocar) {
    int idxMenor = 0;

    for (int i = 1; i < tam; i++) {
        if (vet[i] < vet[idxMenor])
            idxMenor = i;
    }

    if (vet[idxMenor] < *paraTrocar) {
        int aux = *paraTrocar;
        *paraTrocar = vet[idxMenor];
        vet[idxMenor] = aux;
    }
}

void OrdeneCrescente(int* vet, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        TrocaSeAcharMenor(vet + i + 1, tam - i - 1, &vet[i]);
    }
}