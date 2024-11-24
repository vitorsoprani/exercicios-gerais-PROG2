#include <stdio.h>

// Função recursiva que retorna a soma dos elementos pares.
int SomaElementosPares(int* vet, int numElementos);

void LeVetorIntr(int* vet, int numElementos);

int main() {
    int qtdVetores;
    scanf("%d", &qtdVetores);

    for (int i = 0; i < qtdVetores; i++) {
        int numElementos;
        scanf("%d", &numElementos);

        int vet[numElementos];
        LeVetorIntr(vet, numElementos);

        printf("%d\n", SomaElementosPares(vet, numElementos));
    }

    return 0;
}

int SomaElementosPares(int* vet, int numElementos) {
    int idx = numElementos - 1;

    if (idx < 0) return 0;

    if (vet[idx] % 2 == 0) { //É par;
        return vet[idx] + SomaElementosPares(vet, idx);
    } else {
        return SomaElementosPares(vet, idx);
    }
}

void LeVetorIntr(int* vet, int numElementos) {
    for (int i = 0; i < numElementos; i++) {
        scanf("%d", &vet[i]);
    }
}