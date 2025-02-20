#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "agencia.h"

#define MAX_TAM_NOME 100
struct Agencia {
    int numero;
    char* nome;
    Vector* contas;
};

tAgencia* CriaAgencia() {
    tAgencia* agencia = (tAgencia*)malloc(sizeof(tAgencia));
    assert(agencia != NULL);

    agencia->contas = VectorConstruct();

    return agencia;
}

void DestroiAgencia(DataType agencia) {
    if (agencia != NULL) {
        if (((tAgencia*)agencia)->contas != NULL)
            VectorDestroy(((tAgencia*)agencia)->contas, DestroiConta);
        if (((tAgencia*)agencia)->nome != NULL)
            free(((tAgencia*)agencia)->nome);
        free(agencia);
    }
}

void LeAgencia(tAgencia* agencia) {
    assert(agencia != NULL);

    char nome[MAX_TAM_NOME];

    scanf("%d;%[^\n]%*c", &agencia->numero, nome);

    agencia->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    assert(agencia->nome != NULL);

    strcpy(agencia->nome, nome);
}

void AdicionaConta(tAgencia* agencia, tConta* conta) {
    assert(agencia != NULL);
    assert(conta != NULL);

    VectorPushBack(agencia->contas, conta);
}

int ComparaAgencia(int numAgencia, tAgencia* agencia2) {
    assert(agencia2 != NULL);

    return numAgencia == agencia2->numero;
}

float GetSaldoMedioAgencia(tAgencia* agencia) {
    assert(agencia != NULL);

    float media = 0;
    int qtdContas = VectorSize(agencia->contas);

    for (int i = 0; i < qtdContas; i++) {
        media += GetSaldoConta(VectorGet(agencia->contas, i));
    }

    media /= qtdContas;

    return media;
}

void ImprimeDadosAgencia(tAgencia* agencia) {
    assert(agencia != NULL);

    printf("\tNome: %s\n", agencia->nome);
    printf("\tNumero: %d\n", agencia->numero);
    printf("\tNumero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("\tSaldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
    printf("\n");
}