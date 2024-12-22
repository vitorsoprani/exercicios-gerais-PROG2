#include <stdio.h>
#include "store.h"

char ObtemEscolha();

int main() {
    tStore loja = abreLoja();

    int rodando = 1;
    while (rodando) {
        char escolha = ObtemEscolha();

        switch (escolha) {
        case 'C': {
            loja = adicionaProduto(loja, leProduto());
            printf("\n");
            break;
        }
        case 'E': {
            int id = 0;
            int qtd = 0;
            printf("Digite o id do Produto: ");
            scanf("%d%*c", &id);
            printf("Digite o numero de unidades: ");
            scanf("%d%*c", &qtd);
            loja = aumentaEstoqueLoja(loja, id, qtd);
            printf("\n");
            break;
        }
        case 'V': {
            int id = 0;
            int qtd = 0;
            printf("Digite o id do Produto: ");
            scanf("%d%*c", &id);
            printf("Digite o numero de unidades: ");
            scanf("%d%*c", &qtd);
            loja = vendeProdutoLoja(loja, id, qtd);
            printf("\n");
            break;
        }
        case 'D': {
            int id = 0;
            float desconto = 0;
            printf("Digite o id do Produto: ");
            scanf("%d%*c", &id);
            printf("Digite o novo desconto: ");
            scanf("%f%*c", &desconto);
            loja = atualizaDescontoLoja(loja, id, desconto);
            printf("\n");
            break;
        }
        case 'I': {
            imprimeProdutosLoja(loja);
            printf("\n");
            break;
        }
        case 'R': {
            imprimeRelatorio(loja);
            printf("\n");
            break;
        }
        case 'F': {
            rodando = 0;
            break;
        }
        }
    }

    return 0;
}

char ObtemEscolha() {
    char escolha;
    printf("Menu:\n");
    printf(" C - Cadastrar Produto\n");
    printf(" E - Estocar Produto\n");
    printf(" V - Vender Produto\n");
    printf(" D - Atualizar desconto de Produto\n");
    printf(" I - Imprimir Produtos\n");
    printf(" R - Imprimir Relatorio de Vendas\n");
    printf(" F - Finalizar Programa\n");
    scanf("%c%*c", &escolha);

    return escolha;
}