#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

tJogo* CriaJogo() {
    tJogo* jogo = (tJogo*)malloc(sizeof(tJogo));

    if (jogo == NULL) {
        printf("[ERRO] - Na função CriaJogo.\n\tNao foi possivel alocar o jogo.\n");
        exit(1);
    }

    jogo->jogador1 = CriaJogador(1);
    jogo->jogador2 = CriaJogador(2);
    jogo->tabuleiro = CriaTabuleiro();

    return jogo;
}

void ComecaJogo(tJogo* jogo) {
    int jogando = 1;

    int jogadorAtual = 1;

    if (jogo == NULL) {
        printf("[ERRO] - Na função ComecaJogo.\n\tFoi passado um ponteiro nulo como parametro.\n");
        exit(1);
    }

    while (jogando) {
        if (jogadorAtual == 1) {
            JogaJogador(jogo->jogador1, jogo->tabuleiro);
        } else {
            JogaJogador(jogo->jogador2, jogo->tabuleiro);
        }

        ImprimeTabuleiro(jogo->tabuleiro);

        jogadorAtual = jogadorAtual == 1 ? 2 : 1;

        jogando = !AcabouJogo(jogo);
    }
}

int AcabouJogo(tJogo* jogo) {
    if (VenceuJogador(jogo->jogador1, jogo->tabuleiro)) {
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    }
    if (VenceuJogador(jogo->jogador2, jogo->tabuleiro)) {
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    }
    if (!TemPosicaoLivreTabuleiro(jogo->tabuleiro)) {
        printf("Sem vencedor!\n");
        return 1;
    }

    return 0;
}

int ContinuaJogo() {
    char escolha;

    printf("Jogar novamente? (s,n)");
    scanf("%*[^sn]");
    scanf("%c%*c", &escolha);
    printf("\n");

    return escolha == 's';
}

void DestroiJogo(tJogo* jogo) {
    DestroiJogador(jogo->jogador1);
    DestroiJogador(jogo->jogador2);
    DestroiTabuleiro(jogo->tabuleiro);
    free(jogo);
}