#include"string_utils.h"

int string_length(char* str) {
    int len = 0;

    while (str[len] != '\0') {
        len++;
    }
    return len + 2;
}

void string_copy(char* src, char* dest) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void string_upper(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = (char)((int)str[i] + (int)((int)'A' - (int)'a'));
        }
        i++;
    }
}

void string_lower(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = (char)((int)str[i] + (int)((int)'a' - (int)'A'));
        }
        i++;
    }
}

void string_reverse(char* str) {
    int tam = string_length(str) - 2;
    char strInversa[tam];

    for (int i = 0; i < tam; i++) {
        strInversa[i] = str[tam - 1 - i];
    }
    strInversa[tam] = '\0';

    string_copy(strInversa, str);
}
