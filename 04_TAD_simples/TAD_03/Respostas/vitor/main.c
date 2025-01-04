#include <stdio.h>
#include <string.h>
#include "locadora.h"

char LerOpcao(void);

int main() {
    tLocadora locadora = criarLocadora();
    char opcao;

    opcao = LerOpcao();
    while (opcao != '!') {
        locadora = ordenarFilmesLocadora(locadora);

        switch (opcao) {
        case 'c': {
            //CADASTRO
            locadora = lerCadastroLocadora(locadora);
            break;
        }
        case 'a': {
            //ALUGUEL
            locadora = lerAluguelLocadora(locadora);
            break;
        }
        case 'd': {
            //DEVOLUÇÃO
            locadora = lerDevolucaoLocadora(locadora);
            break;
        }
        case 'e': {
            //ESTOQUE
            consultarEstoqueLocadora(locadora);
            scanf("%*c");
            break;
        }
        default: {
            printf("[ERRO] - Problema na leitura da opcao. (%c)\n", opcao);
            return 1;
        }
        }
        opcao = LerOpcao();
        printf("\n");
    }

    consultarLucroLocadora(locadora);

    return 0;
}

char LerOpcao(void) {
    char escolha[11];
    if (scanf("%s%*c", escolha) != 1)
        return '!';

    if (strcmp(escolha, "Cadastrar") == 0) {
        return 'c';
    } else if (strcmp(escolha, "Alugar") == 0) {
        return 'a';
    } else if (strcmp(escolha, "Devolver") == 0) {
        return 'd';
    } else if (strcmp(escolha, "Estoque") == 0) {
        return 'e';
    } else {
        return '#';
    }
}