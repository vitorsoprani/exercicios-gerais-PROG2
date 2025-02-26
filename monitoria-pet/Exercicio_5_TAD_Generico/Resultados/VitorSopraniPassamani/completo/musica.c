#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "musica.h"

//  Faz o casting de um ponteiro qualquer para um ponteiro do tipo especificado em "a"
#define cast(a, b) ((a*)b)

struct Musica {
    char* titulo;
    char* artista;
    int numParticipantes;
    char* participantes;
    char* album;
    char* genero;
};

Musica* musica_construct() {
    Musica* m = (Musica*)malloc(sizeof(Musica));
    assert(m != NULL);

    //  Variaveis temporarias com redundancia de memoria:
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char participantes[MAXTAM_STRINGS] = "";
    char participante[MAXTAM_STRINGS];
    char album[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];

    //  Leitura dos dados:
    scanf("%s %s %d ", titulo, artista, &m->numParticipantes);

    for (int i = 0; i < m->numParticipantes - 1; i++) {
        scanf("%s ", participante);
        strcat(participantes, participante);
        strcat(participantes, ", ");
    }
    scanf("%s ", participante);
    strcat(participantes, participante);

    scanf("%s %s%*c", album, genero);
    
    //  Alocação das variaveis strings com tamanho "justificado":
    m->titulo = (char*)malloc(sizeof(char) * (strlen(titulo) + 1));
    assert(m != NULL);

    m->artista = (char*)malloc(sizeof(char) * (strlen(artista) + 1));
    assert(m != NULL);

    m->participantes = (char*)malloc(sizeof(char) * (strlen(participantes) + 1));
    assert(m != NULL);

    m->album = (char*)malloc(sizeof(char) * (strlen(album) + 1));
    assert(m != NULL);

    m->genero = (char*)malloc(sizeof(char) * (strlen(genero) + 1));
    assert(m != NULL);

    //  Atribuição dos dados às variaveis justificadas:
    strcpy(m->titulo, titulo);
    strcpy(m->artista, artista);
    strcpy(m->participantes, participantes);
    strcpy(m->album, album);
    strcpy(m->genero, genero);

    return m;
}

void musica_print(void* m) {
    assert(m != NULL);

    printf("MUSICA\n");
    printf("%s - %s (feat. %s)\n", cast(Musica, m)->artista, cast(Musica, m)->titulo, cast(Musica, m)->participantes);
    printf("Album: %s\n", cast(Musica, m)->album);
    printf("Genero: %s\n", cast(Musica, m)->genero);            
}

void musica_destroy(void* m) {
    if (m != NULL) {
        free(cast(Musica, m)->titulo);
        free(cast(Musica, m)->artista);
        free(cast(Musica, m)->participantes);
        free(cast(Musica, m)->album);
        free(cast(Musica, m)->genero);

        free(m);
    }
}
