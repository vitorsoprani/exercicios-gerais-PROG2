#include <stdlib.h>
#include <assert.h>

#include "tarefagenerica.h"

struct tarefagenerica {
    void* tarefa;
    int prioridade;

    void(*executa)(void*);
    void(*destroi)(void*);
};


tTarefa* CriaTarefa(int prioridade, void* tarefa, void(*executa)(void*), void(*destroi)(void*)) {
    assert(tarefa != NULL);

    tTarefa* tGen = (tTarefa*)malloc(sizeof(tTarefa));
    assert(tGen != NULL);

    tGen->tarefa = tarefa;
    tGen->executa = executa;
    tGen->destroi = destroi;

    tGen->prioridade = prioridade;

    return tGen;
}


void DestroiTarefa(tTarefa* tarefa) {
    assert(tarefa != NULL);

    tarefa->destroi(tarefa->tarefa);
    free(tarefa);
}

void ExecutaTarefa(tTarefa* tarefa) {
    assert(tarefa != NULL);

    tarefa->executa(tarefa->tarefa);
}

int GetPrioridadeTarefa(tTarefa* tarefa) {
    assert(tarefa != NULL);

    return tarefa->prioridade;
}