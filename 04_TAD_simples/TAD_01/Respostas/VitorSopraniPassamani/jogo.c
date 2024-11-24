#include "jogo.h"
#include <stdio.h>

/**
 * Cria um jogo e retorna o jogo criado.
 *
 * @return o jogo criado.
 */
tJogo CriaJogo() {
    tJogo jogo;

    jogo.tabuleiro = CriaTabuleiro();
    jogo.jogador1 = CriaJogador(1);
    jogo.jogador2 = CriaJogador(2);

    return jogo;
}


/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo) {
    int jogadorAtual = 0;
    while (1) {
        printf("Jogador %d\n", jogadorAtual + 1);
        if (jogadorAtual == 0) {
            jogo.tabuleiro = JogaJogador(jogo.jogador1, jogo.tabuleiro);
        } else {
            jogo.tabuleiro = JogaJogador(jogo.jogador2, jogo.tabuleiro);
        }

        jogadorAtual = !jogadorAtual;

        if (AcabouJogo(jogo)) {
            if (!ContinuaJogo()) {
                break;
            } else {
                jogo.tabuleiro = CriaTabuleiro();
                jogadorAtual = 0;
            }
        }
    }
}


/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo) {
    if (VenceuJogador(jogo.jogador1, jogo.tabuleiro)) {
        printf("JOGADOR 1 Venceu!\n");
        return 1;
    } else if (VenceuJogador(jogo.jogador2, jogo.tabuleiro)) {
        printf("JOGADOR 2 Venceu!\n");
        return 1;
    } else if (!TemPosicaoLivreTabuleiro(jogo.tabuleiro)) {
        printf("Sem vencedor!\n");
        return 1;
    }

    return 0;
}


/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo() {
    char continuar;

    printf("Jogar novamente? (s,n)\n");
    scanf("%c\n", &continuar);

    return continuar == 's';
}
