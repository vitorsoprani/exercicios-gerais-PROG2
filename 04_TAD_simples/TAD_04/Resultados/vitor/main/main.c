#include <stdio.h>
#include "aluno.h"

int main() {
    int qtdAlunos;

    scanf("%d%*c", &qtdAlunos);

    tAluno alunos[qtdAlunos];

    for (int i = 0; i < qtdAlunos; i++) {
        alunos[i] = LeAluno();
    }

    for (int i = 0; i < qtdAlunos - 1; i++) {
        for (int j = 0; j < qtdAlunos - i - 1; j++) {
            if (ComparaMatricula(alunos[j], alunos[j + 1]) > 0) {
                tAluno aux = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = aux;
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++) {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
    }
    return 0;
}