#include <stdio.h>
#include "jogada.h"

tJogada LeJogada() {
    tJogada jogada;

    printf("Digite uma posicao (x e y):");
    jogada.sucesso = (scanf("%d %d%*c", &jogada.x, &jogada.y) == 2);

    printf("\n");

    return jogada;
}

int ObtemJogadaX(tJogada jogada) {
    return jogada.x;
}

int ObtemJogadaY(tJogada jogada) {
    return jogada.y;
}

int FoiJogadaBemSucedida(tJogada jogada) {
    return jogada.sucesso;
}
