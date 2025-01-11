#include <stdio.h>
#include "utils.h"

int main() {
    int linhas, colunas, ** matriz;

    scanf("%d %d", &linhas, &colunas);

    matriz = CriaMatriz(linhas, colunas);

    LeMatriz(matriz, linhas, colunas);

    ImprimeMatrizTransposta(matriz, linhas, colunas);

    LiberaMatriz(matriz, linhas);
    matriz = NULL;

    return 0;
}