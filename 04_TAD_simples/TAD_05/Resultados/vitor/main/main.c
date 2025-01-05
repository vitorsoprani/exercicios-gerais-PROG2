#include <stdio.h>
#include "conta.h"

#define SAIR        0
#define SAQUE       1
#define DEPOSITO    2
#define CADASTRO    3
#define RELATORIO   4

int main() {
    int qtdMaxContas;
    int qtdContas = 0;
    int operacao;

    scanf("%d%*c", &qtdMaxContas);

    tConta contas[qtdMaxContas];

    while (1) {
        scanf("%d", &operacao);

        if (operacao == SAIR) {
            break;
        } else if (operacao == SAQUE) {
            int numero;
            float valor;
            if (qtdContas <= 0) {
                printf("[ERRO] - Ainda não há contas cadastradas\n");
                continue;
            }

            scanf("%d %f ", &numero, &valor);

            for (int i = 0; i < qtdContas; i++) {
                if (VerificaConta(contas[i], numero)) {
                    contas[i] = SaqueConta(contas[i], valor);
                    break;
                }
            }
        } else if (operacao == DEPOSITO) {
            int numero;
            float valor;
            if (qtdContas <= 0) {
                printf("[ERRO] - Ainda não há contas cadastradas\n");
                continue;
            }

            scanf("%d %f ", &numero, &valor);

            for (int i = 0; i < qtdContas; i++) {
                if (VerificaConta(contas[i], numero)) {
                    contas[i] = DepositoConta(contas[i], valor);
                    break;
                }
            }
        } else if (operacao == CADASTRO) {
            char nome[50];
            char cpf[15];
            int numero;

            scanf("%s %s %d ", nome, cpf, &numero);

            contas[qtdContas] = CriaConta(numero, CriaUsuario(nome, cpf));
            qtdContas++;
        } else if (operacao == RELATORIO) {
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0;i < qtdContas; i++) {
                ImprimeConta(contas[i]);
                printf("\n");
            }
        } else {
            printf("[ERRO] - Codigo de operacao nao identificado (%d).\n", operacao);
            return 1;
        }
    }

    return 0;
}