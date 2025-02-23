#include <stdio.h>
#include <stdlib.h>

#include "matrizgenerica.h"

void ImprimeInt(void* x) {
    printf("%d", *(int*)x);
}

void* MultiInt(void* n1, void* n2) {
    void* result = malloc(sizeof(int));
    *(int*)result = *(int*)n1 * *(int*)n2;

    return result;
}
void* SomaInt(void* n1, void* n2) {
    void* result = malloc(sizeof(int));
    *(int*)result = *(int*)n1 + *(int*)n2;

    return result;
}

int main() {
    tMatrizGenerica* mat;
    int nLinhas, nColunas;

    scanf("%d %d", &nLinhas, &nColunas);

    mat = CriaMatrizGenerica(nLinhas, nColunas, sizeof(int));

    int k = 0;
    for (int i = 0; i < ObtemNumeroLinhasMatrizGenerica(mat); i++) {
        for (int j = 0; j < ObtemNumeroColunasMatrizGenerica(mat); j++) {
            int* n = (int*)malloc(sizeof(int));
            *n = k++;
            AtribuiElementoMatrizGenerica(mat, i, j, n);
        }
    }

    ImprimirMatrizGenerica(mat, ImprimeInt);

    tMatrizGenerica* trans = MatrizTransposta(mat);

    ImprimirMatrizGenerica(trans, ImprimeInt);

    tMatrizGenerica* mult = MultiplicaMatrizes(mat, trans, sizeof(int), MultiInt, SomaInt);

    ImprimirMatrizGenerica(mult, ImprimeInt);

    DestroiMatrizGenerica(mat);
    DestroiMatrizGenerica(trans);
    DestroiMatrizGenerica(mult);
    return 0;
}