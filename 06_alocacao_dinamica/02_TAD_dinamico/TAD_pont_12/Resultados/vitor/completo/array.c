#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

Array* CriarArray() {
    Array* array = (Array*)malloc(sizeof(Array));

    assert(array != NULL);

    array->data = NULL;
    array->tamanho = 0;

    return array;
}

void DestruirArray(Array* array) {
    assert(array != NULL);

    if (array->data != NULL)
        free(array->data);

    free(array);
}

void LerArray(Array* array) {
    assert(array != NULL);

    array->data = (int*)malloc(0); //alocando um vetor vazio para usar o realloc posteriormente.

    int n;
    char c;

    while (1) {
        scanf("%d%c", &n, &c);

        array->tamanho++;
        array->data = (int*)realloc(array->data, array->tamanho * sizeof(int));

        assert(array->data != NULL);

        array->data[(array->tamanho) - 1] = n;

        if (c == '.') {
            scanf("%*c"); //limpando o \n do buffer
            break;
        }
    }
}

void OrdenarArray(Array* array) {
    assert(array != NULL);
    assert(array->data != NULL);

    for (int i = 0; i < array->tamanho - 1; i++) {
        for (int j = 0; j < array->tamanho - i - 1; j++) {
            if (array->data[j] > array->data[j + 1]) {
                int aux = array->data[j];
                array->data[j] = array->data[j + 1];
                array->data[j + 1] = aux;
            }
        }
    }
}

int BuscaBinariaArray(Array* array, int elementoBuscado) {
    assert(array != NULL);
    assert(array->data != NULL);

    int n = array->tamanho / 2;
    int idx = n;

    while ((array->data[idx] != elementoBuscado) && n > 0) {
        n = n / 2;
        if (array->data[idx] < elementoBuscado)
            idx += n;
        else
            idx -= n;
    }

    if (array->data[idx] == elementoBuscado)
        return idx;

    return -1;
}