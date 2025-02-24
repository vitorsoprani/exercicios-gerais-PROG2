#include <stdio.h>

#include "histograma.h"
#include "imagem.h"

int main() {
    int nIntervalos = 0;

    scanf("%d%*c", &nIntervalos);

    Imagem* img = LerImagem();
    Histograma* hist = CalcularHistograma(img, nIntervalos);

    MostrarHistograma(hist);

    DestruirHistograma(hist);
    DestruirImagem(img);

    return 0;
}