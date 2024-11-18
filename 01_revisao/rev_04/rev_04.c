#include <stdio.h>

int main() {
    int nDecimal;
    scanf("%d", &nDecimal);

    int nOctal[6]; //um número armazenado em uma variavel do tipo int jamais terá mais de 5 digitos

    int qtdDigitos = 0;
    while (nDecimal != 0) {
        nOctal[qtdDigitos] = nDecimal % 8;
        nDecimal /= 8;
        qtdDigitos++;
    }

    for (int i = 0; i < qtdDigitos; i++) {
        printf("%d", nOctal[qtdDigitos - i - 1]);
    }
    return 0;
}