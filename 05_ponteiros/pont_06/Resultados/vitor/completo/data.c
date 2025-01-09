#include <stdio.h>
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData* data) {
    data->dia = dia;
    data->mes = mes;
    data->ano = ano;

    if (data->mes > 12)
        data->mes = 12;
    if (data->dia > InformaQtdDiasNoMes(data))
        data->dia = InformaQtdDiasNoMes(data);
}

void LeData(tData* data) {
    int dia, mes, ano;
    scanf("%d %d %d%*c", &dia, &mes, &ano);

    InicializaDataParam(dia, mes, ano, data);
}

void ImprimeData(tData* data) {
    printf("'%.02d/%.02d/%.04d'", data->dia, data->mes, data->ano);
}

int EhBissexto(tData* data) {
    if ((data->ano % 4) == 0) {
        if (((data->ano % 100) == 0) && ((data->ano % 400) != 0)) {
            return 0;
        }

        return 1;
    }

    return 0;
}

int InformaQtdDiasNoMes(tData* data) {
    switch (data->mes) {
    case 2:
        return 28 + EhBissexto(data);
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    default:
        return 30;
    }
}

void AvancaParaDiaSeguinte(tData* data) {
    data->dia++;

    if (data->dia > InformaQtdDiasNoMes(data)) {
        data->dia = 1;
        data->mes++;
    }

    if (data->mes > 12) {
        data->mes = 1;
        data->ano++;
    }
}

int EhIgual(tData* data1, tData* data2) {
    return data1->dia == data2->dia &&
        data1->mes == data2->mes &&
        data1->ano == data2->ano;
}