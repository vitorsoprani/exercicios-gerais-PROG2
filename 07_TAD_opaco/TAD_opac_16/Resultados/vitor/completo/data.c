#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"

struct Data {
    int diaDaSemana;
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
};


tData* CriaData() {
    tData* data = (tData*)malloc(sizeof(tData));
    assert(data != NULL);

    data->diaDaSemana = -1;
    data->dia = -1;
    data->mes = -1;
    data->ano = -1;
    data->hora = -1;
    data->minuto = -1;

    return data;
}

void DestroiData(tData* data) {
    if (data != NULL)
        free(data);
}

void ProcessaDiaMesAno(tData* data, char* str) {
    assert(data != NULL);

    sscanf(str, "%d/%d/%d", &data->dia, &data->mes, &data->ano);
}

void ProcessaDiaDaSemana(tData* data, char* str) {
    assert(data != NULL);

    sscanf(str, "%d", &data->diaDaSemana);
}

void ProcessaHorario(tData* data, char* str) {
    assert(data != NULL);

    sscanf(str, "%d:%d", &data->hora, &data->minuto);
}

int VerificaDataValida(tData* data) {
    assert(data != NULL);

    if (data->mes < 1 || data->mes > 12) return 0;
    if (data->dia < 1 || data->dia > NumeroDiasMes(data)) return 0;
    return 1;
}

int VerificaBissexto(tData* data) {
    assert(data != NULL);

    if (data->ano % 400 == 0)
        return 1;
    else if (data->ano % 4 == 0 && data->ano % 100 != 0)
        return 1;
    else
        return 0;
}

int NumeroDiasMes(tData* data) {
    assert(data != NULL);

    if (data->mes == 2) {
        if (VerificaBissexto(data)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (data->mes == 1 ||
        data->mes == 3 ||
        data->mes == 5 ||
        data->mes == 7 ||
        data->mes == 8 ||
        data->mes == 10 ||
        data->mes == 12) {
        return 31;
    }
    return 30;
}

int ComparaDiaMesAno(tData* data1, tData* data2) {
    assert(data1 != NULL);
    assert(data2 != NULL);

    if (data1->ano > data2->ano) {
        return 1;
    } else if (data1->ano < data2->ano) {
        return -1;
    } else if (data1->mes > data2->mes) {
        return 1;
    } else if (data1->mes < data2->mes) {
        return -1;
    } else if (data1->dia > data2->dia) {
        return 1;
    } else if (data1->dia < data2->dia) {
        return -1;
    } else {
        return 0;
    }
}

int CalculaDiasAteMes(tData* data) {
    assert(data != NULL);

    int qtdDias = 0;

    for (int i = 1; i < data->mes; i++) {
        qtdDias += NumeroDiasMes(CriaData(1, i, data->ano));
    }

    return qtdDias;
}

int CalculaDiferencaDias(tData* data1, tData* data2) {
    assert(data1 != NULL);
    assert(data2 != NULL);

    if (ComparaDiaMesAno(data1, data2) == 1) {
        // A DATA 2 É MAIS ANTIGA QUE A DATA 1;
        return CalculaDiferencaDias(data2, data1);
    } else if (ComparaDiaMesAno(data1, data2) == 0) {
        return 0;
    }

    int qtdDias = 0;

    for (int i = data1->ano; i < data2->ano; i++) {
        if (VerificaBissexto(CriaData(1, 1, i))) {
            qtdDias += 366;
        } else {
            qtdDias += 365;
        }
    }

    qtdDias += (CalculaDiasAteMes(data2) + data2->dia) - (CalculaDiasAteMes(data1) + data1->dia);


    return qtdDias;
}

float CalculaHorasEntreDatas(tData* data1, tData* data2) {
    // assert(data1 != NULL);
    // assert(data2 != NULL);


    int qtdHoras = CalculaDiferencaDias(data1, data2) * 24;
    // int qtdHoras = 0;
    qtdHoras += data2->hora - data1->hora;
    qtdHoras += (float)(data2->minuto - data1->minuto) / 60.0;

    return qtdHoras;
}

int DataEhSabadoOuDomingo(tData* data) {
    assert(data != NULL);

    return data->diaDaSemana == 0 || data->diaDaSemana == 6;
}

void DataDiaSeguinte(tData* data) {
    assert(data != NULL);

    data->dia++;

    if (data->dia > NumeroDiasMes(data)) {
        data->mes++;
        data->dia = 0;

        if (data->mes > 12) {
            data->mes = 1;
            data->ano++;
        }
    }

    data->diaDaSemana = (data->diaDaSemana + 1) % 7;
}

void CopiaDiaMesAno(tData* src, tData* tgt) {
    assert(src != NULL);
    assert(tgt != NULL);

    tgt->dia = src->dia;
    tgt->mes = src->mes;
    tgt->ano = src->ano;
}