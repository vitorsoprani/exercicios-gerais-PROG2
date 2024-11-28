#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
    int dia, mes, ano;
    scanf("%02d/%02d/%04d", &dia, &mes, &ano);

    if (!verificaDataValida(dia, mes, ano)) {
        printf("A data informada eh invalida");
        exit(1);
    }

    printf("Data informada: ");
    imprimeDataExtenso(dia, mes, ano);

    printf("O ano informado ");
    if (verificaBissexto(ano)) {
        printf("eh ");
    } else {
        printf("nao eh ");
    }
    printf("bissexto\n");

    printf("O mes informado possui %d dias\n", numeroDiasMes(mes, ano));

    printf("A data seguinte eh: ");
    imprimeProximaData(dia, mes, ano);

    return 0;
}