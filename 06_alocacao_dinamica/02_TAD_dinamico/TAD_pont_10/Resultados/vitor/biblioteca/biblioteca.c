#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "biblioteca.h"

tBiblioteca* InicializarBiblioteca() {
    tBiblioteca* biblioteca = (tBiblioteca*)malloc(sizeof(tBiblioteca));

    assert(biblioteca != NULL);

    for (int i = 0; i < MAX_LIVROS; i++) {
        biblioteca->livros[i] = NULL;
    }

    biblioteca->tamanho = 0;

    return biblioteca;
}

void ApagaBiblioteca(tBiblioteca* biblioteca) {
    if (biblioteca == NULL)
        return;

    for (int i = 0; i < MAX_LIVROS; i++) {
        if (biblioteca->livros[i] != NULL)
            ApagaLivro(biblioteca->livros[i]);
    }

    free(biblioteca);
}

void AdicionarLivroNaBiblioteca(tBiblioteca* biblioteca, tLivros* livro) {
    assert(biblioteca != NULL);
    assert(livro != NULL);

    if (biblioteca->tamanho == MAX_LIVROS) {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        ApagaLivro(livro);
        return;
    }

    biblioteca->livros[biblioteca->tamanho] = livro;
    biblioteca->tamanho++;
    printf("Livro adicionado com sucesso!\n");
}

void RemoverLivroDaBiblioteca(tBiblioteca* biblioteca, char* titulo) {
    assert(biblioteca != NULL);

    for (int i = 0; i < biblioteca->tamanho; i++) {
        if (VerificaTituloDoLivroNaBiblioteca(biblioteca->livros[i], titulo) == 0) {
            ApagaLivro(biblioteca->livros[i]);
            printf("Livro removido com sucesso!\n");

            for (int j = i; j < biblioteca->tamanho - 1; j++) {
                biblioteca->livros[j] = biblioteca->livros[j + 1];
            }
            biblioteca->livros[biblioteca->tamanho - 1] = NULL;
            biblioteca->tamanho--;
            return;
        }
    }

    printf("Livro nao encontrado na biblioteca.\n");
}

int VerificaTituloDoLivroNaBiblioteca(tLivros* livro, char* titulo) {
    assert(livro != NULL);
    return strcmp(livro->titulo, titulo);
}

void ListarLivrosDaBiblioteca(tBiblioteca* biblioteca) {
    assert(biblioteca != NULL);

    if (biblioteca->tamanho <= 0) {
        printf("A biblioteca esta vazia!");
    } else {
        printf("\nLista de Livros na Biblioteca:\n");

        for (int i = 0; i < biblioteca->tamanho; i++) {
            ImprimeLivro(biblioteca->livros[i]);
        }
    }
}