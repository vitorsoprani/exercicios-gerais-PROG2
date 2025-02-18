#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "pacote.h"

struct pacote {
    Type tipo;
    int qtdElementos;
    int somaVerificacao;
    void* conteudo;
};

tPacote* CriaPacote(Type type, int numElem) {
    tPacote* pac = (tPacote*)malloc(sizeof(tPacote));
    assert(pac != NULL);

    pac->tipo = type;
    pac->qtdElementos = numElem;
    pac->somaVerificacao = -1;

    if (type == INT) {
        pac->conteudo = malloc(sizeof(int) * numElem);
    } else if (type == CHAR) {
        pac->conteudo = malloc(sizeof(char) * numElem);
    }

    return pac;
}

void DestroiPacote(tPacote* pac) {
    if (pac != NULL) {
        if (pac->conteudo != NULL)
            free(pac->conteudo);
        free(pac);
    }
}

void LePacote(tPacote* pac) {
    assert(pac != NULL);
    assert(pac->conteudo != NULL);


    printf("\nDigite o conteúdo do vetor/mensagem: ");

    scanf("\n");

    if (pac->tipo == INT) {
        for (int i = 0; i < pac->qtdElementos - 1; i++)
            scanf("%d ", &((int*)pac->conteudo)[i]);
        scanf("%d\n", &((int*)pac->conteudo)[pac->qtdElementos - 1]);
    } else if (pac->tipo == CHAR) {
        for (int i = 0; i < pac->qtdElementos; i++)
            scanf("%c", &((char*)pac->conteudo)[i]);
        scanf("\n");
    }

    CalculaSomaVerificacaoPacote(pac);
}

void ImprimePacote(tPacote* pac) {
    assert(pac != NULL);
    assert(pac->conteudo != NULL);

    printf("%d ", pac->somaVerificacao);

    if (pac->tipo == CHAR) {
        for (int i = 0; i < pac->qtdElementos; i++) {
            if (((char*)pac->conteudo)[i] != '\n')
                printf("%c", ((char*)pac->conteudo)[i]);
        }
    } else if (pac->tipo == INT) {
        for (int i = 0; i < pac->qtdElementos - 1; i++) {
            printf("%d ", ((int*)pac->conteudo)[i]);
        }
        printf("%d", ((int*)pac->conteudo)[pac->qtdElementos - 1]);
    }
    printf("\n");
}

void CalculaSomaVerificacaoPacote(tPacote* pac) {
    assert(pac != NULL);
    assert(pac->conteudo != NULL);

    pac->somaVerificacao = 0;

    if (pac->tipo == INT) {
        for (int i = 0; i < pac->qtdElementos; i++) {
            pac->somaVerificacao += ((int*)pac->conteudo)[i];
        }
    } else if (pac->tipo == CHAR) {
        for (int i = 0; i < pac->qtdElementos; i++) {
            if (((char*)pac->conteudo)[i] != '\n')
                pac->somaVerificacao += (int)((char*)pac->conteudo)[i];
        }
    }
}