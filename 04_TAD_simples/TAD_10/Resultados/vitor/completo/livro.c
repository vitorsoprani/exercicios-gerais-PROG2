#include <stdio.h>
#include "livro.h"

tLivros lerLivro() {
    tLivros livro;
    scanf("%[^\n]%*c", livro.titulo);
    scanf("%[^\n]%*c", livro.autor);
    scanf("%d%*c", &livro.anoPublicacao);

    return livro;
}

void imprimeLivro(tLivros livro) {
    printf("Titulo: %s\n", livro.titulo);
    printf("Autor: %s\n", livro.autor);
    printf("Ano de Publicacao: %d\n", livro.anoPublicacao);
    printf("\n");
}