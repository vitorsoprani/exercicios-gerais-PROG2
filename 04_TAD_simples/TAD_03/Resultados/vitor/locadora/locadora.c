#include "locadora.h"
#include <stdio.h>

tLocadora criarLocadora() {
    tLocadora locadora;
    locadora.numFilmes = 0;
    locadora.lucro = 0;

    return locadora;
}

int verificarFilmeCadastrado(tLocadora locadora, int codigo) {
    for (int i = 0; i < locadora.numFilmes; i++)
        if (obterCodigoFilme(locadora.filme[i]) == codigo) return 1;
    return 0;
}

tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme) {
    if (verificarFilmeCadastrado(locadora, obterCodigoFilme(filme))) {
        printf("Filme ja cadastrado no estoque\n");
    } else {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
        printf("Filme cadastrado %d - ", obterCodigoFilme(filme));
        imprimirNomeFilme(filme);
        printf("\n");
    }

    return locadora;
}

tLocadora lerCadastroLocadora(tLocadora locadora) {
    int codigo;

    while (1) {
        if (scanf("%d,", &codigo) != 1) break;

        locadora = cadastrarFilmeLocadora(locadora, leFilme(codigo));
    }
    scanf("%*c");

    return locadora;
}

tLocadora alugarFilmesLocadora(tLocadora locadora, int* codigos, int quantidadeCodigos) {
    int qtdFilmesAlugados = 0;
    int custoTotal = 0;

    for (int i = 0; i < quantidadeCodigos; i++) {
        if (verificarFilmeCadastrado(locadora, codigos[i])) {
            for (int j = 0; j < locadora.numFilmes; j++) {
                if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                    if (obterQtdEstoqueFilme(locadora.filme[j]) <= 0) {
                        printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                        imprimirNomeFilme(locadora.filme[j]);
                        printf(" nao disponivel no estoque. Volte mais tarde.\n");
                    } else {
                        locadora.filme[j] = alugarFilme(locadora.filme[j]);
                        qtdFilmesAlugados++;
                        custoTotal += obterValorFilme(locadora.filme[j]);
                    }
                    break;
                }
            }
        } else {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    if (qtdFilmesAlugados > 0)
        printf("Total de filmes alugados: %d com custo de R$%d\n", qtdFilmesAlugados, custoTotal);


    return locadora;
}

tLocadora lerAluguelLocadora(tLocadora locadora) {
    int codigos[MAX_FILMES];
    int qtdCodigos = 0;
    int codigo;

    while (1) {
        if (scanf("%d", &codigo) != 1)
            break;

        scanf("%*c");

        codigos[qtdCodigos] = codigo;
        qtdCodigos++;
    }

    scanf("%*c");

    locadora = alugarFilmesLocadora(locadora, codigos, qtdCodigos);

    return locadora;
}

tLocadora devolverFilmesLocadora(tLocadora locadora, int* codigos, int quantidadeCodigos) {
    for (int i = 0; i < quantidadeCodigos; i++) {
        if (verificarFilmeCadastrado(locadora, codigos[i])) {
            for (int j = 0; j < locadora.numFilmes; j++) {
                if (ehMesmoCodigoFilme(locadora.filme[j], codigos[i])) {
                    if (obterQtdAlugadaFilme(locadora.filme[j]) <= 0) {
                        printf("Nao e possivel devolver o filme %d - ", codigos[i]);
                        imprimirNomeFilme(locadora.filme[j]);
                        printf(".\n");
                    } else {
                        locadora.filme[j] = devolverFilme(locadora.filme[j]);
                        printf("Filme %d - ", obterCodigoFilme(locadora.filme[j]));
                        imprimirNomeFilme(locadora.filme[j]);
                        printf(" Devolvido!\n");
                        locadora.lucro += obterValorFilme(locadora.filme[j]);
                    }

                    break;
                }
            }
        } else {
            printf("Filme %d nao cadastrado.\n", codigos[i]);
        }
    }

    return locadora;
}

tLocadora lerDevolucaoLocadora(tLocadora locadora) {
    int codigos[MAX_FILMES];
    int qtdCodigos = 0;
    int codigo;
    while (1) {
        if (scanf("%d", &codigo) != 1)
            break;

        scanf("%*c");

        codigos[qtdCodigos] = codigo;
        qtdCodigos++;
    }

    scanf("%*c");

    locadora = devolverFilmesLocadora(locadora, codigos, qtdCodigos);

    return locadora;
}

tLocadora ordenarFilmesLocadora(tLocadora locadora) {
    for (int i = 0; i < locadora.numFilmes - 1; i++) {
        for (int j = 0; j < locadora.numFilmes - i - 1; j++) {
            if (compararNomesFilmes(locadora.filme[j], locadora.filme[j + 1]) > 0) {
                tFilme aux = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j + 1];
                locadora.filme[j + 1] = aux;
            }
        }
    }

    return locadora;
}

void consultarEstoqueLocadora(tLocadora locadora) {
    locadora = ordenarFilmesLocadora(locadora);
    printf("~ESTOQUE~\n");
    for (int i = 0; i < locadora.numFilmes; i++) {
        printf("%d - ", obterCodigoFilme(locadora.filme[i]));
        imprimirNomeFilme(locadora.filme[i]);
        printf(" Fitas em estoque: %d\n", obterQtdEstoqueFilme(locadora.filme[i]));
    }
    // scanf("%*c");
}

void consultarLucroLocadora(tLocadora locadora) {
    if (locadora.lucro > 0) {
        printf("\nLucro total R$%d\n", locadora.lucro);
    }
}