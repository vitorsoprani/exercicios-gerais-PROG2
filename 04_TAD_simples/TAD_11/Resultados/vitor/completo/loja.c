#include <stdio.h>
#include "loja.h"

tLoja AbreLoja(int id, float aluguel) {
    tLoja loja;

    loja.id = id;
    loja.aluguel = aluguel;

    loja.totalVendedores = 0;
    loja.lucro = 0;

    return loja;
}

int VerificaIdLoja(tLoja loja, int id) {
    return loja.id == id;
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor) {
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;

    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor) {
    for (int i = 0; i < loja.totalVendedores; i++) {
        if (VerificaNomeVendedor(loja.vendedores[i], nome)) {
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            return loja;
        }
    }

    printf("[ERRO] - Vendedor (%s) não registrado na loja (%d).\n", nome, loja.id);

    return loja;
}

tLoja CalculaLucro(tLoja loja) {
    float somaVendas = 0, somaDespesas = 0;

    somaDespesas += loja.aluguel;

    for (int i = 0; i < loja.totalVendedores; i++) {
        somaDespesas += GetTotalRecebido(loja.vendedores[i]);
        somaVendas += GetTotalVendido(loja.vendedores[i]);
    }

    loja.lucro = somaVendas - somaDespesas;

    return loja;
}

void ImprimeRelatorioLoja(tLoja loja) {
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);

    for (int i = 0; i < loja.totalVendedores; i++) {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}