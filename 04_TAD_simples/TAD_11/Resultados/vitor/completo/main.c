#include <stdio.h>
#include "loja.h"

#define SAIR                0
#define ABRIR_LOJA          1
#define CADASTRO_VENDEDOR   2
#define VENDA               3
#define RELATORIO           4

int main() {
    int totalLojas, qtdLojasCadastradas = 0, operacao;

    scanf("%d%*c", &totalLojas);

    tLoja lojas[totalLojas];


    while (1) {
        scanf("%d%*c", &operacao);

        if (operacao == SAIR) {
            break;
        } else if (operacao == ABRIR_LOJA) {
            int id;
            float aluguel;

            scanf("%d %f%*c", &id, &aluguel);
            lojas[qtdLojasCadastradas] = AbreLoja(id, aluguel);
            qtdLojasCadastradas++;
        } else if (operacao == CADASTRO_VENDEDOR) {
            char nome[50];
            float salario, prct_comissao;
            int idLoja;

            scanf("%s %f %f%*c", nome, &salario, &prct_comissao);
            scanf("%d%*c", &idLoja);


            for (int i = 0; i < qtdLojasCadastradas; i++) {
                if (VerificaIdLoja(lojas[i], idLoja)) {
                    lojas[i] = ContrataVendedor(lojas[i], RegistraVendedor(nome, salario, prct_comissao));
                    break;
                }
            }

        } else if (operacao == VENDA) {
            int idLoja;
            char nome[50];
            float valor;

            scanf("%d %s %f%*c", &idLoja, nome, &valor);

            for (int i = 0; i < qtdLojasCadastradas; i++) {
                if (VerificaIdLoja(lojas[i], idLoja)) {
                    lojas[i] = RegistraVenda(lojas[i], nome, valor);
                    break;
                }
            }
        } else if (operacao == RELATORIO) {
            for (int i = 0; i < qtdLojasCadastradas; i++) {
                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        } else {
            printf("[ERRO] - Codigo de operacao nao identificado. (%d)\n", operacao);
        }
    }
    return 0;
}