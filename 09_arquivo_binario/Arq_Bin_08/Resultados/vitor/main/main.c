#include <stdio.h>

#include "lista_contato.h"

void PrintaMenu();

void Cadastrar();

void Buscar();

void (*table_lista[5])(tListaContato* lista);

int main() {
    table_lista[1] = Cadastrar;
    table_lista[2] = RemoverContatoListaContato;
    table_lista[3] = Buscar;
    table_lista[4] = ImprimirListaContato;
    
    tListaContato* lista = CriarListaContato();

    char nomeArquivo[100];
    scanf("%[^\n]%*c", nomeArquivo);
    CarregarListaContato(lista, nomeArquivo);
    
    int opt = 0;
    while(1) {
        PrintaMenu();
        scanf("%d%*c", &opt);

        if (opt == 0)
            break;

        table_lista[opt](lista);
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


void Cadastrar(tListaContato* lista) {
    tContato* c = LeContato();
    AdicionarContatoListaContato(lista, c);
}

void Buscar(tListaContato* lista) {
    int opt = 0;
    
    printf("1 - Buscar pelo nome\n");
    printf("2 - Buscar pelo numero de telefone\n");
    printf("Opcao escolhida: \n");

    scanf("%d%*c", &opt);

    if (opt == 1) {
        BuscarPorNomeListaContato(lista);
    } else if (opt == 2) {
        BuscarPorNumeroTelefoneListaContato(lista);
    }
}