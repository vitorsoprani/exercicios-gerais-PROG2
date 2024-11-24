#include <stdio.h>
#define TAM_MAX_STR 1001 //1000 caracteres e o '\0' no final

// Função recursiva que imprime a string de forma invertida.
void ImprimeInvertido(char* string);

int main() {
    char str[TAM_MAX_STR];
    while (scanf("%1000s", str) == 1) {
        ImprimeInvertido(str);
        printf(" ");
    }
}

void ImprimeInvertido(char* string) {
    if (string[0] == '\0') {
        return;
    }

    ImprimeInvertido(string + 1);

    printf("%c", string[0]);
}