#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "aluno.h"

#define MAX_STRING 101

struct Aluno{
    char* nome;
    int matricula;
    float n1, n2, n3;
};

tAluno* CriaAluno() {
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));

    assert(aluno != NULL);

    aluno->nome = NULL;
    aluno->matricula = -1;
    aluno->n1 = -1;
    aluno->n2 = -1;
    aluno->n3 = -1;

    return aluno;
}

void ApagaAluno(tAluno *aluno) {
    if (aluno != NULL) {
        if(aluno->nome != NULL)
            free(aluno->nome);
        
        free(aluno);
    }
}

void LeAluno(tAluno *aluno) {
    assert(aluno != NULL);
    
    char nome[MAX_STRING];
    scanf("%[^\n]%*c", nome);

    aluno->nome = (char*)malloc(sizeof(char) * strlen(nome) + 1);
    assert(aluno->nome != NULL);
    strcpy(aluno->nome, nome);

    scanf("%d%*c", &aluno->matricula);
    scanf("%f %f %f%*c", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno* aluno1, tAluno* aluno2) {
    assert(aluno1 != NULL);
    assert(aluno2 != NULL);

    if (aluno1->matricula > aluno2->matricula)
        return 1;
    if (aluno1->matricula < aluno2->matricula)
        return -1;
    
    return 0;
}

int CalculaMediaAluno(tAluno* aluno) {
    assert(aluno != NULL);

    float media;
    media = (((float)(aluno->n1 + aluno->n2 + aluno->n3)) / 3.0);

    return (int)media;
}

int VerificaAprovacao(tAluno* aluno) {
    assert(aluno != NULL);
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno* aluno) {
    printf("%s\n", aluno->nome);
    // printf("nome: %s matricula:%d\n\tN1:%f\n\tN2:%f\n\tN3:%f\n", aluno->nome, aluno->matricula, aluno->n1, aluno->n2, aluno->n3);
}