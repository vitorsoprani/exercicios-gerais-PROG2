#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "contato.h"

#define MAX_TAM_STRING 100

struct Contato {
    char nome[MAX_TAM_STRING];
    unsigned long int telefone;
};

tContato *CriarContato(char *nome, unsigned long int telefone) {
    tContato* contato = (tContato*)malloc(sizeof(tContato));
    assert(contato != NULL);

    memset(contato->nome, 0, MAX_TAM_STRING);

    strcpy(contato->nome, nome);
    contato->telefone = telefone;

    return contato;
}

void DestruirContato(tContato *contato) {
    if (contato != NULL) {
        free(contato);
    }
}

void ImprimirContato(tContato *contato) {
    assert(contato != NULL);

    printf("Nome: %s\n", contato->nome);
    printf("Telefone: %lu\n\n", contato->telefone);
}

void SalvarContato(tContato *contato, FILE* arquivo) {
    assert(contato != NULL);
    assert(arquivo != NULL);
    
    fwrite(contato->nome, sizeof(char), MAX_TAM_STRING, arquivo);
    fwrite(&contato->telefone, sizeof(unsigned long int), 1, arquivo);
}

tContato *LeContato() {
    char nome[MAX_TAM_STRING] = "";
    unsigned long int telefone = 0;

    scanf("%*[^a-zA-Z0-9]");
    scanf("%[^\n]%*c", nome);
    scanf("%lu%*c", &telefone);
    
    return CriarContato(nome, telefone);
}

tContato *CarregarContato(FILE *arquivo) {
    assert(arquivo != NULL);

    char nome[MAX_TAM_STRING] = "";
    unsigned long int telefone = 0;

    fread(nome, sizeof(char), MAX_TAM_STRING, arquivo) ;
    fread(&telefone, sizeof(unsigned long int), 1, arquivo);

    assert(!feof(arquivo));

    return CriarContato(nome, telefone);
}

int ComparaTelefoneContato(tContato *c1, tContato *c2) {
    assert(c1 != NULL);
    assert(c2 != NULL);

    return c1->telefone == c2->telefone;
}

int ComparaNomeContato(tContato *c1, tContato *c2) {
    assert(c1 != NULL);
    assert(c2 != NULL);

    return strcmp(c1->nome, c2->nome) == 0;
}

unsigned long int GetTelefoneContato(tContato *contato) {
    assert(contato != NULL);

    return contato->telefone;
}

char *GetNomeContato(tContato *contato) {
    assert(contato != NULL);

    return contato->nome;
}