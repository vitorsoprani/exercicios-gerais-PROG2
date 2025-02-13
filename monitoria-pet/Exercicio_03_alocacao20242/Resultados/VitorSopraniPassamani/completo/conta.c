#include <stdlib.h>

#include "conta.h"
#include "utils.h"
#include "usuario.h"

#define DEBUG 1

Conta* CriaConta(Usuario* usuario, int nConta) {
#if DEBUG
    if (usuario == NULL)
        ERRO("CriaConta(conta.c)", "Foi passado um poteiro NULL como argumeto (usuario)");
#endif

    Conta* conta = (Conta*)malloc(sizeof(Conta));

#if DEBUG
    if (conta == NULL)
        ERRO("CriaConta(conta.c)", "Nao foi possivel alocar o struct Conta");
#endif

    conta->movimentacoes = (float*)malloc(0);

#if DEBUG
    if (conta->movimentacoes == NULL)
        ERRO("CriaConta(conta.c)", "Nao foi possivel alocar o atributo movimentacoes do struct Conta");
#endif

    conta->usuario = usuario;
    conta->nConta = nConta;

    conta->saldo = 0;
    conta->qtdMovimentacoes = 0;

    return conta;
}

Conta* BuscaConta(Conta** contas, int qtdContas, int nConta) {
#if DEBUG
    if (contas == NULL)
        ERRO("BuscaConta(conta.c)", "Foi passado um ponteiro NULL como argumento (contas)");
#endif  

    for (int i = 0; i < qtdContas; i++) {
        if (RecuperaNConta(contas[i]) == nConta)
            return contas[i];
    }

    return NULL;
}

Usuario* RecuperaUsuario(Conta* conta) {
#if DEBUG
    if (conta == NULL)
        ERRO("RecuperaUsuario (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    return conta->usuario;
}

int RecuperaNConta(Conta* conta) {
#if DEBUG
    if (conta == NULL)
        ERRO("RecuperaNConta (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    return conta->nConta;
}

int RecuperaQtdMovimentacoes(Conta* conta) {
#if DEBUG
    if (conta == NULL)
        ERRO("RecuperaQtdMovimentacoes (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    return conta->qtdMovimentacoes;
}

float RecuperaSaldo(Conta* conta) {
#if DEBUG
    if (conta == NULL)
        ERRO("RecuperaSaldo (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    return conta->saldo;
}

float Saque(Conta* conta, float valor) {
#if DEBUG
    if (conta == NULL)
        ERRO("Saque (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    if (valor > RecuperaSaldo(conta) || valor < 0)
        return 0;

    conta->saldo -= valor;
    conta->qtdMovimentacoes++;
    conta->movimentacoes = (float*)realloc(conta->movimentacoes, conta->qtdMovimentacoes * sizeof(float));

#if DEBUG
    if (conta->movimentacoes == NULL)
        ERRO("Saque (conta.c)", "Nao foi possivel realocar o vetor de movimentacoes");
#endif

    conta->movimentacoes[conta->qtdMovimentacoes - 1] = -valor;

    return valor;
}

float Transferencia(Conta* contaOri, Conta* contaDes, float valor) {
#if DEBUG
    if (contaOri == NULL)
        ERRO("Transferencia (conta.c)", "Foi passado um ponteiro NULL como argumento (contaOri)");
    if (contaDes == NULL)
        ERRO("Transferencia (conta.c)", "Foi passado um ponteiro NULL como argumento (contaDes)");
#endif

    if (valor <= 0)
        return 0;

    if (Saque(contaOri, valor) == 0)
        return 0;

    Deposito(contaDes, valor);

    return valor;
}

float* RecuperaMovimentacoes(Conta* conta) {
#if DEBUG
    if (conta == NULL)
        ERRO("RecuperaMovimentacoes (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    return conta->movimentacoes;
}

void Deposito(Conta* conta, float valor) {
#if DEBUG
    if (conta == NULL)
        ERRO("Deposito (conta.c)", "Foi passado um ponteiro NULL como argumento (conta)");
#endif

    if (valor < 0)
        return;

    conta->saldo += valor;
    conta->qtdMovimentacoes++;
    conta->movimentacoes = (float*)realloc(conta->movimentacoes, conta->qtdMovimentacoes * sizeof(float));

#if DEBUG
    if (conta == NULL)
        ERRO("Deposito (conta.c)", "Nao foi possivel realocar o vetor de movimentacoes");
#endif

    conta->movimentacoes[conta->qtdMovimentacoes - 1] = valor;
}

void DestroiConta(Conta* conta) {
    if (conta != NULL) {
        // if (conta->usuario != NULL)
            // DestroiUsuario(conta->usuario);
        if (conta->movimentacoes != NULL)
            free(conta->movimentacoes);
        free(conta);
    }
}