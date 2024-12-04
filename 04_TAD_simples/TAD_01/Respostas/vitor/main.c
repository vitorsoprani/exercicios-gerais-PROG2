#include <stdio.h>
#include "jogo.h"

int main() {
    tJogo jogo = CriaJogo();

    int continua = 1;

    while (continua) {
        ComecaJogo(jogo);
        continua = ContinuaJogo();
    }

    return 0;
}