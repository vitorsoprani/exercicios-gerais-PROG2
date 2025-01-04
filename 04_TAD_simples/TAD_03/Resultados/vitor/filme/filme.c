#include <stdio.h>
#include <string.h>
#include "filme.h"

tFilme criarFilme(char* nome, int codigo, int valor, int quantidade) {
    tFilme filme;

    strcpy(filme.nome, nome);
    filme.codigo = codigo;
    filme.valor = valor;
    filme.qtdEstoque = quantidade;
    filme.qtdAlugada = 0;

    return filme;
}

tFilme leFilme(int codigo) {
    char nome[MAX_CARACTERES];
    int valor, quantidade;
    scanf("%[^,],%d,%d%*c", nome, &valor, &quantidade);
    return criarFilme(nome, codigo, valor, quantidade);
}

int obterCodigoFilme(tFilme filme) {
    return filme.codigo;
}

void imprimirNomeFilme(tFilme filme) {
    printf("%s", filme.nome);
}

int obterValorFilme(tFilme filme) {
    return filme.valor;
}

int obterQtdEstoqueFilme(tFilme filme) {
    return filme.qtdEstoque;
}

int obterQtdAlugadaFilme(tFilme filme) {
    return filme.qtdAlugada;
}

int ehMesmoCodigoFilme(tFilme filme, int codigo) {
    return obterCodigoFilme(filme) == codigo;
}

tFilme alugarFilme(tFilme filme) {
    if (obterQtdEstoqueFilme(filme) <= 0) {
        printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", obterCodigoFilme(filme), filme.nome);
    } else {
        filme.qtdAlugada++;
        filme.qtdEstoque--;
    }

    return filme;
}

tFilme devolverFilme(tFilme filme) {
    if (obterQtdAlugadaFilme(filme) <= 0) {
        printf("Nao e possivel devolver o filme %d - %s\n", obterCodigoFilme(filme), filme.nome);
    } else {
        filme.qtdAlugada--;
        filme.qtdEstoque++;
    }

    return filme;
}

int compararNomesFilmes(tFilme filme1, tFilme filme2) {
    return strcmp(filme1.nome, filme2.nome);
}