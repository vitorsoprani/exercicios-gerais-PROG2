#include <stdio.h>
#include <string.h>

int palindromo(char* string, int tamanho);

int main() {
    char str[100];

    while (scanf("%99s", str) == 1) {
        if (palindromo(str, (int)strlen(str))) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}

int palindromo(char* string, int tamanho) {
    if (tamanho < 1) return 1;

    if (string[0] != string[tamanho - 1]) return 0;

    return palindromo(string + 1, tamanho - 2);
}