#include <stdio.h>
#include "biblioteca.h"

int main() {
    tBiblioteca* biblioteca = InicializarBiblioteca();
    int qtdOperacoes, operacao;

    scanf("%d%*c", &qtdOperacoes);

    printf("Lista de operacoes:\n1 - Cadastrar livros.\n2 - Remover livros.\n3 - Listar todos os livros cadastrados.\n");
    printf("\n");

    for (int i = 0; i < qtdOperacoes; i++) {
        scanf("%d%*c", &operacao);

        if (operacao == 1) {
            tLivros* livro = CriaLivro();
            LerLivro(livro);
            AdicionarLivroNaBiblioteca(biblioteca, livro);
        } else if (operacao == 2) {
            char titulo[100];
            scanf("%[^\n]%*c", titulo);
            RemoverLivroDaBiblioteca(biblioteca, titulo);
        } else if (operacao == 3) {
            ListarLivrosDaBiblioteca(biblioteca);
        } else {
            printf("Operacao invalida!");
            break;
        }
    }

    ApagaBiblioteca(biblioteca);

    return 0;
}