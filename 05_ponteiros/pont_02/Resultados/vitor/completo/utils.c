#include <stdio.h>
#include "utils.h"

void LeIntervalo(int* m, int* n) {
    scanf("%d %d\n", m, n);
}

int EhPrimo(int n) {
    for (int i = 2; i <= ((float)n / 2); i++) {
        if ((n % i) == 0)
            return 0;
    }

    return n != 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int* menor, int* maior) {
    *menor = n;
    *maior = m;
    for (int i = m; i <= n; i++) {
        if (EhPrimo(i)) {
            if (i < *menor)
                *menor = i;

            if (i > *maior)
                *maior = i;
        }
    }
}
