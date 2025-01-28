#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "aluno.h"

int main() {
    int qtdAlunos;
    scanf("%d%*c", &qtdAlunos);

    tAluno** alunos = (tAluno**)malloc(sizeof(tAluno*) * qtdAlunos);
    assert(alunos != NULL);

    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = CriaAluno();
        LeAluno(alunos[i]);
    }

    // ORDENANDO O VETOR:
    
    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = 0; j < qtdAlunos - i - 1; j++) {
            if (ComparaMatricula(alunos[j], alunos[j + 1]) == 1) {
                tAluno *aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }

    for (int i = 0; i < qtdAlunos; i++) {
        ApagaAluno(alunos[i]);
    }

    free(alunos);

    return 0;
}