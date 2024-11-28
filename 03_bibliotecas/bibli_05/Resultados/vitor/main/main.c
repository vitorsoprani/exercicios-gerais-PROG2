#include <stdio.h>
#include "string_utils.h"

#define TAM_MAX 100

int main() {
    char str[TAM_MAX];
    scanf("%100[^\n]", str);

    while (1) {
        int opcao = 0;
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 1) {
            printf("Tamanho da string: %d\n\n", string_length(str));
        } else if (opcao == 2) {
            char str2[TAM_MAX];
            string_copy(str, str2);
            printf("String copiada: %s\n\n", str2);
        } else if (opcao == 3) {
            string_upper(str);
            printf("String convertida para maiusculas: %s\n\n", str);
        } else if (opcao == 4) {
            string_lower(str);
            printf("String convertida para minusculas: %s\n\n", str);
        } else if (opcao == 5) {
            string_reverse(str);
            printf("String invertida: %s\n\n", str);
        } else if (opcao == 6) {
            break;
        } else {
            printf("Opcao  invalida\n\n");
        }
    }

    return 0;
}