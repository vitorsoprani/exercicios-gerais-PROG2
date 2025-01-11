#include <stdio.h>
#include "utils.h"

int main() {
    int qtdNumeros, * vetor;
    scanf("%d", &qtdNumeros);

    vetor = CriaVetor(qtdNumeros);

    LeVetor(vetor, qtdNumeros);

    printf("%.2f\n", CalculaMedia(vetor, qtdNumeros));

    LiberaVetor(vetor);
    vetor = NULL;

    return 0;
}