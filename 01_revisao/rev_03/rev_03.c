#include <stdio.h>

void LeVetorInt(int* vet, int tamVet);
void OrdenaVetorInt(int* vet, int tamVet);
void ImprimeVetorInt(int* vet, int tamVet);

int main() {
    int qtdLivros;
    scanf("%d", &qtdLivros);

    int livros[qtdLivros];
    LeVetorInt(livros, qtdLivros);

    OrdenaVetorInt(livros, qtdLivros);

    int temRepetição = 0;

    if (livros[0] != livros[1]) {
        printf("%d ", livros[0]);
        temRepetição = 1;
    }

    for (int i = 1; i < qtdLivros - 1; i++) {
        if (livros[i] != livros[i - 1] && livros[i] != livros[i + 1]) {
            printf("%d ", livros[i]);
            temRepetição = 1;
        }
    }

    if (livros[qtdLivros - 1] != livros[qtdLivros - 2]) {
        printf("%d", livros[qtdLivros - 1]);
        temRepetição = 1;
    }

    if (!temRepetição) {
        printf("NENHUM");
    }

    return 0;
}

void LeVetorInt(int* vet, int tamVet) {
    for (int i = 0; i < tamVet; i++) {
        scanf("%d", &vet[i]);
    }
}

void OrdenaVetorInt(int* vet, int tamVet) {
    for (int i = 0; i < tamVet - 1; i++) {
        int idxMenorRelativo = i + 1;

        for (int j = i + 1; j < tamVet; j++) {
            if (vet[j] < vet[idxMenorRelativo]) idxMenorRelativo = j;
        }

        if (vet[idxMenorRelativo] < vet[i]) {
            // TROCA DE LUGAR
            int aux = vet[i];
            vet[i] = vet[idxMenorRelativo];
            vet[idxMenorRelativo] = aux;
        }
    }
}

void ImprimeVetorInt(int* vet, int tamVet) {
    for (int i = 0; i < tamVet; i++) {
        printf("%d ", vet[i]);
    }
}