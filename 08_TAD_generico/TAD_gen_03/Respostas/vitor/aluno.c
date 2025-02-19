#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "aluno.h"

#define FEMININO    'F'
#define MASCULINO   'M'
#define OUTROS      'O'

struct Aluno {
    char* nome;
    float nota;
    char genero;
};

tAluno* CriaAluno() {
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));
    assert(aluno != NULL);

    aluno->nome = NULL;
    aluno->nota = -1;
    aluno->genero = '\0';

    return aluno;
}

void DestroiAluno(data_type aluno) {
    if (aluno != NULL) {
        if (((tAluno*)aluno)->nome != NULL)
            free(((tAluno*)aluno)->nome);
        free(aluno);
    }
}

void LeAluno(tAluno* aluno) {
    assert(aluno != NULL);

    char nome[51];

    scanf("%50[^;];%c;%f%*c", nome, &aluno->genero, &aluno->nota);

    aluno->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    strcpy(aluno->nome, nome);
}

char GetGeneroAluno(tAluno* aluno) {
    assert(aluno != NULL);

    return aluno->genero;
}

float GetNotaAluno(tAluno* aluno) {
    assert(aluno != NULL);

    return aluno->nota;
}