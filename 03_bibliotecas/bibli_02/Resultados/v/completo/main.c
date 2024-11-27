#include <stdio.h>
#include "matrix_utils.h"

int main() {
    int running = 1;

    //DECLARAÇÃO E LEITURA DAS MATRIZES:
    int rows1, cols1, rows2, cols2;

    scanf("%d %d\n", &rows1, &cols1);

    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d\n", &rows2, &cols2);

    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    while (running) {
        //IMPRIMINDO O MENU:
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");

        int opcao;
        scanf("%d", &opcao);

        //TRATANDO RESPOSTA:
        switch (opcao) {
        case 1:
            if (possible_matrix_sum(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 2:
            if (possible_matrix_sub(rows1, cols1, rows2, cols2)) {
                int result[rows1][cols1];
                matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols1, result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 3:
            if (possible_matrix_multiply(cols1, rows2)) {
                int result[rows1][cols2];
                matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

                matrix_print(rows1, cols2, result);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            break;
        case 4:
            int scalar, n;
            scanf("%d %d", &scalar, &n);

            if (n == 1) {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
            } else if (n == 2) {
                scalar_multiply(rows2, cols2, matrix2, scalar);
                matrix_print(rows2, cols2, matrix2);
            }

            break;
        case 5: {
            int result[cols1][rows1];
            transpose_matrix(rows1, cols1, matrix1, result);
            matrix_print(cols1, rows1, result);

            int resul2[cols2][rows2];
            transpose_matrix(rows2, cols2, matrix2, resul2);
            matrix_print(cols2, rows2, resul2);
            break;
        }

        case 6:
            running = 0;
            break;
        }
    }
    return 0;
}