#include <stdlib.h>
#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro* CriaTabuleiro() {
    tTabuleiro* tab = (tTabuleiro*)malloc(sizeof(tTabuleiro));
    tab->peca1 = 'X';
    tab->peca2 = '0';
    tab->pecaVazio = '-';

    //INICIANDO TODAS POSICOES DO TABULEIRO COMO -:
    tab->posicoes = (char**)malloc(TAM_TABULEIRO * sizeof(char*));

    if (tab->posicoes == NULL) {
        printf("[ERRO] - Na função CriaTabuleiro.\n\tNão foi possivel alocar o tabuleiro.\n");
        exit(1);
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        tab->posicoes[i] = (char*)malloc(TAM_TABULEIRO * sizeof(char));

        if (tab->posicoes[i] == NULL) {
            printf("[ERRO] - Na função CriaTabuleiro.\n\tNão foi possivel alocar o tabuleiro.\n");
            exit(1);
        }

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tab->posicoes[i][j] = tab->pecaVazio;
        }
    }

    return tab;
}

void DestroiTabuleiro(tTabuleiro* tabuleiro) {
    if (tabuleiro != NULL) {
        if (tabuleiro->posicoes != NULL) {
            for (int i = 0; i < TAM_TABULEIRO; i++)
                if (tabuleiro->posicoes[i] != NULL)
                    free(tabuleiro->posicoes[i]);

            free(tabuleiro->posicoes);
        }
        free(tabuleiro);
    }
}

void MarcaPosicaoTabuleiro(tTabuleiro* tabuleiro, int peca, int x, int y) {
    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função MarcaPosicaoTabuleiro.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }

    //ATENÇÃO PARA O ÍNDICE "INVERTIDO"
    tabuleiro->posicoes[y][x] = (peca == PECA_1 ? tabuleiro->peca1 : tabuleiro->peca2);
}

int TemPosicaoLivreTabuleiro(tTabuleiro* tabuleiro) {
    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função TemPosicaoLivreTabuleiro.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, j, i))
                return 1;
        }
    }

    return 0;
}


int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro* tabuleiro, int x, int y, int peca) {
    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função EstaMarcadaPosicaoPecaTabuleiro.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }

    return tabuleiro->posicoes[y][x] == (peca == PECA_1 ? tabuleiro->peca1 : tabuleiro->peca2);
}

int EstaLivrePosicaoTabuleiro(tTabuleiro* tabuleiro, int x, int y) {
    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função EstaMarcadaPosicaoPecaTabuleiro.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }
    return tabuleiro->posicoes[y][x] == tabuleiro->pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro* tabuleiro) {
    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função ImprimeTabuleiro.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }

    if (tabuleiro->posicoes == NULL) {
        printf("[ERRO] - Na função ImprimeTabuleiro.\n\tFoi passado um tabuleiro com posicoes nulas como parametro.\n");
        exit(1);
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (tabuleiro->posicoes[i] == NULL) {
            printf("[ERRO] - Na função ImprimeTabuleiro.\n\tFoi passado um tabuleiro com posicoes nulas como parametro.\n");
            exit(1);
        }
        printf("\t");

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro->posicoes[i][j]);
        }

        printf("\n");
    }
}