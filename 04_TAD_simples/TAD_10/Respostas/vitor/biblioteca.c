#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

tBiblioteca inicializarBiblioteca() {
    tBiblioteca biblioteca;

    biblioteca.tamanho = 0;

    return biblioteca;
}

tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro) {
    if (biblioteca.tamanho == MAX_LIVROS) {
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
        return biblioteca;
    }

    biblioteca.livros[biblioteca.tamanho] = livro;
    biblioteca.tamanho++;
    printf("Livro adicionado com sucesso!\n");

    return biblioteca;
}

tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char* titulo) {
    for (int i = 0; i < biblioteca.tamanho; i++) {
        if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo) == 0) {
            printf("Livro removido com sucesso!\n");
            for (int j = i; j < biblioteca.tamanho - 1; j++) {
                biblioteca.livros[j] = biblioteca.livros[j + 1];
            }
            biblioteca.tamanho--;
            return biblioteca;
        }
    }

    printf("Livro nao encontrado na biblioteca.\n");

    return biblioteca;
}

int verificaTituloDoLivroNaBiblioteca(tLivros livro, char* titulo) {
    return strcmp(livro.titulo, titulo);
}

void listarLivrosDaBiblioteca(tBiblioteca biblioteca) {
    if (biblioteca.tamanho <= 0) {
        printf("A biblioteca esta vazia!");
    } else {
        printf("\nLista de Livros na Biblioteca:\n");

        for (int i = 0; i < biblioteca.tamanho; i++) {
            imprimeLivro(biblioteca.livros[i]);
        }
    }
}