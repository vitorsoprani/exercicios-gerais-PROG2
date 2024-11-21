// #include "tabuleiro.h"


// #define ID_JOGADOR_1 1
// #define ID_JOGADOR_2 2


// typedef struct{
//     int id;
// } tJogador;

#include "jogador.h"
#include "jogada.h"
#include <stdio.h>

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador) {
    tJogador jogador;
    jogador.id = idJogador;

    return jogador;
}


/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro) {
    tJogada jogada = LeJogada();
    if (FoiJogadaBemSucedida(jogada)) {
        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        tabuleiro = MarcaPosicaoTabuleiro(tabuleiro, jogador.id, jogada.x, jogada.y);
        ImprimeTabuleiro(tabuleiro);
    }

    return tabuleiro;
}


/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro) {

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int ganhou = 1;

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            ganhou = ganhou && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, j, i, jogador.id);
        }

        if (ganhou) return 1;
    }

    for (int i = 0; i < TAM_TABULEIRO; i++) {
        int ganhou = 1;

        for (int j = 0; j < TAM_TABULEIRO; j++) {
            ganhou = ganhou && EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, i, j, jogador.id);
        }

        if (ganhou) return 1;
    }

    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 0, jogador.id) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 2, jogador.id)) {
        return 1;
    }

    if (EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 2, 0, jogador.id) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 1, 1, jogador.id) &&
        EstaMarcadaPosicaoPecaTabuleiro(tabuleiro, 0, 2, jogador.id)) {
        return 1;
    }

    return 0;
}