#include <assert.h>
#include "tabela.h"

struct _Tabela {
    int qtdTimes;
    tTime** times; //times no campeonato;
};

tTabela* CriaTabela(int numTimes) {
    tTabela* tabela = (tTabela*)malloc(sizeof(tTabela));
    assert(tabela != NULL);

    // printf("tabela criada\n");

    tabela->times = (tTime**)malloc(sizeof(tTime*) * numTimes);
    assert(tabela->times != NULL);

    // printf("tabela->times alocado\n");

    for (int i = 0; i < numTimes; i++) {
        tabela->times[i] = LeTime();
    }

    tabela->qtdTimes = numTimes;

    return tabela;
}

void DesalocaTabela(tTabela* tabela) {
    if (tabela != NULL) {
        if (tabela->times != NULL) {
            for (int i = 0; i < tabela->qtdTimes; i++)
                DesalocaTime(tabela->times[i]);

            free(tabela->times);
        }
        free(tabela);
    }
}

void OrdenaTabela(tTabela* tabela) {
    assert(tabela != NULL);

    for (int i = 0; i < tabela->qtdTimes - 1; i++) {
        for (int j = 0; j < tabela->qtdTimes - i - 1; j++) {
            if (ObtemPontos(tabela->times[j]) < ObtemPontos(tabela->times[j + 1])) {
                tTime* aux = tabela->times[j];
                tabela->times[j] = tabela->times[j + 1];
                tabela->times[j + 1] = aux;
            } else if (ObtemPontos(tabela->times[j]) == ObtemPontos(tabela->times[j + 1])) {
                if (DesempataTimes(tabela->times[j], tabela->times[j + 1]) == 1) {
                    tTime* aux = tabela->times[j];
                    tabela->times[j] = tabela->times[j + 1];
                    tabela->times[j + 1] = aux;
                }
            }
        }
    }
}

tTime* ObtemTimeTabela(tTabela* tabela, char* time) {
    assert(tabela != NULL);

    for (int i = 0; i < tabela->qtdTimes; i++) {
        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0) {
            return tabela->times[i];
        }
    }

    return NULL;
}

void RemoveTimeTabela(tTabela* tabela, char* time) {
    assert(tabela != NULL);

    tTime* t = ObtemTimeTabela(tabela, time);
    if (t == NULL) return;


    // REORGANIZA O VETOR PARA NAO FICAR "BURACO":
    for (int i = 0; i < tabela->qtdTimes; i++) {
        if (tabela->times[i] == t) {
            DesalocaTime(t);
            for (int j = i; j < tabela->qtdTimes - 1; j++) {
                tabela->times[j] = tabela->times[j + 1];
            }
            break;
        }
    }

    tabela->qtdTimes--;
}


void ImprimePremiacao(tTabela* tabela, float valorPremio) {
    assert(tabela != NULL);

    if (tabela->qtdTimes == 0) {
        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
    } else if (tabela->qtdTimes == 2) {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), valorPremio * 0.6);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), valorPremio * 0.4);
    } else if (tabela->qtdTimes >= 3) {
        printf("1º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[0]), valorPremio * 0.5);
        printf("2º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[1]), valorPremio * 0.3);
        printf("3º lugar - %s: R$%.2f\n", ObtemNomeTime(tabela->times[2]), valorPremio * 0.2);
    }
}

void ImprimeTabela(tTabela* tabela) {
    assert(tabela != NULL);

    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");

    for (int i = 0; i < tabela->qtdTimes; i++) {
        ImprimeTime(tabela->times[i]);
    }

    printf("\n");
}