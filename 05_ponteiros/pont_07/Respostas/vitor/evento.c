#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento* eventos, int* numEventos) {
    if (*numEventos >= MAX_EVENTOS) {
        printf("Limite de eventos atingido!\n");
        return;
    }

    Evento evento;

    scanf(" %[^\n]%*c", evento.nome);
    scanf("%d %d %d%*c", &evento.dia, &evento.mes, &evento.ano);

    eventos[*numEventos] = evento;
    (*numEventos)++;

    printf("Evento cadastrado com sucesso!\n");
}

void exibirEventos(Evento* eventos, int* numEventos) {
    if (*numEventos == 0) {
        printf("Nenhum evento cadastrado.\n");
        return;
    }
    printf("Eventos cadastrados:\n");
    for (int i = 0; i < *numEventos; i++) {
        printf("%d - %s - %d/%d/%d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento* eventos, int* numEventos) {
    int idxEvento;
    scanf("%d%*c", &idxEvento);

    if (idxEvento > (*numEventos) - 1) {
        printf("Indice invalido!\n");
        return;
    }

    scanf("%d %d %d%*c", &eventos[idxEvento].dia, &eventos[idxEvento].mes, &eventos[idxEvento].ano);
    printf("Data modificada com sucesso!\n");
}

void trocarIndicesEventos(Evento* eventos, int* indiceA, int* indiceB, int* numEventos) {
    if (*indiceA > (*numEventos) - 1 || *indiceB > (*numEventos) - 1) {
        printf("Indices invalidos!\n");
        return;
    }

    Evento aux = eventos[*indiceA];

    eventos[*indiceA] = eventos[*indiceB];
    eventos[*indiceB] = aux;

    printf("Eventos trocados com sucesso!\n");
}