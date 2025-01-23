#include <stdio.h>
#include "array.h"

int main() {
    Array* arr = CriarArray();
    int elementoBuscado, idx;


    LerArray(arr);
    scanf("%d", &elementoBuscado);

    OrdenarArray(arr);
    idx = BuscaBinariaArray(arr, elementoBuscado);

    if (idx != -1)
        printf("Elemento %d encontrado no índice %d.\n", elementoBuscado, idx);
    else
        printf("Elemento %d não encontrado no array (%d).\n", elementoBuscado, idx);

    DestruirArray(arr);
    return 0;
}