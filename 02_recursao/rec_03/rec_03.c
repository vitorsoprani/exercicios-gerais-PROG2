#include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

void LeVetorInt(int* vet, int numElementos);

int main() {
    int qtdCasos;
    scanf("%d", &qtdCasos);

    for (int i = 0; i < qtdCasos; i++) {
        int numProcurado;
        scanf("%d", &numProcurado);

        int numElementos;
        scanf("%d", &numElementos);

        int vet[numElementos];
        LeVetorInt(vet, numElementos);


        printf("%d\n", ContaOcorrencias(vet, numElementos, numProcurado));
    }

    return 0;
}

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    numElementos--;

    if (numElementos < 0) return 0;

    if (vet[numElementos] == numeroProcurado) {
        return 1 + ContaOcorrencias(vet, numElementos, numeroProcurado);
    } else {
        return ContaOcorrencias(vet, numElementos, numeroProcurado);
    }
}

void LeVetorInt(int* vet, int numElementos) {
    for (int i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
}