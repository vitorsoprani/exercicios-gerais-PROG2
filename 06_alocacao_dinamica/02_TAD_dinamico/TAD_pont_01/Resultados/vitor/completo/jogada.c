#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

tJogada* CriaJogada() {
    tJogada* jogada = (tJogada*)malloc(sizeof(tJogada));

    if (jogada == NULL) {
        printf("[ERRO] - Na funcao CriaJogada.\n\tJogada nao pode ser alocada.\n");
        exit(1);
    }

    return jogada;
}

void DestroiJogada(tJogada* jogada) {
    if (jogada != NULL)
        free(jogada);
}

void LeJogada(tJogada* jogada) {
    if (jogada == NULL) {
        printf("[ERRO] - Na funcao LeJogada.\n\tFoi passado um ponteiro nulo como argumento.\n");
        exit(1);
    }

    printf("Digite uma posicao (x e y):");
    if (scanf("%d %d%*c", &(jogada->x), &(jogada->y)) == 2) {
        jogada->sucesso = 1;
    } else {
        jogada->sucesso = 0;
    }

    printf("\n");
}

int ObtemJogadaX(tJogada* jogada) {
    if (jogada == NULL) {
        printf("[ERRO] - Na funcao ObtemJogadaX.\n\tFoi passado um ponteiro nulo como argumento.\n");
        exit(1);
    }

    return jogada->x;
}

int ObtemJogadaY(tJogada* jogada) {
    if (jogada == NULL) {
        printf("[ERRO] - Na funcao ObtemJogadaY.\n\tFoi passado um ponteiro nulo como argumento.\n");
        exit(1);
    }

    return jogada->y;
}

int FoiJogadaBemSucedida(tJogada* jogada) {
    if (jogada == NULL) {
        printf("[ERRO] - Na funcao FoiJogadaBemSucedida.\n\tFoi passado um ponteiro nulo como argumento.\n");
        exit(1);
    }

    return jogada->sucesso;
}