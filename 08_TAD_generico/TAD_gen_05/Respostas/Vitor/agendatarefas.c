#include <stdlib.h>
#include <assert.h>

#include "agendatarefas.h"
#include "tarefagenerica.h"

struct agendatarefas {
    tTarefa** tarefas;
    int maxElementos;
    int qtdElementos;
};


tAgendaTarefas* CriaAgendaDeTarefas(int numElem) {
    tAgendaTarefas* tar = (tAgendaTarefas*)malloc(sizeof(tAgendaTarefas));
    assert(tar != NULL);

    tar->tarefas = (tTarefa**)malloc(sizeof(tTarefa*) * numElem);
    assert(tar->tarefas != NULL);

    tar->maxElementos = numElem;
    tar->qtdElementos = 0;

    for (int i = 0; i < numElem; i++) {
        tar->tarefas[i] = NULL;
    }

    return tar;
}

void DestroiAgendaDeTarefas(tAgendaTarefas* tar) {
    if (tar != NULL) {
        if (tar->tarefas != NULL) {
            for (int i = 0; i < tar->qtdElementos; i++)
                DestroiTarefa(tar->tarefas[i]);

            free(tar->tarefas);
        }
        free(tar);
    }
}

void CadastraTarefaNaAgenda(tAgendaTarefas* tar, int prioridade, void* tarefa, void (*executa)(void*), void (*destroi)(void*)) {
    assert(tar != NULL);

    if (tar->qtdElementos == 0) {
        tar->tarefas[0] = CriaTarefa(prioridade, tarefa, executa, destroi);
        tar->qtdElementos++;
        return;
    }

    for (int i = 0; i < tar->maxElementos; i++) {
        if (tar->tarefas[i] == NULL) {
            tar->tarefas[i] = CriaTarefa(prioridade, tarefa, executa, destroi);
            tar->qtdElementos++;
            break;
        } else if (GetPrioridadeTarefa(tar->tarefas[i]) < prioridade) {
            tar->qtdElementos++;

            for (int j = tar->qtdElementos - 1; j > i; j--) {
                tar->tarefas[j] = tar->tarefas[j - 1];
            }

            tar->tarefas[i] = CriaTarefa(prioridade, tarefa, executa, destroi);
            break;
        }
    }
}

void ExecutarTarefasDaAgenda(tAgendaTarefas* tar) {
    assert(tar != NULL);

    for (int i = 0; i < tar->qtdElementos; i++) {
        ExecutaTarefa(tar->tarefas[i]);
    }
}