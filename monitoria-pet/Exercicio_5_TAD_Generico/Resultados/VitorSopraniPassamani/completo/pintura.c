#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "pintura.h"

//  Faz o casting de um ponteiro qualquer para um ponteiro do tipo especificado em "a"
#define cast(a, b) ((a*)b)

struct Pintura {
    char* titulo;
    char* artista;
    char* movimento;
    char* material;
    int ano;
};

Pintura* pintura_construct() {
    Pintura* p= (Pintura*)malloc(sizeof(Pintura));
    assert(p!= NULL);

    //  Variaveis temporarias com redundancia de memoria:
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char movimento[MAXTAM_STRINGS];
    char material[MAXTAM_STRINGS];

    //  Leitura dos dados:
    scanf("%s %s %s %s %d%*c", titulo, artista, movimento, material, &p->ano);

    //  Alocação das variaveis strings com tamanho "justificado":
    p->titulo = (char*)malloc(sizeof(char) * (strlen(titulo) + 1));
    assert(p!= NULL);

    p->artista = (char*)malloc(sizeof(char) * (strlen(artista) + 1));
    assert(p!= NULL);

    p->movimento = (char*)malloc(sizeof(char) * (strlen(movimento) + 1));
    assert(p!= NULL);

    p->material = (char*)malloc(sizeof(char) * (strlen(material) + 1));
    assert(p!= NULL);

    //  Atribuição dos dados às variaveis justificadas:
    strcpy(p->titulo, titulo);
    strcpy(p->artista, artista);
    strcpy(p->movimento, movimento);
    strcpy(p->material, material);

    return p;
}

void pintura_print(void* p) {
    assert(p != NULL);

    printf("PINTURA\n");
    printf("Titulo: %s\n", cast(Pintura, p)->titulo);
    printf("Artista: %s\n", cast(Pintura, p)->artista);
    printf("Movimento: %s\n", cast(Pintura, p)->movimento);
    printf("Material: %s\n", cast(Pintura, p)->material);
    printf("Ano: %d\n", cast(Pintura, p)->ano);
}

void pintura_destroy(void* p) {
    if (p != NULL) {
        free(cast(Pintura, p)->titulo);
        free(cast(Pintura, p)->artista);
        free(cast(Pintura, p)->movimento);
        free(cast(Pintura, p)->material);

        free(p);
    }
}