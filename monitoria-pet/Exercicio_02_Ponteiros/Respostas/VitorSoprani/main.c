#include <stdio.h>
#include "prisao.h"

int main() {
    int nCelas, capacidadeCelas;
    char nome[MAXTAM_NOME];
    scanf("%[^\n]%*c", nome);
    scanf("%d %d%*c", &nCelas, &capacidadeCelas);

    tPrisao prisao = criaPrisao(nome, nCelas, capacidadeCelas);
    executaPrisao(&prisao);

    return 0;
}