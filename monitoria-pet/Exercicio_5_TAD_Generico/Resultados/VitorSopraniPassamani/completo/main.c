#include <stdio.h>

#include "musica.h"
#include "pintura.h"
#include "livro.h"
#include "roteiro.h"

#define LIVRO   'L'
#define MUSICA  'M'
#define PINTURA 'P'

int main() {
    int qtdMidias;
    scanf("%d%*c", &qtdMidias);

    Roteiro* r = roteiro_construct();

    for (int i = 0; i < qtdMidias; i++) {
        char tipoMidia;
        scanf("%c ", &tipoMidia);

        if (tipoMidia == LIVRO) {
            Livro* l = livro_construct();
            roteiro_inserir_midia(r, l, livro_print, livro_destroy);
        } else if (tipoMidia == MUSICA) {
            Musica* m = musica_construct();
            roteiro_inserir_midia(r, m, musica_print, musica_destroy);
        } else if (tipoMidia == PINTURA) {
            Pintura* p = pintura_construct();
            roteiro_inserir_midia(r, p, pintura_print, pintura_destroy);
        } else {
            // scanf("%*[^\n]%*c");
            // i--;

            printf("TIPO INVALIDO!!!!!!\n");
            return 1;
        }
    }

    roteiro_imprimir_midias(r);
    roteiro_destroy(r);

    return 0;
}