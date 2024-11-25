#include <stdio.h>
#include "matrix_utils.h"

int main() {
    int rows1, cols1, rows2, cols2;
    scanf("%d %d", &rows1, &cols1);

    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);


    scanf("%d %d", &rows2, &cols2);

    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    matrix_print(rows1, cols1, matrix1);
    printf("\nmultiplicando com:\n\n");
    matrix_print(rows2, cols2, matrix2);
    printf("\n");

    int result[rows1][cols2];

    matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);

    matrix_print(rows1, cols1, result);

    return 0;
}