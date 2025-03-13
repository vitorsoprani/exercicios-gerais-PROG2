#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "lista_contato.h"
#include "vector.h"


struct ListaContato {
    Vector* contatos;
};


tListaContato *CriarListaContato() {
    tListaContato* l = (tListaContato*)malloc(sizeof(tListaContato));
    assert(l != NULL);

    l->contatos = VectorConstruct();

    return l;
}

void DestruirListaContato(tListaContato *l) {
    if (l != NULL) {
        VectorDestroy(l->contatos, DestruirContato);

        free(l);
    }
}

void AdicionarContatoListaContato(tListaContato *l, tContato *contato) {
    assert(l != NULL);
    assert(contato != NULL);

    int tamanho = VectorSize(l->contatos);

    printf("\n"); //????
    
    for (int i = 0; i < tamanho; i++) {
        if (ComparaTelefoneContato(VectorGet(l->contatos, i), contato) || ComparaNomeContato(VectorGet(l->contatos, i), contato)) {
            printf("Ja existe um contato com esse nome e/ou numero de telefone\n");
            DestruirContato(contato);
            return;
        }
    }

    VectorPushBack(l->contatos, contato);
}

void CarregarListaContato(tListaContato *l, char* nomeArquivo) {
    assert(l != NULL);

    FILE* contatosBin = fopen(nomeArquivo, "rb");
    if (contatosBin == NULL) return;
   
    // IDENTIFICANDO O TAMANHO DA LISTA.
    int tamanho = 0;
    fread(&tamanho, sizeof(int), 1, contatosBin);

    // LENDO OS ELEMENTOS:
    for (int i = 0; i < tamanho; i++) {
        tContato* c = CarregarContato(contatosBin);
        VectorPushBack(l->contatos, c);
    }

    fclose(contatosBin);
}

void SalvarListaContato(tListaContato *l, char* nomeArquivo) {
    assert(l != NULL);

    FILE* contatosBin = fopen(nomeArquivo, "wb");
    assert(contatosBin != NULL);

    // INSERINDO O TAMANHO DA LISTA:
    int tamanho = VectorSize(l->contatos);
    fwrite(&tamanho, sizeof(int), 1, contatosBin);

    // ESCREVENDO OS CONTATOS:
    for (int i = 0; i < tamanho; i++) {
        tContato* c = VectorGet(l->contatos, i);
        SalvarContato(c, contatosBin);
    }

    fclose(contatosBin);
}

void BuscarPorNumeroTelefoneListaContato(tListaContato *l) {
    assert(l != NULL);

    unsigned long int tel;
    scanf("%*[^a-zA-Z0-9]");
    scanf("%lu%*c", &tel);

    int tamanho = VectorSize(l->contatos);

    for (int i = 0; i < tamanho; i++) {
        tContato* c = VectorGet(l->contatos, i);
        if (GetTelefoneContato(c) == tel){
            ImprimirContato(c);
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

void BuscarPorNomeListaContato(tListaContato *l) {
    assert(l != NULL);

    char nome[100] = "";
    scanf("%*[^a-zA-Z0-9]");
    scanf("%[^\n]%*c", nome);

    int tamanho = VectorSize(l->contatos);

    for (int i = 0; i < tamanho; i++) {
        tContato* c = VectorGet(l->contatos, i);
        if (strcmp(GetNomeContato(c), nome) == 0) {
            ImprimirContato(c);
            return;
        }
    }

    printf("Contato nao encontrado\n");
}

void ImprimirListaContato(tListaContato *l) {
    assert(l != NULL);

    int tamanho = VectorSize(l->contatos);
    printf("\n"); //????
    printf("Lista de contatos cadastrados\n");

    for (int i = 0; i < tamanho; i++) {
        tContato* c = VectorGet(l->contatos, i);
        ImprimirContato(c);
    }
}

void RemoverContatoListaContato(tListaContato *l) {
    assert(l != NULL);

    unsigned long int tel;
    scanf("%*[^a-zA-Z0-9]");
    scanf("%lu%*c", &tel);
    printf("\n"); //????

    int tamanho = VectorSize(l->contatos);

    for (int i = tamanho - 1; i >= 0; i--) {
        tContato* c = VectorGet(l->contatos, i);

        if (GetTelefoneContato(c) == tel){
            VectorRemove(l->contatos, i);
            DestruirContato(c);
            printf("Contato removido com sucesso\n");
            return;
        }
    }

    printf("Nao existe um contato cadastrado com esse numero de telefone\n");
}