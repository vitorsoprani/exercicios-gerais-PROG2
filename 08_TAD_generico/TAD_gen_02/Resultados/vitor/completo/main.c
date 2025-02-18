#include <stdio.h>
#include "gerenciadorpacotes.h"

void ImprimeMenu();

int main() {
    int opt = 0;

    tGerenciador* geren = CriaGerenciador();

    printf("tad_gen_02\n");

    while (1) {
        ImprimeMenu();
        scanf("%d%*c", &opt);

        if (opt == 1) {
            int tipo;
            int qtdElementos;

            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem: ");
            scanf("%d %d", &tipo, &qtdElementos);

            tPacote* p = NULL;

            if (tipo == 0)
                p = CriaPacote(CHAR, qtdElementos);
            else if (tipo == 1)
                p = CriaPacote(INT, qtdElementos);
            else {
                printf("\nDigite um tipo valido!");
                continue;
            }

            LePacote(p);

            if (p != NULL)
                AdicionaPacoteNoGerenciador(geren, p);
        } else if (opt == 2) {
            int idx;
            scanf("%d%*c", &idx);
            ImprimirPacoteNoIndice(geren, idx);
        } else if (opt == 3) {
            ImprimirTodosPacotes(geren);
            break;
        } else {
            printf("Escolha uma opcao valida para o menu!");
        }
    }

    DestroiGerenciador(geren);
    return 0;
}

void ImprimeMenu() {
    printf("\nEscolha uma opcao:\n");
    printf("\t(1) Cadastrar um novo pacote\n");
    printf("\t(2) Imprimir um pacote específico\n");
    printf("\t(3) Imprimir todos os pacotes e sair\n");
}
