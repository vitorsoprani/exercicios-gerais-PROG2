#include <stdio.h>
#include "matrix_utils.h"

int main() {
    int running = 1;

    //DECLARAÇÃO E LEITURA DAS MATRIZES:
    tMatrix matrix1, matrix2;

    int rows, cols;

    scanf("%d %d", &rows, &cols);
    matrix1 = MatrixCreate(rows, cols);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d", &rows, &cols);
    matrix2 = MatrixCreate(rows, cols);
    matrix2 = MatrixRead(matrix2);

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
            if (PossibleMatrixSum(matrix1, matrix2)) {
                tMatrix result;
                result = MatrixAdd(matrix1, matrix2);

                MatrixPrint(result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 2:
            if (PossibleMatrixSub(matrix1, matrix2)) {
                tMatrix result;
                result = MatrixSub(matrix1, matrix2);

                MatrixPrint(result);
            } else {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
            }
            break;
        case 3:
            if (PossibleMatrixMultiply(matrix1, matrix2)) {
                tMatrix result;
                result = MatrixMultiply(matrix1, matrix2);

                MatrixPrint(result);
            } else {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
            }
            break;
        case 4:
            int scalar, n;
            scanf("%d %d", &scalar, &n);

            if (n == 1) {
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            } else if (n == 2) {
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }

            break;
        case 5: {
            tMatrix result;
            result = TransposeMatrix(matrix1);
            MatrixPrint(result);

            tMatrix result2;
            result2 = TransposeMatrix(matrix2);
            MatrixPrint(result2);
            break;
        }

        case 6:
            running = 0;
            break;
        }
    }
    return 0;
}