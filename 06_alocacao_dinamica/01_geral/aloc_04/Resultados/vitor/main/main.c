#include <stdio.h>
#include "utils_char2.h"

int main() {
    int tam = TAM_PADRAO;
    char* vet;
    vet = CriaVetorTamPadrao();

    vet = LeVetor(vet, &tam);

    ImprimeString(vet);

    LiberaVetor(vet);
    return 0;
}