#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa() {
    tPessoa pessoa;
    pessoa.nome[0] = '\0';

    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;

    return pessoa;
}

void LePessoa(tPessoa* pessoa) {
    scanf(" %[^\n]%*c", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa* pessoa) {
    return pessoa->pai != NULL || pessoa->mae != NULL;
}

void ImprimePessoa(tPessoa* pessoa) {
    if (!VerificaSeTemPaisPessoa(pessoa))
        return;

    printf("NOME COMPLETO: %s\n", pessoa->nome);
    printf("PAI: ");

    if (pessoa->pai != NULL) {
        printf("%s\n", pessoa->pai->nome);
    } else {
        printf("NAO INFORMADO\n");
    }

    printf("MAE: ");

    if (pessoa->mae != NULL) {
        printf("%s\n", pessoa->mae->nome);
    } else {
        printf("NAO INFORMADO\n");
    }

    printf("IRMAO: ");

    if (pessoa->irmao != NULL) {
        printf("%s\n", pessoa->irmao->nome);
    } else {
        printf("NAO INFORMADO\n");
    }

    printf("\n");
}

int VerificaIrmaoPessoa(tPessoa* pessoa1, tPessoa* pessoa2) {
    return pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai;
}

void AssociaFamiliasGruposPessoas(tPessoa* pessoas, int numPessoas) {
    int qtdAssociacoes;
    scanf("%d%*c", &qtdAssociacoes);

    for (int i = 0; i < qtdAssociacoes; i++) {
        int idxMae, idxPai, idxFilho;
        scanf("mae: %d, pai: %d, filho: %d%*c", &idxMae, &idxPai, &idxFilho);

        if (idxMae != -1)
            pessoas[idxFilho].mae = &pessoas[idxMae];

        if (idxPai != -1)
            pessoas[idxFilho].pai = &pessoas[idxPai];
    }

    for (int i = 0; i < numPessoas; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j])) {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}