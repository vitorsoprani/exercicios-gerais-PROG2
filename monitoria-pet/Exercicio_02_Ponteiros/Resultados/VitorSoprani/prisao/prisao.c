#include "prisao.h"
#include <stdlib.h>

tPrisao criaPrisao(char* nome, int nCelas, int capacidadeCelas) {
    tPrisao prisao;

    strcpy(prisao.nome, nome);
    prisao.nCelas = nCelas;
    prisao.capacidadeCelas = capacidadeCelas;

    prisao.dia = 0;

    for (int i = 0; i < nCelas; i++) {
        prisao.celas[i] = criaCela(capacidadeCelas);
    }

    return prisao;
}

void executaPrisao(tPrisao* prisao) {
    char opcao = '\0';
    while (opcao != 'E') {
        imprimeDiaEMenuPrisao(prisao);

        scanf("%c%*c", &opcao);
        switch (opcao) {
        case 'I':
            inserePrisioneiroPrisao(prisao);
            break;
        case 'P':
            passaDiaPrisao(prisao);
            break;
        case 'F':
            registraFugaCelaPrisao(prisao);
            break;
        case 'E':
            finalizaPrograma(prisao);
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }

        if (obtemNumeroPrisioneirosPrisao(prisao) >= prisao->nCelas * prisao->capacidadeCelas) {
            rebeliaoGeralPrisao(prisao);
            finalizaPrograma(prisao);
            break;
        }
    }
}

void imprimeDiaEMenuPrisao(tPrisao* prisao) {
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf(" I - Inserir detento\n");
    printf(" P - Passar o dia\n");
    printf(" F - Registrar fuga de cela\n");
    printf(" E - Encerrar programa\n");
}

void inserePrisioneiroPrisao(tPrisao* prisao) {
    int pena;
    char nome[MAXTAM_NOME];
    tPrisioneiro prisioneiro;
    printf("Informe a pena e o nome do prisioneiro:\n");
    scanf("%d %[^\n]%*c", &pena, nome);

    if (pena <= 0) {
        printf("Valor invalido\n");
        return;
    }

    prisioneiro = criaPrisioneiro(nome, pena);

    for (int i = 0; i < prisao->nCelas; i++) {
        if (possuiVagaCela(&prisao->celas[i])) {
            inserePrisioneiroCela(&prisao->celas[i], prisioneiro);
            printf("Detento %s foi inserido na cela %d\n", prisioneiro.nome, i);
            break;
        }
    }
}

void passaDiaPrisao(tPrisao* prisao) {
    prisao->dia++;
    for (int i = 0; i < prisao->nCelas; i++) {
        passaDiaCela(&prisao->celas[i]);
    }
}

void registraFugaCelaPrisao(tPrisao* prisao) {
    int idx;
    printf("Informe a cela em qual ocorreu a fuga:\n");
    scanf("%d%*c", &idx);

    if (idx < 0 || idx >= prisao->nCelas) {
        printf("Valor invalido\n");
        return;
    }

    fogePrisioneirosCela(&prisao->celas[idx]);
}

void finalizaPrograma(tPrisao* prisao) {
    if (obtemNumeroPrisioneirosPrisao(prisao) > 0) {
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    } else {
        printf("Fim do programa.\n");
    }
}

int obtemNumeroPrisioneirosPrisao(tPrisao* prisao) {
    int nPrisioneiros = 0;

    for (int i = 0; i < prisao->nCelas; i++) {
        nPrisioneiros += obtemNumeroPrisioneirosCela(&prisao->celas[i]);
    }

    return nPrisioneiros;
}

void rebeliaoGeralPrisao(tPrisao* prisao) {
    printf("REBELIAO GERAL\n");

    for (int i = 0; i < prisao->nCelas; i++) {
        fogePrisioneirosCela(&prisao->celas[i]);
    }
}