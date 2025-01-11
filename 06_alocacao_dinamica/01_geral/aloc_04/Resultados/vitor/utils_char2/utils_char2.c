#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"

#define DEBUG 1

char* CriaVetorTamPadrao() {
    char* vetor = (char*)malloc((TAM_PADRAO + 1) * sizeof(char));

#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'CriaVetorTamPadrao'.\n\tVetor nao pode ser inicializado.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < TAM_PADRAO; i++) {
        vetor[i] = '_';
    }

    vetor[TAM_PADRAO] = '\0';

    return vetor;
}

char* AumentaTamanhoVetor(char* vetor, int tamanhoantigo) {
    char* novoVetor;
    novoVetor = (char*)malloc((tamanhoantigo + TAM_PADRAO + 1) * sizeof(char));

#if DEBUG
    if (novoVetor == NULL) {
        printf("[ERRO] - Na funcao 'AumentaTamanhoVetor'.\n\tVetor nao pode ser inicializado.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < tamanhoantigo; i++)
        novoVetor[i] = vetor[i];


    for (int i = tamanhoantigo; i < tamanhoantigo + TAM_PADRAO; i++) {
        novoVetor[i] = '_';
    }

    novoVetor[tamanhoantigo + TAM_PADRAO] = '\0';

    LiberaVetor(vetor);

    return novoVetor;
}

char* LeVetor(char* vetor, int* tamanho) {
#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'LeVetor'.\n\tUm ponteiro nulo foi passado como argumento.\n");
        exit(1);
    }
#endif

    char c = 0;
    int i = 0;

    scanf("%c", &c);

    while (c != '\n') {
        if (i >= *tamanho) {
            vetor = AumentaTamanhoVetor(vetor, *tamanho);
            (*tamanho) += TAM_PADRAO;
        }
        vetor[i] = c;
        i++;
        scanf("%c", &c);
    }

    return vetor;
}

void ImprimeString(char* vetor) {
#if DEBUG
    if (vetor == NULL) {
        printf("[ERRO] - Na funcao 'ImprimeVetor'.\n\tUm ponteiro nulo foi passado como argumento.\n");
        exit(1);
    }
#endif

    printf("%s\n", vetor);
}

void LiberaVetor(char* vetor) {
    if (vetor == NULL)
        return;

    free(vetor);
}