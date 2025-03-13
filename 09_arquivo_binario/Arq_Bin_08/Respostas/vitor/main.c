#include <stdio.h>

#include "lista_contato.h"

void PrintaMenu();

int main() {
    tListaContato* lista = CriarListaContato();

    char nomeArquivo[100];
    scanf("%[^\n]%*c", nomeArquivo);
    CarregarListaContato(lista, nomeArquivo);
    
    int opt = 0;
    while(1) {
        PrintaMenu();
        scanf("%d%*c", &opt);

        if (opt == 0) {
            break;
        } else if (opt == 1) {
            tContato* c = LeContato();
            AdicionarContatoListaContato(lista, c);
        } else if (opt == 2) {
            RemoverContatoListaContato(lista);
        } else if (opt == 3) {
            printf("1 - Buscar pelo nome\n");
            printf("2 - Buscar pelo numero de telefone\n");
            printf("Opcao escolhida: \n");

            scanf("%d%*c", &opt);

            if (opt == 1) {
                BuscarPorNomeListaContato(lista);
            } else if (opt == 2) {
                BuscarPorNumeroTelefoneListaContato(lista);
            }
        } else if (opt == 4) {
            ImprimirListaContato(lista);
        }
    }

    scanf("%[^\n]%*c", nomeArquivo);
    SalvarListaContato(lista, nomeArquivo);

    DestruirListaContato(lista);

    return 0;
}


void PrintaMenu() {
    printf("1 - Cadastrar contato\n");
    printf("2 - Remover contato\n");
    printf("3 - Realizar busca\n");
    printf("4 - Exibir todos os contatos\n");
    printf("0 - Sair da lista de contatos\n");
    printf("Opcao escolhida: \n");
}

