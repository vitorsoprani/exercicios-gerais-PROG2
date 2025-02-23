#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "matrizgenerica.h"

struct matrizgenerica {
    int nLinhas;
    int nColunas;
    void*** conteudo;

    int tamElementos;
};


tMatrizGenerica* CriaMatrizGenerica(int linhas, int colunas, int numByteElem) {
    tMatrizGenerica* mat = (tMatrizGenerica*)malloc(sizeof(tMatrizGenerica));
    assert(mat != NULL);

    mat->conteudo = (void***)malloc(sizeof(void**) * linhas);
    assert(mat->conteudo != NULL);

    for (int i = 0; i < linhas; i++) {
        mat->conteudo[i] = (void**)malloc(sizeof(void*) * colunas);
        assert(mat->conteudo[i] != NULL);
    }

    mat->nLinhas = linhas;
    mat->nColunas = colunas;
    mat->tamElementos = numByteElem;

    return mat;
}

void DestroiMatrizGenerica(tMatrizGenerica* mat) {
    if (mat != NULL) {
        for (int i = 0; i < mat->nLinhas; i++) {
            for (int j = 0; j < mat->nColunas; j++) {
                if (mat->conteudo[i][j] != NULL)
                    free(mat->conteudo[i][j]);
            }
            // free(mat->conteudo[i]);
        }

        free(mat->conteudo);

        free(mat);
    }
}

int ObtemNumeroLinhasMatrizGenerica(tMatrizGenerica* mat) {
    assert(mat != NULL);

    return mat->nLinhas;
}

int ObtemNumeroColunasMatrizGenerica(tMatrizGenerica* mat) {
    assert(mat != NULL);

    return mat->nColunas;
}

void* ObtemElementoMatrizGenerica(tMatrizGenerica* mat, int linha, int coluna) {
    assert(mat != NULL);

    return mat->conteudo[linha][coluna];
}

void AtribuiElementoMatrizGenerica(tMatrizGenerica* mat, int linha, int coluna, void* elem) {
    assert(mat != NULL);
    assert(elem != NULL);

    mat->conteudo[linha][coluna] = elem;
}

void ImprimirMatrizGenerica(tMatrizGenerica* mat, void(imprime_elemento(void*))) {
    assert(mat != NULL);
    for (int i = 0; i < mat->nLinhas; i++) {
        for (int j = 0; j < mat->nColunas; j++) {
            imprime_elemento(mat->conteudo[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

tMatrizGenerica* MatrizTransposta(tMatrizGenerica* mat) {
    tMatrizGenerica* trans = CriaMatrizGenerica(mat->nColunas, mat->nLinhas, mat->tamElementos);


    for (int i = 0; i < trans->nLinhas; i++) {
        for (int j = 0; j < trans->nColunas; j++) {
            void* elemento = malloc(mat->tamElementos);
            memcpy(elemento, ObtemElementoMatrizGenerica(mat, j, i), mat->tamElementos);
            AtribuiElementoMatrizGenerica(trans, i, j, elemento);
        }
    }

    return trans;
}

tMatrizGenerica* MultiplicaMatrizes(tMatrizGenerica* mat1, tMatrizGenerica* mat2, int numByteTarget, void* (*multi_elem)(void*, void*), void* (*soma_elem)(void*, void*)) {


    // ALGORITIMO DE MULTIPLIUCAR MATRIZES:
    // for (int i = 0; i < r1; ++i) {
    //     for (int j = 0; j < c2; ++j) {
    //         for (int k = 0; k < c1; ++k) {
    //             result[i][j] += first[i][k] * second[k][j];
    //         }
    //     }
    // }

    tMatrizGenerica* result = CriaMatrizGenerica(mat1->nLinhas, mat2->nColunas, numByteTarget);

    // Inicializa a matriz result com 0.
    for (int i = 0; i < result->nLinhas; i++) {
        for (int j = 0; j < result->nColunas; j++) {
            AtribuiElementoMatrizGenerica(result, i, j, calloc(1, numByteTarget));
        }
    }

    for (int i = 0; i < mat1->nLinhas; i++) {
        for (int j = 0; j < mat2->nColunas; j++) {
            for (int k = 0; k < mat1->nColunas; k++) {
                void* multResult = multi_elem(ObtemElementoMatrizGenerica(mat1, i, k), ObtemElementoMatrizGenerica(mat2, k, j));
                void* sumResult = soma_elem(multResult, ObtemElementoMatrizGenerica(result, i, j));

                memcpy(result->conteudo[i][j], sumResult, numByteTarget);

                free(multResult);
                free(sumResult);
            }
        }
    }

    return result;
}

tMatrizGenerica* ConverteTipoMatriz(tMatrizGenerica* mat2, int novoNumByteElem, void* (*converte_elem)(void*)) {
    tMatrizGenerica* result = CriaMatrizGenerica(mat2->nLinhas, mat2->nColunas, novoNumByteElem);

    for (int i = 0; i < result->nLinhas; i++) {
        for (int j = 0; j < result->nColunas; j++) {
            AtribuiElementoMatrizGenerica(result, i, j, converte_elem(ObtemElementoMatrizGenerica(mat2, i, j)));
        }
    }

    return result;
}