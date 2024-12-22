#include <stdio.h>
#include <string.h>
#include "product.h"

tProduct leProduto() {
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, id;

    printf("Nome do Produto: ");
    scanf("%[^\n]%*c", nome);

    printf("ID: ");
    scanf("%d%*c", &id);

    printf("Preco: ");
    scanf("%f%*c", &preco);

    printf("Desconto: ");
    scanf("%f%*c", &desconto);

    printf("Estoque: ");
    scanf("%d%*c", &estoque);

    return criaProduto(nome, desconto, preco, estoque, id);
}

tProduct criaProduto(char* nome, float desconto, float preco, int estoque, int id) {
    tProduct produto;

    strcpy(produto.nome, nome);

    produto.desconto = desconto;
    produto.preco = preco;
    produto.estoque = estoque;
    produto.id = id;

    produto.vendas = 0;

    return produto;
}

float obtemDesconto(tProduct produto) {
    return produto.desconto;
}

float obtempreco(tProduct produto) {
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto) {
    return (produto.preco - (produto.preco * produto.desconto));
}

int obtemEstoque(tProduct produto) {
    return produto.estoque;
}

int obtemVendas(tProduct produto) {
    return produto.vendas;
}

int obtemId(tProduct produto) {
    return produto.id;
}


tProduct aumentaEstoqueProduto(tProduct produto, int qtd) {
    if (qtd > 0) {
        produto.estoque += qtd;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}


tProduct vendeProduto(tProduct produto, int qtd) {
    if (obtemEstoque(produto) >= qtd && qtd > 0) {
        produto.estoque -= qtd;
        produto.vendas += qtd;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto) {
    if (desconto >= 0 && desconto <= 1) {
        produto.desconto = desconto;
    } else {
        printf("Quantidade inválida.\n");
    }

    return produto;
}

bool ehMesmoId(tProduct produto, int id) {
    return obtemId(produto) == id;
}

void imprimeProduto(tProduct produto) {
    // Produto: <nome>, Preco atual: <preco>, Qtd no estoque: <estoque>, Qtd vendida: <vendas>
    printf("Produto: %s, ", produto.nome);
    printf("Preco atual: %.2f, ", obtemPrecoComDesconto(produto));
    printf("Qtd no estoque: %d, ", obtemEstoque(produto));
    printf("Qtd vendida: %d\n", obtemVendas(produto));
}
