#include <stdio.h>

int main() {
    int numLinhas;
    scanf("%d", &numLinhas);

    int numAtual = 1;
    for (int i = 1; i <= numLinhas; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", numAtual);
            numAtual++;
        }
        printf("\n");
    }

    return 0;
}