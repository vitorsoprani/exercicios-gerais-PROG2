#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #include <string.h>

#include "estabelecimento.h"

struct Estabelecimento {
    tProduto** produtos;
    int qtdProdutos;
};

tEstabelecimento *CriaEstabelecimento() {
    tEstabelecimento* estabelecimento = (tEstabelecimento*)malloc(sizeof(tEstabelecimento));
    assert (estabelecimento != NULL);

    estabelecimento->qtdProdutos = 0;
    estabelecimento->produtos = (tProduto**)malloc(0);

    return estabelecimento;
}

void DestroiEstabelecimento(tEstabelecimento *estabelecimento) {
    if(estabelecimento != NULL) {
        for (int i = 0; i < estabelecimento->qtdProdutos; i++)
            DestroiProduto(estabelecimento->produtos[i]);
        
        free(estabelecimento->produtos);
        free(estabelecimento);
    }
}

void AdicionaProdutoEstabelecimento(tEstabelecimento *estabelecimento, tProduto *produto) {
    assert(estabelecimento != NULL);
    assert(produto != NULL);

    estabelecimento->qtdProdutos++;
    estabelecimento->produtos = (tProduto**)realloc(estabelecimento->produtos, sizeof(tProduto*) * estabelecimento->qtdProdutos);
    assert(estabelecimento->produtos != NULL);

    estabelecimento->produtos[estabelecimento->qtdProdutos - 1] = produto;
}

void LeEstabelecimento(tEstabelecimento *estabelecimento) {
    assert(estabelecimento != NULL);

    char caminho[50];
    FILE* produtosBin;
    int qtdProdutos;

    scanf("%[^\n]%*c", caminho);
    produtosBin = fopen(caminho, "rb");
    assert(produtosBin != NULL);

    fread(&qtdProdutos, sizeof(int), 1, produtosBin);

    for (int i = 0; i < qtdProdutos; i++) {
        tProduto* p = LeProduto(produtosBin);
        AdicionaProdutoEstabelecimento(estabelecimento, p);
    }

    fclose(produtosBin);
}

void ImprimeProdutosEmFaltaEstabelecimento(tEstabelecimento *estabelecimento) {
    assert(estabelecimento != NULL);

    int temProdutoFaltando = 0;

    printf("Produtos em falta:\n");
    printf("Codigo;Nome;Preco\n");
    for (int i = 0; i < estabelecimento->qtdProdutos; i++) {
        if (!TemEstoqueProduto(estabelecimento->produtos[i])) {
            temProdutoFaltando = 1;
            ImprimeProduto(estabelecimento->produtos[i]);
        }
    }

    if(!temProdutoFaltando) {
        printf("Nao ha produtos em falta!\n");
    }
}