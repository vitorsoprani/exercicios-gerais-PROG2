#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "aluno.h"

#define MAX_TAM_NOME    100
#define MAX_TAM_DATA    11
#define MAX_TAM_CURSO   50

struct Aluno {
    char* nome;
    char* dataNascimento;
    char* curso;

    int periodo;
    float cr;
};

tAluno* CriarAluno(char* nome, char* dataNascimento, char* curso, int periodo, float coeficienteRendimento) {
    tAluno* aluno = (tAluno*)malloc(sizeof(tAluno));
    assert(aluno != NULL);

    // ALOCANDO A MEMORIA PARA AS STRINGS:
    aluno->nome = (char*)malloc(sizeof(char) * (strlen(nome) + 1));
    aluno->dataNascimento = (char*)malloc(sizeof(char) * (strlen(dataNascimento) + 1));
    aluno->curso = (char*)malloc(sizeof(char) * (strlen(curso) + 1));

    // CERTIFICANDO QUE TODAS AS ALOCAÇÕES FORAM BEM SUCEDIDAS:
    assert(aluno->nome != NULL);
    assert(aluno->dataNascimento != NULL);
    assert(aluno->curso != NULL);

    // COPIANDO O CONTEÚDO DOS ARGUMENTOS PARA AS STRINGS DO OBJETO:
    strcpy(aluno->nome, nome);
    strcpy(aluno->dataNascimento, dataNascimento);
    strcpy(aluno->curso, curso);

    aluno->periodo = periodo;
    aluno->cr = coeficienteRendimento;

    return aluno;
}

void DestruirAluno(tAluno* aluno) {
    if (aluno != NULL) {
        free(aluno->nome);
        free(aluno->dataNascimento);
        free(aluno->curso);

        free(aluno);
    }
}

tAluno *LeAluno(FILE *arquivo_binario) {
    assert(arquivo_binario != NULL);
    
    // DECLARAÇÃO DE VARIAVEIS TEMPORARIAS:
    char nome[MAX_TAM_NOME];
    char dataNascimento[MAX_TAM_DATA];
    char curso [MAX_TAM_CURSO];
    int periodo = 0;
    float cr = 0;

    // INCIALIZANDO AS STRINGS:
    // memset(nome, 0, sizeof(char) * MAX_TAM_NOME);
    // memset(dataNascimento, 0, sizeof(char) * MAX_TAM_DATA);
    // memset(curso, 0, sizeof(char) * MAX_TAM_CURSO);

    // LEITURA DAS VARIAVIES:
    fread(nome, sizeof(char), MAX_TAM_NOME, arquivo_binario);
    
    fread(dataNascimento, sizeof(char), MAX_TAM_DATA, arquivo_binario);

    fread(curso, sizeof(char), MAX_TAM_CURSO, arquivo_binario);

    fread(&periodo, sizeof(int), 1, arquivo_binario);

    fread(&cr, sizeof(float), 1, arquivo_binario);

    assert(!feof(arquivo_binario));

    return CriarAluno(nome, dataNascimento, curso, periodo, cr);
}

float GetCoeficienteRendimentoAluno(tAluno* aluno) {
    assert(aluno != NULL);

    return aluno->cr;
}