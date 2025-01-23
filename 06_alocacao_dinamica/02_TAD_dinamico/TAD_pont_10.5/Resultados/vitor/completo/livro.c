#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "livro.h"

tLivros* CriaLivro() {
    tLivros* livro = (tLivros*)malloc(sizeof(tLivros));

    assert(livro != NULL);

    livro->autor = NULL;
    livro->titulo = NULL;
    livro->anoPublicacao = -1;

    return livro;
}

void LerLivro(tLivros* livro) {
    assert(livro != NULL);

    livro->titulo = (char*)malloc(100 * sizeof(char));
    assert(livro->titulo != NULL);

    livro->autor = (char*)malloc(50 * sizeof(char));
    assert(livro->autor != NULL);

    scanf("%[^\n]%*c", livro->titulo);
    scanf("%[^\n]%*c", livro->autor);
    scanf("%d%*c", &livro->anoPublicacao);
}

void ImprimeLivro(tLivros* livro) {
    assert(livro != NULL);

    printf("Titulo: %s\n", livro->titulo);
    printf("Autor: %s\n", livro->autor);
    printf("Ano de Publicacao: %d\n", livro->anoPublicacao);
    printf("\n");
}

void ApagaLivro(tLivros* livro) {
    if (livro != NULL) {
        if (livro->autor != NULL)
            free(livro->autor);
        if (livro->titulo != NULL)
            free(livro->titulo);

        free(livro);
    }
}