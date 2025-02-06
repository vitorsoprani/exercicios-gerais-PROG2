#include <assert.h>
#include "cela.h"

tCela criaCela(int capacidade) {
    tCela cela;

    cela.capacidade = capacidade;
    cela.nPresidiarios = 0;

    return cela;
}

int possuiVagaCela(tCela* cela) {
    return cela->nPresidiarios < cela->capacidade;
}

int obtemNumeroPrisioneirosCela(tCela* cela) {
    return cela->nPresidiarios;
}

void inserePrisioneiroCela(tCela* cela, tPrisioneiro prisioneiro) {
    // assert(possuiVagaCela(cela));

    cela->prisioneiros[cela->nPresidiarios] = prisioneiro;
    cela->nPresidiarios++;
}

tPrisioneiro obtemPrisioneiroCela(tCela* cela, int i) {
    // assert(cela->nPresidiarios < i);

    return cela->prisioneiros[i];
}

void fogePrisioneirosCela(tCela* cela) {
    for (int i = 0; i < obtemNumeroPrisioneirosCela(cela); i++)
        fogePrisioneiro(&(cela->prisioneiros[i]));

    cela->nPresidiarios = 0;
}

void passaDiaCela(tCela* cela) {
    for (int i = 0; i < obtemNumeroPrisioneirosCela(cela); i++) {
        passaTempoPrisioneiro(&(cela->prisioneiros[i]));
    }

    for (int i = 0; i < obtemNumeroPrisioneirosCela(cela); i++) {
        if (acabouPenaPrisioneiro(&cela->prisioneiros[i])) {
            liberaPrisioneiroCumpriuPena(&cela->prisioneiros[i]);

            for (int j = i; j < cela->nPresidiarios - 1; j++) {
                cela->prisioneiros[j] = cela->prisioneiros[j + 1];
            }
            cela->nPresidiarios--;
        }
    }

}