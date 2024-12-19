#include <stdio.h>
#include "utils.h"

int main() {
    int tam, * vet;
    float media = 0;

    scanf("%d", &tam);
    vet = CriaVetor(tam);

    LeVetor(vet, tam);

    media = CalculaMedia(vet, tam);

    printf("%.2f", media);

    LiberaVetor(vet);

    return 0;
}