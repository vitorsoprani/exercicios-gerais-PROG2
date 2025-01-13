#include <stdio.h>
#include "jogo.h"

int main() {
    int continua = 1;

    while (continua) {
        tJogo* jogo = CriaJogo();

        ComecaJogo(jogo);

        DestroiJogo(jogo);

        continua = ContinuaJogo();
    }

    return 0;
}