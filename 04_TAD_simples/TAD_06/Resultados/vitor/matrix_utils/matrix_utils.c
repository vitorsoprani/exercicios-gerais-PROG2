#include <stdio.h>
#include "matrix_utils.h"

tMatrix MatrixCreate(int rows, int cols) {
    tMatrix matrix;

    matrix.rows = rows;
    matrix.cols = cols;

    return matrix;
}

tMatrix MatrixRead(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            scanf("%d", &matrix.data[i][j]);
        }
        scanf("%*c");
    }

    return matrix;
}

void MatrixPrint(tMatrix matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        printf("|");
        for (int j = 0; j < matrix.cols - 1; j++) {
            printf("%d ", matrix.data[i][j]);
        }
        printf("%d|\n", matrix.data[i][matrix.cols - 1]);
    }
    printf("\n");
}

int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2) {
    return (matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols);
}

int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2) {
    return (matrix1.rows == matrix2.rows) && (matrix1.cols == matrix2.cols);
}

int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    return matrix1.cols == matrix2.rows;
}

tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);

    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }

    return result;
}

tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix1.cols);

    for (int i = 0; i < matrix1.rows; i++) {
        for (int j = 0; j < matrix1.cols; j++) {
            result.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }

    return result;
}


tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2) {
    tMatrix result = MatrixCreate(matrix1.rows, matrix2.cols);

    for (int i = 0; i < matrix2.cols; i++) {
        for (int j = 0; j < matrix1.rows; j++) {
            int soma = 0;

            for (int k = 0; k < matrix1.cols; k++) {
                soma += matrix1.data[j][k] * matrix2.data[k][i];
            }

            result.data[j][i] = soma;
        }
    }

    return result;
}

tMatrix TransposeMatrix(tMatrix matrix) {
    tMatrix result = MatrixCreate(matrix.cols, matrix.rows);

    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            result.data[j][i] = matrix.data[i][j];
        }
    }

    return result;
}

tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            matrix.data[i][j] = matrix.data[i][j] * scalar;
        }
    }

    return matrix;
}