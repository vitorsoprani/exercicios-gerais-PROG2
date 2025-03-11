#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "base_alunos.h"
#include "aluno.h"

struct BaseAlunos {
    tAluno** alunos;
    int tamanho;
};


tBaseAlunos* CriarBaseAlunos() {
    tBaseAlunos* baseAlunos = (tBaseAlunos*)malloc(sizeof(tBaseAlunos));
    assert(baseAlunos != NULL);

    // ALOCANDO INCIALMENTE COM TAMANHO 0 PARA REALOCAR NA MEDIDA QUE FOR NECESSARIO.
    baseAlunos->alunos = (tAluno**)malloc(0);
    baseAlunos->tamanho = 0;

    return baseAlunos;
}

void DestruirBaseAlunos(tBaseAlunos* baseAlunos) {
    if (baseAlunos != NULL) {
        for (int i = 0; i < baseAlunos->tamanho; i++) 
            DestruirAluno(baseAlunos->alunos[i]);
        
        free(baseAlunos->alunos);
        free(baseAlunos);
    }
}

void LerBaseAlunos(tBaseAlunos* baseAlunos, char* nomeArquivo) {
    assert(baseAlunos != NULL);

    FILE* binFile = fopen(nomeArquivo, "rb");
    assert(binFile != NULL);

    int qtdAlunos = 0;
    fread(&qtdAlunos, sizeof(int), 1, binFile);

    baseAlunos->tamanho = qtdAlunos; 
    baseAlunos->alunos = (tAluno**)realloc(baseAlunos->alunos, sizeof(tAluno*) * qtdAlunos);

    for (int i = 0; i < qtdAlunos; i++)
        baseAlunos->alunos[i] = LeAluno(binFile);

    fclose(binFile);
}

float GetCoeficienteRendimentoMedioBaseAlunos(tBaseAlunos* baseAlunos) {
    assert(baseAlunos != NULL);

    float media = 0;
    for (int i = 0; i < baseAlunos->tamanho; i++)
        media += (float)GetCoeficienteRendimentoAluno(baseAlunos->alunos[i]) / (float)baseAlunos->tamanho;
    
    return media;
}