#include <stdio.h>
#include <stdlib.h>
#include "jogador.h"
#include "jogada.h"

tJogador* CriaJogador(int idJogador) {
    tJogador* jogador = (tJogador*)malloc(sizeof(tJogador));

    if (jogador == NULL) {
        printf("[ERRO] - Na função CriaJogador.\n\tNao foi possivel alocar o jogador.\n");
        exit(1);
    }

    jogador->id = idJogador;

    return jogador;
}

void DestroiJogador(tJogador* jogador) {
    if (jogador != NULL)
        free(jogador);
}

void JogaJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    if (jogador == NULL) {
        printf("[ERRO] - Na função JogaJogador.\n\tFoi Passado um jogador nulo como parametro.\n");
        exit(1);
    }

    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função JogaJogador.\n\tFoi Passado um tabuleiro nulo como parametro.\n");
        exit(1);
    }

    printf("Jogador %d\n", jogador->id);

    tJogada* jogada = CriaJogada();
    LeJogada(jogada);

    if (!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        JogaJogador(jogador, tabuleiro);
        DestroiJogada(jogada);
        return;
    }

    if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        JogaJogador(jogador, tabuleiro);
        DestroiJogada(jogada);
        return;
    }

    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    MarcaPosicaoTabuleiro(tabuleiro, jogador->id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));

    DestroiJogada(jogada);
}

int VenceuJogador(tJogador* jogador, tTabuleiro* tabuleiro) {
    if (jogador == NULL) {
        printf("[ERRO] - Na função VenceiJogador.\n\tFoi Passado um jogador nulo como parametro.\n");
        exit(1);
    }

    if (tabuleiro == NULL) {
        printf("[ERRO] - Na função VenceuJogador.\n\tFoi Passado um tabuleiro nulo como parametro.\n");
        exit(1);
    }

    int venceu;

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        venceu = 1;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador->id))
                venceu = 0;
        }
        if (venceu) return 1;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        venceu = 1;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador->id))
                venceu = 0;
        }
        if (venceu) return 1;
    }


    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador->id))
            venceu = 0;
    }
    if (venceu) return 1;

    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, (TAM_TABULEIRO - i) - 1, i, jogador->id))
            venceu = 0;
    }
    if (venceu) return 1;


    return 0;
}