#include "utils_char.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

char* CriaVetor(int tamanho) {
    char* vetor = NULL;
    vetor = (char*)malloc(tamanho * sizeof(char));
    assert(vetor != NULL);

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }

    return vetor;
}

void LeVetor(char* vetor, int tamanho) {
    assert(vetor != NULL);

    char caracter;
    int i = 0;

    while (scanf("%c", &caracter) == 1) {
        if (caracter == '\n') break;
        if (i >= tamanho) {
            scanf("%*c");
            break;
        }
        vetor[i] = caracter;
        i++;
    }
}

void ImprimeString(char* vetor, int tamanho) {
    assert(vetor != NULL);

    for (int i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }

    printf("\n");
}

void LiberaVetor(char* vetor) {
    assert(vetor != NULL);

    free(vetor);
}
