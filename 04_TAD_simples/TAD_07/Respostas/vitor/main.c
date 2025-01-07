#include <stdio.h>
#include <stdlib.h>
#include "data.h"

int main() {
    int dia, mes, ano;

    scanf("%2d/%2d/%4d%*c", &dia, &mes, &ano);
    tData data1 = CriaData(dia, mes, ano);

    scanf("%2d/%2d/%4d%*c", &dia, &mes, &ano);
    tData data2 = CriaData(dia, mes, ano);

    if (!VerificaDataValida(data1) || !VerificaDataValida(data2)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(1);
    }


    printf("Primeira data: ");
    ImprimeDataExtenso(data1);

    printf("Segunda data: ");
    ImprimeDataExtenso(data2);

    switch (ComparaData(data1, data2)) {
    case 1:
        printf("A segunda data eh mais antiga\n");
        break;
    case -1:
        printf("A primeira data eh mais antiga\n");
        break;
    case 0:
        printf("As datas sao iguais\n");
        break;
    }

    printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));

    return 0;
}