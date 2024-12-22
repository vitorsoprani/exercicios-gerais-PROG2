#include <stdio.h>
#include "store.h"

tStore abreLoja() {
    tStore loja;
    loja.nmProdutos = 0;
    loja.nmVendas = 0;
    loja.faturamento = 0;

    return loja;
}

tStore adicionaProduto(tStore loja, tProduct produto) {
    loja.produtos[loja.nmProdutos] = produto;

    loja.nmProdutos++;

    return loja;
}

int buscaProduto(tStore loja, int id) {
    for (int i = 0; i < loja.nmProdutos; i++) {
        if (ehMesmoId(loja.produtos[i], id)) {
            return i;
        }
    }

    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd) {
    int idxProduto;
    idxProduto = buscaProduto(loja, id);

    if (idxProduto != -1) {
        loja.produtos[idxProduto] = aumentaEstoqueProduto(loja.produtos[idxProduto], qtd);
    } else {
        printf("Produto não encontrado.\n");
    }

    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd) {
    int idxProduto;
    idxProduto = buscaProduto(loja, id);

    if (idxProduto != -1) {
        loja.produtos[idxProduto] = vendeProduto(loja.produtos[idxProduto], qtd);
        loja.faturamento += obtemPrecoComDesconto(loja.produtos[idxProduto]) * qtd;
        loja.nmVendas += qtd;
    } else {
        printf("Produto não encontrado.\n");
    }

    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto) {
    int idxProduto;
    idxProduto = buscaProduto(loja, id);

    if (idxProduto != -1) {
        loja.produtos[idxProduto] = atualizaDesconto(loja.produtos[idxProduto], desconto);
    } else {
        printf("Produto não encontrado.\n");
    }

    return loja;
}

void imprimeProdutosLoja(tStore loja) {
    for (int i = 0; i < loja.nmProdutos; i++) {
        imprimeProduto(loja.produtos[i]);
        printf("\n");
    }
}

void imprimeRelatorio(tStore loja) {
    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    printf("PRODUTO MAIS VENDIDO:\n");
    imprimeMaisVendido(loja);
}

int obtemEstoqueLoja(tStore loja) {
    int estoqueTotal = 0;

    for (int i = 0; i < loja.nmProdutos; i++) {
        estoqueTotal += obtemEstoque(loja.produtos[i]);
    }

    return estoqueTotal;
}

void imprimeMaisVendido(tStore loja) {
    int idxMaisVendido = 0;

    for (int i = 1; i < loja.nmProdutos; i++) {
        if (obtemVendas(loja.produtos[idxMaisVendido]) < obtemVendas(loja.produtos[i])) {
            idxMaisVendido = i;
        }
    }

    imprimeProduto(loja.produtos[idxMaisVendido]);
}
