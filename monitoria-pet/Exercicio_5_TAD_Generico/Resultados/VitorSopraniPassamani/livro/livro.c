#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "livro.h"

//  Faz o casting de um ponteiro qualquer para um ponteiro do tipo especificado em "a"
#define cast(a, b) ((a*)b)

struct Livro {
    char* titulo;
    char* autor;
    char* genero;
    char* editora;
    int anoPublicacao;
};

Livro* livro_construct() {
    Livro* l = (Livro*)malloc(sizeof(Livro));
    assert(l != NULL);

    //  Variaveis temporarias com redundancia de memoria:
    char titulo[MAXTAM_STRINGS];
    char autor[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char editora[MAXTAM_STRINGS];

    //  Leitura dos dados:
    scanf("%s %s %s %s %d%*c", titulo, autor, genero, editora, &l->anoPublicacao);

    //  Alocação das variaveis strings com tamanho "justificado":
    l->titulo = (char*)malloc(sizeof(char) * (strlen(titulo) + 1));
    assert(l != NULL);

    l->autor = (char*)malloc(sizeof(char) * (strlen(autor) + 1));
    assert(l != NULL);

    l->genero = (char*)malloc(sizeof(char) * (strlen(genero) + 1));
    assert(l != NULL);

    l->editora = (char*)malloc(sizeof(char) * (strlen(editora) + 1));
    assert(l != NULL);

    //  Atribuição dos dados às variaveis justificadas:
    strcpy(l->titulo, titulo);
    strcpy(l->autor, autor);
    strcpy(l->genero, genero);
    strcpy(l->editora, editora);

    return l;
}

void livro_print(void* l) {
    assert(l != NULL);
    printf("LIVRO\n");
    printf("Titulo: %s\n", cast(Livro, l)->titulo);
    printf("Autor: %s\n", cast(Livro, l)->autor);
    printf("Genero: %s\n", cast(Livro, l)->genero);
    printf("Editora: %s\n", cast(Livro, l)->editora);
    printf("Ano: %d\n", cast(Livro, l)->anoPublicacao);
}

void livro_destroy(void* l) {
    if (l != NULL) {
        free(cast(Livro, l)->titulo);
        free(cast(Livro, l)->autor);
        free(cast(Livro, l)->genero);
        free(cast(Livro, l)->editora);

        free(l);
    }
}