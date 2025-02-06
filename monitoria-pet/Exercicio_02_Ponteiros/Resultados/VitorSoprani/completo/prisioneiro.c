#include <stdio.h>
#include <string.h>
#include "prisioneiro.h"

tPrisioneiro criaPrisioneiro(char* nome, int pena) {
    tPrisioneiro prisioneiro;

    strcpy(prisioneiro.nome, nome);
    prisioneiro.pena = pena;
    prisioneiro.tempoPassado = 0;

    return prisioneiro;
}

void passaTempoPrisioneiro(tPrisioneiro* prisioneiro) {
    prisioneiro->tempoPassado++;
}

void fogePrisioneiro(tPrisioneiro* prisioneiro) {
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

int acabouPenaPrisioneiro(tPrisioneiro* prisioneiro) {
    return prisioneiro->pena <= prisioneiro->tempoPassado;
}

void liberaPrisioneiroCumpriuPena(tPrisioneiro* prisioneiro) {
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

void liberaPrisioneiroFimPrograma(tPrisioneiro* prisioneiro) {
    printf("?????\n"); //nunca é usada
}