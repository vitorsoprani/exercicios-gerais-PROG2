#include <stdio.h>
#include "tabuleiro.h"

tTabuleiro CriaTabuleiro() {
    tTabuleiro tab;
    tab.peca1 = 'X';
    tab.peca2 = '0';
    tab.pecaVazio = '-';

    //INICIANDO TODAS POSICOES DO TABULEIRO COMO -:
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tab.posicoes[i][j] = '-';
        }
    }

    return tab;
}

tTabuleiro MarcaPosicaoTabuleiro(tTabuleiro tabuleiro, int peca, int x, int y) {
    //ATENÇÃO PARA O ÍNDICE "INVERTIDO"
    tabuleiro.posicoes[y][x] = (peca == PECA_1 ? tabuleiro.peca1 : tabuleiro.peca2);

    return tabuleiro;
}

int TemPosicaoLivreTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (EstaLivrePosicaoTabuleiro(tabuleiro, j, i))
                return 1;
        }
    }

    return 0;
}

int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro tabuleiro, int x, int y, int peca) {
    return tabuleiro.posicoes[y][x] == (peca == PECA_1 ? tabuleiro.peca1 : tabuleiro.peca2);
}

int EstaLivrePosicaoTabuleiro(tTabuleiro tabuleiro, int x, int y) {
    return tabuleiro.posicoes[y][x] == tabuleiro.pecaVazio;
}

int EhPosicaoValidaTabuleiro(int x, int y) {
    return (x >= 0 && x < TAM_TABULEIRO) && (y >= 0 && y < TAM_TABULEIRO);
}

void ImprimeTabuleiro(tTabuleiro tabuleiro) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("\t");
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%c", tabuleiro.posicoes[i][j]);
        }
        printf("\n");
    }
}
