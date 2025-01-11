#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

#define DEBUG 1

char* CriaVetor(int tamanho) {
    char* vetor = (char*)malloc(tamanho * sizeof(char));

#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'CriaVetor'.\n\tVetor não pode ser alocado.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = '_';
    }

    return vetor;

}

void LeVetor(char* vetor, int tamanho) {
#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'LeVetor'.\n\tUm ponteiro nulo foi passado como argumento.\n");
        exit(1);
    }
#endif

    char c = 0;
    int i = 0;

    scanf("%c", &c);

    while (c != '\n' && i < tamanho) {
        vetor[i] = c;
        i++;
        scanf("%c", &c);
    }
}

void ImprimeString(char* vetor, int tamanho) {
#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'LeVetor'.\n\tUm ponteiro nulo foi passado como argumento.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < tamanho; i++) {
        printf("%c", vetor[i]);
    }
    printf("\n");
}

void LiberaVetor(char* vetor) {
    if (vetor == NULL)
        return;
    free(vetor);
}