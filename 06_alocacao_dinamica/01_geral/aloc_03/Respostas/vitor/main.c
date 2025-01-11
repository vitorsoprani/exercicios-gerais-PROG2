#include <stdio.h>
#include "utils_char.h"

int main() {
    int tamanho;
    char* vetor;

    scanf("%d%*c", &tamanho);

    vetor = CriaVetor(tamanho);

    ImprimeString(vetor, tamanho);

    LeVetor(vetor, tamanho);

    ImprimeString(vetor, tamanho);

    LiberaVetor(vetor);
    return 0;
}