#include <stdio.h>
#include <string.h>
#include "aluno.h"

tAluno CriaAluno(char* nome, int matricula, int n1, int n2, int n3) {
    tAluno aluno;

    strcpy(aluno.nome, nome);
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

tAluno LeAluno() {
    char nome[50];
    int matricula;
    int n1, n2, n3;

    scanf("%[^\n]%*c", &nome);
    scanf("%d%*c", &matricula);
    scanf("%d %d %d%*c", &n1, &n2, &n3);

    return CriaAluno(nome, matricula, n1, n2, n3);
}

int ComparaMatricula(tAluno aluno1, tAluno aluno2) {
    if (aluno1.matricula < aluno2.matricula)
        return -1;
    if (aluno1.matricula > aluno2.matricula)
        return 1;

    return 0;
}

int CalculaMediaAluno(tAluno aluno) {
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

int VerificaAprovacao(tAluno aluno) {
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno aluno) {
    printf("%s\n", aluno.nome);
}
