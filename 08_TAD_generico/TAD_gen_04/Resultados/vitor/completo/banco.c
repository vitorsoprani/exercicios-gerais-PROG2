#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "banco.h"

#define MAX_TAM_NOME 100

struct Banco {
    char* nome;
    Vector* agencias;
};

tBanco* CriaBanco() {
    tBanco* banco = (tBanco*)malloc(sizeof(tBanco));
    assert(banco != NULL);

    banco->nome = NULL;
    banco->agencias = VectorConstruct();

    return banco;
}

void DestroiBanco(tBanco* banco) {
    if (banco != NULL) {
        if (banco->nome != NULL)
            free(banco->nome);

        if (banco->agencias != NULL)
            VectorDestroy(banco->agencias, DestroiAgencia);

        free(banco);
    }
}

void LeBanco(tBanco* banco) {
    assert(banco != NULL);

    char nome[MAX_TAM_NOME];
    scanf("%[^\n]%*c", nome);

    banco->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    assert(banco->nome != NULL);
    strcpy(banco->nome, nome);
}

void AdicionaAgencia(tBanco* banco, tAgencia* agencia) {
    assert(banco != NULL);
    assert(agencia != NULL);

    VectorPushBack(banco->agencias, agencia);
}

void InsereContaBanco(tBanco* banco, int numAgencia, tConta* cliente) {
    assert(banco != NULL);
    assert(cliente != NULL);

    for (int i = 0; i < VectorSize(banco->agencias); i++) {
        if (ComparaAgencia(numAgencia, (tAgencia*)VectorGet(banco->agencias, i)))
            AdicionaConta((tAgencia*)VectorGet(banco->agencias, i), cliente);
    }
}

void ImprimeRelatorioBanco(tBanco* banco) {
    assert(banco != NULL);

    printf("%s\n", banco->nome);
    printf("Lista de agencias:\n");

    for (int i = 0; i < VectorSize(banco->agencias); i++) {
        ImprimeDadosAgencia((tAgencia*)VectorGet(banco->agencias, i));
    }
}