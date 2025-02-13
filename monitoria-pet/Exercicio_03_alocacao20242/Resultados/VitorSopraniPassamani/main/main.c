#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "conta.h"

#define SAIR            0
#define SAQUE           1
#define DEPOSITO        2
#define TRANSFERENCIA   3
#define CADASTRO        4
#define RELATORIO       5
#define EXTRATO         6

int main() {
    int qtdContas = 0;
    Conta** contas = (Conta**)malloc(sizeof(Conta*) * qtdContas);

    if (contas == NULL) {
        ERRO("main()", "Nao foi possivel alocar o vetor de contas");
    }

    int opcao;
    scanf("%d%*c", &opcao);

    while (opcao != SAIR) {
        if (opcao == SAQUE) {
            int nConta;
            float valor;
            Conta* conta;

            scanf("%d %f%*c", &nConta, &valor);

            conta = BuscaConta(contas, qtdContas, nConta);

            if (conta == NULL)
                goto fim_menu;

            Saque(conta, valor);

        } else if (opcao == DEPOSITO) {
            int nConta;
            float valor;
            Conta* conta;

            scanf("%d %f%*c", &nConta, &valor);

            conta = BuscaConta(contas, qtdContas, nConta);

            if (conta == NULL)
                goto fim_menu;

            Deposito(conta, valor);

        } else if (opcao == TRANSFERENCIA) {
            int nContaDest, nContaSrc;
            float valor;
            Conta* conta;

            scanf("%d %d %f%*c", &nContaSrc, &nContaDest, &valor);

            conta = BuscaConta(contas, qtdContas, nContaSrc);

            if (conta == NULL)
                goto fim_menu;

            if (Saque(conta, valor) != 0) {
                conta = BuscaConta(contas, qtdContas, nContaDest);

                if (conta == NULL)
                    goto fim_menu;

                Deposito(conta, valor);
            }

        } else if (opcao == CADASTRO) {
            char nome[200];
            int cpf, nConta;

            scanf("%199s %d %d%*c", nome, &cpf, &nConta);
            Usuario* usuario = CriaUsuario(nome, cpf);

            qtdContas++;
            contas = (Conta**)realloc(contas, sizeof(Conta*) * qtdContas);
            if (contas == NULL) {
                ERRO("main()", "Nao foi possivel realocar o vetor de contas");
            }

            contas[qtdContas - 1] = CriaConta(usuario, nConta);

        } else if (opcao == RELATORIO) {
            printf("===| Imprimindo Relatorio |===\n");

            for (int i = 0; i < qtdContas; i++) {
                Usuario* usr = RecuperaUsuario(contas[i]);

                printf("Conta: %d\n", RecuperaNConta(contas[i]));
                printf("Saldo: R$ %.2f\n", RecuperaSaldo(contas[i]));
                printf("Nome: %s\n", RecuperaNomeUsuario(usr));
                printf("CPF: %d\n", RecuperaCpfUsuario(usr));

                printf("\n");
            }

        } else if (opcao == EXTRATO) {
            int nConta, qtdOp;
            scanf("%d %d%*c", &nConta, &qtdOp);

            Conta* conta = BuscaConta(contas, qtdContas, nConta);

            if (conta == NULL)
                goto fim_menu;

            Usuario* usr = RecuperaUsuario(conta);

            printf("===| Imprimindo Extrato |===\n");

            printf("Conta: %d\n", RecuperaNConta(conta));
            printf("Saldo: R$ %.2f\n", RecuperaSaldo(conta));
            printf("Nome: %s\n", RecuperaNomeUsuario(usr));
            printf("CPF: %d\n", RecuperaCpfUsuario(usr));

            printf("\n");

            printf("Ultimas %d transações\n", qtdOp);
            float* transacoes = RecuperaMovimentacoes(conta);
            int qtdTransacoesConta = RecuperaQtdMovimentacoes(conta);

            if (qtdTransacoesConta < qtdOp)
                ERRO("main()", "Numero de transacoes selecionados para o extrato maior que o numero de transacoes na conta");

            for (int i = 1; i <= qtdOp; i++) {
                printf("%.2f\n", transacoes[qtdTransacoesConta - i]);
            }

            printf("\n");

        } else {
            ERRO("main()", "Opcao invalida");
        }

    fim_menu:
        scanf("%d%*c", &opcao);
    }

    for (int i = 0;i < qtdContas; i++) {
        DestroiUsuario(RecuperaUsuario(contas[i]));
        DestroiConta(contas[i]);
    }

    free(contas);

    return 0;
}
