#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "aluno.h"

#define MAX_STRINGS 100

struct aluno {
    char* nome;
    char* dtNasc;
    char* curso;
    char* periodoIngresso;

    int pctConclusao;
    float CRA;
};

Aluno** CriaVetorAlunos(int numeroAlunos) {
    Aluno** alunos = (Aluno**)malloc(sizeof(Aluno*) * numeroAlunos);

    assert(alunos != NULL);

    return alunos;
}

Aluno* CriaAluno(char *nome, char *dtNasc, char *cursoUfes, char* periodoIngresso, int percConclusao, float CRA) {
    Aluno* a = (Aluno*)malloc(sizeof(Aluno));
    assert(a != NULL);

    a->nome = (char*)malloc((strlen(nome) + 1) * sizeof(char));
    a->dtNasc = (char*)malloc((strlen(dtNasc) + 1) * sizeof(char));
    a->curso = (char*)malloc((strlen(cursoUfes) + 1) * sizeof(char));
    a->periodoIngresso = (char*)malloc((strlen(periodoIngresso) + 1) * sizeof(char));

    assert(a->nome != NULL);
    assert(a->dtNasc != NULL);
    assert(a->curso != NULL);
    assert(a->periodoIngresso != NULL);

    strcpy(a->nome, nome);
    strcpy(a->dtNasc, dtNasc);
    strcpy(a->curso, cursoUfes);
    strcpy(a->periodoIngresso, periodoIngresso);

    a->pctConclusao = percConclusao;
    a->CRA = CRA;

    return a;
}

void LeAlunos(Aluno** vetorAlunos, int numeroAlunos) {
    assert(vetorAlunos != NULL);

    char nome[MAX_STRINGS] = "";
    char dtNasc[MAX_STRINGS] = "";
    char cursoUfes[MAX_STRINGS] = "";
    char periodoIngresso[MAX_STRINGS] = "";
    int percConclusao = 0;
    float CRA = 0;

    //Limpando o buffer:
    scanf("%*[^a-zA-Z1-9]");

    for (int i = 0; i < numeroAlunos; i ++) {
        scanf("%[^\n]%*c", nome);
        scanf("%[^\n]%*c", dtNasc);
        scanf("%[^\n]%*c", cursoUfes);
        scanf("%[^\n]%*c", periodoIngresso);
        scanf("%d%*c", &percConclusao);
        scanf("%f%*c", &CRA);

        vetorAlunos[i] = CriaAluno(nome, dtNasc, cursoUfes, periodoIngresso, percConclusao, CRA);
    }
}

void LiberaAluno(Aluno* a) {
    if (a != NULL) {
        free(a->nome);
        free(a->dtNasc);
        free(a->curso);
        free(a->periodoIngresso);

        free(a);
    }
}

void LiberaAlunos(Aluno** alunos, int numeroAlunos) {
    if (alunos != NULL) {
        for (int i = 0; i < numeroAlunos; i++) {
            LiberaAluno(alunos[i]);
        }

        free(alunos);
    }
}

void SalvaAlunosBinario(Aluno **alunos, char *fileName, int numeroAlunos) {
    FILE* fp = fopen(fileName, "wb");
    assert(fp != NULL);

    int numBytesEscritos = 0;
    int tamString = 0;

    numBytesEscritos += sizeof(int) * fwrite(&numeroAlunos, sizeof(int), 1, fp);
    
    for (int i = 0; i < numeroAlunos; i++) {
        assert(alunos[i] != NULL);
        
        tamString = strlen(alunos[i]->nome);
        numBytesEscritos += sizeof(int) * fwrite(&tamString, sizeof(int), 1, fp);
        numBytesEscritos += sizeof(char) * fwrite(alunos[i]->nome, sizeof(char), tamString, fp);
        
        tamString = strlen(alunos[i]->dtNasc);
        numBytesEscritos += sizeof(int) * fwrite(&tamString, sizeof(int), 1, fp);
        numBytesEscritos += sizeof(char) * fwrite(alunos[i]->dtNasc, sizeof(char), tamString, fp);

        tamString = strlen(alunos[i]->curso);
        numBytesEscritos += sizeof(int) * fwrite(&tamString, sizeof(int), 1, fp);
        numBytesEscritos += sizeof(char) * fwrite(alunos[i]->curso, sizeof(char), tamString, fp);

        tamString = strlen(alunos[i]->periodoIngresso);
        numBytesEscritos += sizeof(int) * fwrite(&tamString, sizeof(int), 1, fp);
        numBytesEscritos += sizeof(char) * fwrite(alunos[i]->periodoIngresso, sizeof(char), tamString, fp);

        numBytesEscritos += sizeof(int) * fwrite(&alunos[i]->pctConclusao, sizeof(int), 1, fp);

        numBytesEscritos += sizeof(float) * fwrite(&alunos[i]->CRA, sizeof(float), 1, fp);
    }

    fclose(fp);

    printf("Numero de bytes salvos: %d\n", numBytesEscritos);
}

void CarregaAlunosBinario(Aluno **alunos, char *fileName) {
    FILE* fp = fopen(fileName, "rb");
    assert(fp != NULL);

    int qtdAlunos = 0;
    fread(&qtdAlunos, sizeof(int), 1, fp);

    char nome[MAX_STRINGS] = "";
    char dtNasc[MAX_STRINGS] = "";
    char curso[MAX_STRINGS] = "";
    char periodoIngresso[MAX_STRINGS] = "";
    
    int pctConclusao = 0;
    float CRA = 0;

    int tamString = 0;
    for (int i = 0; i < qtdAlunos; i++) {
        fread(&tamString, sizeof(int), 1, fp);
        fread(nome, sizeof(char), tamString, fp);
        nome[tamString] = '\0';

        fread(&tamString, sizeof(int), 1, fp);
        fread(dtNasc, sizeof(char), tamString, fp);
        dtNasc[tamString] = '\0';

        fread(&tamString, sizeof(int), 1, fp);
        fread(curso, sizeof(char), tamString, fp);
        curso[tamString] = '\0';
        
        fread(&tamString, sizeof(int), 1, fp);
        fread(periodoIngresso, sizeof(char), tamString, fp);
        periodoIngresso[tamString] = '\0';

        fread(&pctConclusao, sizeof(int), 1, fp);
        fread(&CRA, sizeof(float), 1, fp);
        
        assert(!feof(fp));

        alunos[i] = CriaAluno(nome, dtNasc, curso, periodoIngresso, pctConclusao, CRA);
    }

    fclose(fp);
}

void ImprimeAlunos(Aluno** alunos, int numeroAlunos) {
    assert(alunos != NULL);

    for (int i = 0; i < numeroAlunos; i++) {
        assert(alunos[i] != NULL);

        printf("Aluno %d:\n", i);
        printf("Nome: %s\n", alunos[i]->nome);
        printf("Data Nascimento: %s\n", alunos[i]->dtNasc);
        printf("Curso: %s\n", alunos[i]->curso);
        printf("Periodo Ingresso: %s\n", alunos[i]->periodoIngresso);
        printf("%% Conclusao do Curso: %d\n", alunos[i]->pctConclusao);
        printf("CRA: %.2f\n", alunos[i]->CRA);
    }
}