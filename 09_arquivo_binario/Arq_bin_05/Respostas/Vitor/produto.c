#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "produto.h"

#define MAX_TAM_NOME 50

struct Produto {
    int codigo;
    char* nome;
    float preco;
    int quantidade;
};

tProduto *CriaProduto(int codigo, char *nome, float preco, int quantidade) {
    tProduto* produto = (tProduto*)malloc(sizeof(tProduto));
    assert(produto != NULL);

    produto->codigo = codigo;
    produto->preco = preco;
    produto->quantidade = quantidade;

    produto->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    assert(produto->nome != NULL);

    strcpy(produto->nome, nome);

    return produto;
}

void DestroiProduto(tProduto *produto) {
    if (produto != NULL) {
        free(produto->nome);

        free(produto);
    }
}


tProduto *LeProduto(FILE *arquivo) {
    assert(arquivo != NULL);

    int codigo;
    char nome[MAX_TAM_NOME];
    float preco;
    int quantidade;

    fread(&codigo, sizeof(int), 1, arquivo);
    fread(nome, sizeof(char), MAX_TAM_NOME, arquivo);
    fread(&preco, sizeof(float), 1, arquivo);
    fread(&quantidade, sizeof(int),  1, arquivo);

    assert(!feof(arquivo));

    return CriaProduto(codigo, nome, preco, quantidade);
}

int TemEstoqueProduto(tProduto *produto) {
    assert(produto != NULL);

    return produto->quantidade > 0;
}

void ImprimeProduto(tProduto *produto) {
    assert(produto != NULL);
    printf("%d;%s;%.2f\n", produto->codigo, produto->nome, produto->preco);
}