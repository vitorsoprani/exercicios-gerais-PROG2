#include <assert.h>
#include "brasileirao.h"

struct _BRA {
    tTabela* tabela;
    int numTimes;
    int numRodadas;
    float premio;
};

BRA* CriaCamp() {
    BRA* br = (BRA*)malloc(sizeof(BRA));
    assert(br != NULL);

    printf("Insira o num de times, rodadas e premio total:\n");

    scanf("%d %d %f%*c", &br->numTimes, &br->numRodadas, &br->premio);

    br->tabela = CriaTabela(br->numTimes);

    return br;
}

void RealizaRodada(BRA* br) {
    assert(br != NULL);

    for (int i = 0; i < br->numTimes; i += 2) {
        char nomeT1[MAX_TIME_NOME], nomeT2[MAX_TIME_NOME];
        tTime* t1, * t2;
        int gols1, gols2;

        scanf("%s %d x %d %s%*c", nomeT1, &gols1, &gols2, nomeT2);

        t1 = ObtemTimeTabela(br->tabela, nomeT1);
        t2 = ObtemTimeTabela(br->tabela, nomeT2);

        if (t1 == NULL || t2 == NULL)
            return;

        AtualizaGolsMarcados(t1, gols1);
        AtualizaGolsSofridos(t1, gols2);

        AtualizaGolsMarcados(t2, gols2);
        AtualizaGolsSofridos(t2, gols1);

        if (gols1 < gols2) {
            AtualizaDerrotas(t1);
            AtualizaVitorias(t2);
        } else if (gols1 > gols2) {
            AtualizaVitorias(t1);
            AtualizaDerrotas(t2);
        } else {
            AtualizaEmpates(t1);
            AtualizaEmpates(t2);
        }
    }

    OrdenaTabela(br->tabela);
}

void RealizaCamp(BRA* br) {
    assert(br != NULL);

    char opt;

    for (int i = 0; i < br->numRodadas; i++) {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");

        scanf("%c%*c", &opt);

        if (opt == 'C') {
            RealizaRodada(br);
            ImprimeTabela(br->tabela);
        } else if (opt == 'R') {
            RemoveTimesCamp(br);
            if (br->numTimes <= 0)
                break;
            RealizaRodada(br);
            ImprimeTabela(br->tabela);
        } else if (opt == 'F') {
            break;
        } else {
            printf("[ERRO] - OPÇÃO INVALIDA!!!\n");
            exit(1);
        }
    }
}

void RemoveTimesCamp(BRA* br) {
    assert(br != NULL);

    char nomeT1[MAX_TIME_NOME], nomeT2[MAX_TIME_NOME];

    printf("Times a serem retirados:\n");
    scanf("%s %s%*c", nomeT1, nomeT2);

    RemoveTimeTabela(br->tabela, nomeT1);
    RemoveTimeTabela(br->tabela, nomeT2);

    printf("Os times %s e %s se retiraram do campeonato\n", nomeT1, nomeT2);

    br->numTimes -= 2;
}

void DesalocaCamp(BRA* br) {
    if (br != NULL) {
        DesalocaTabela(br->tabela);
        free(br);
    }
}

void FinalizaCamp(BRA* br) {
    assert(br != NULL);

    if (br->numTimes > 0) {
        printf("Esta foi a tabela final:\n");
        ImprimeTabela(br->tabela);
    }

    ImprimePremiacao(br->tabela, br->premio);
    printf("Fim do campeonato\n");
    DesalocaCamp(br);
}