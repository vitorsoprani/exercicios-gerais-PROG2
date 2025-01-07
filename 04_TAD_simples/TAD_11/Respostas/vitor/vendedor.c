#include <stdio.h>
#include <string.h>
#include "vendedor.h"

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao) {
    tVendedor vendedor;

    strcpy(vendedor.nome, nome);
    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;

    vendedor.valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50]) {
    return strcmp(vendedor.nome, nome) == 0;
}

tVendedor ContabilizaVenda(tVendedor vendedor, float valor) {
    if (valor > 0) {
        vendedor.valor_vendido += valor;
    } else {
        printf("[ERRO] - Valor de venda inválido. (%f)\n", valor);
    }

    return vendedor;
}

float GetSalario(tVendedor vendedor) {
    return vendedor.salario;
}

float GetComissao(tVendedor vendedor) {
    return GetTotalVendido(vendedor) * vendedor.prct_comissao;
}

float GetTotalVendido(tVendedor vendedor) {
    return vendedor.valor_vendido;
}

float GetTotalRecebido(tVendedor vendedor) {
    return GetSalario(vendedor) + GetComissao(vendedor);
}

void ImprimeRelatorioVendedor(tVendedor vendedor) {
    printf("\t%s > Total vendido: R$%.2f\n", vendedor.nome, GetTotalVendido(vendedor));
    printf("\t\tTotal recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}