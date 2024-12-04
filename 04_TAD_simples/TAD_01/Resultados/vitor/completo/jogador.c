#include <stdio.h>
#include "jogador.h"
#include "jogada.h"

tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;

    return jogador;
}

tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    printf("Jogador %d\n", jogador.id);
    tJogada jogada = LeJogada();

    if (!EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        return JogaJogador(jogador, tabuleiro);
    }

    if (!EstaLivrePosicaoTabuleiro(tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada))) {
        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        return JogaJogador(jogador, tabuleiro);
    }

    printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    return MarcaPosicaoTabuleiro(tabuleiro, jogador.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
}

int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {
    int venceu;

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        venceu = 1;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id))
                venceu = 0;
        }
        if (venceu) return 1;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        venceu = 1;
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id))
                venceu = 0;
        }
        if (venceu) return 1;
    }


    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, i, jogador.id))
            venceu = 0;
    }
    if (venceu) return 1;

    venceu = 1;
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        if (!EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, (TAM_TABULEIRO - i) - 1, i, jogador.id))
            venceu = 0;
    }
    if (venceu) return 1;


    return 0;
}
