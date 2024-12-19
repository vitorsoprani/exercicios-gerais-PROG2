#include <stdio.h>
#include "utils_char.h"

int main() {
    int tamanho;
    char* vet = NULL;

    scanf("%d%*c", &tamanho);

    vet = CriaVetor(tamanho);
    ImprimeString(vet, tamanho);

    LeVetor(vet, tamanho);
    ImprimeString(vet, tamanho);

    LiberaVetor(vet);
    return 0;
}