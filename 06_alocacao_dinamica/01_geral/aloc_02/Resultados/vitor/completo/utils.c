#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define DEBUG 1

int** CriaMatriz(int linhas, int colunas) {
    int** mat;
    mat = (int**)malloc(linhas * sizeof(int*));

#if DEBUG
    if (mat == NULL) {
        printf("[ERRO] - na função 'CriaMatriz':\n\tNao foi possivel alocar a mariz.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < linhas; i++) {
        *(mat + i) = (int*)malloc(colunas * sizeof(int));
#if DEBUG
        if (mat[i] == NULL) {
            printf("[ERRO] - na função 'CriaMatriz':\n\tNao foi possivel alocar a mariz.\n");
            exit(1);
        }
#endif
    }

    return mat;
}

void LiberaMatriz(int** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        if (matriz[i] == NULL) {
            continue;
        }
        free(matriz[i]);
    }

    free(matriz);
}

void LeMatriz(int** matriz, int linhas, int colunas) {
#if DEBUG
    if (matriz == NULL) {
        printf("[ERRO] - na função 'LeMatriz':\n\tUma matriz nula foi passada como argumento.\n");
        exit(1);
    }
#endif

    for (int i = 0; i < linhas; i++) {
#if DEBUG
        if (matriz[i] == NULL) {
            printf("[ERRO] - na função 'LeMatriz':\n\tUma matriz com partes nulas foi passada como argumento.\n");
            exit(1);
        }
#endif
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void ImprimeMatrizTransposta(int** matriz, int linhas, int colunas) {
#if DEBUG
    if (matriz == NULL) {
        printf("[ERRO] - na função 'ImprimeTransposta':\n\tUma matriz nula foi passada como argumento.\n");
        exit(1);
    }

    for (int i = 0; i < linhas;i++) {
        if (matriz[i] == NULL) {
            printf("[ERRO] - na função 'ImprimeTransposta':\n\tUma matriz com partes nulas foi passada como argumento.\n");
            exit(1);
        }
    }
#endif

    for (int i = 0; i < colunas; i++) {
        for (int j = 0; j < linhas; j++) {
            printf("%d ", matriz[j][i]);
        }
        printf("\n");
    }
}