#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "conta.h"

#define MAX_TAM_NOME 100
struct Conta {
    char* nome;
    int numero;
    float saldo;
};

tConta* CriaConta() {
    tConta* conta = (tConta*)malloc(sizeof(tConta));
    assert(conta != NULL);

    conta->nome = NULL;
    conta->numero = -1;
    conta->saldo = 0;

    return conta;
}

void DestroiConta(DataType conta) {
    if (conta != NULL) {
        if (((tConta*)conta)->nome != NULL)
            free(((tConta*)conta)->nome);

        free(conta);
    }
}

void LeConta(tConta* conta) {
    assert(conta != NULL);

    char nome[MAX_TAM_NOME];
    scanf("%d;%[^;];%f%*c", &conta->numero, nome, &conta->saldo);

    conta->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    assert(conta->nome != NULL);

    strcpy(conta->nome, nome);
}

float GetSaldoConta(tConta* conta) {
    assert(conta != NULL);

    return conta->saldo;
}