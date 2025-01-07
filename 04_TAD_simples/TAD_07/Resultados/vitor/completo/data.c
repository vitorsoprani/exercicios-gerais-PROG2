#include <stdio.h>
#include <stdlib.h>
#include "data.h"

tData CriaData(int dia, int mes, int ano) {
    tData data;

    data.dia = dia;
    data.mes = mes;
    data.ano = ano;

    if (!VerificaDataValida(data)) {
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
        exit(1);
    }

    return data;
}

int VerificaDataValida(tData data) {
    if (data.mes < 1 || data.mes > 12) return 0;
    if (data.dia < 1 || data.dia > NumeroDiasMes(data)) return 0;
    return 1;
}

void ImprimeMesExtenso(tData data) {
    switch (data.mes) {
    case 1: {
        printf("Janeiro");
        break;
    }
    case 2: {
        printf("Fevereiro");
        break;
    }
    case 3: {
        printf("Marco");
        break;
    }
    case 4: {
        printf("Abril");
        break;
    }
    case 5: {
        printf("Maio");
        break;
    }
    case 6: {
        printf("Junho");
        break;
    }
    case 7: {
        printf("Julho");
        break;
    }
    case 8: {
        printf("Agosto");
        break;
    }
    case 9: {
        printf("Setembro");
        break;
    }
    case 10: {
        printf("Outubro");
        break;
    }
    case 11: {
        printf("Novembro");
        break;
    }
    case 12: {
        printf("Dezembro");
        break;
    }
    }
}

void ImprimeDataExtenso(tData data) {
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %d\n", data.ano);
}

int VerificaBissexto(tData data) {
    if (data.ano % 400 == 0)
        return 1;
    else if (data.ano % 4 == 0 && data.ano % 100 != 0)
        return 1;
    else
        return 0;
}

int NumeroDiasMes(tData data) {
    if (data.mes == 2) {
        if (VerificaBissexto(data)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (data.mes == 1 ||
        data.mes == 3 ||
        data.mes == 5 ||
        data.mes == 7 ||
        data.mes == 8 ||
        data.mes == 10 ||
        data.mes == 12) {
        return 31;
    }
    return 30;
}

int ComparaData(tData data1, tData data2) {
    if (data1.ano > data2.ano) {
        return 1;
    } else if (data1.ano < data2.ano) {
        return -1;
    } else if (data1.mes > data2.mes) {
        return 1;
    } else if (data1.mes < data2.mes) {
        return -1;
    } else if (data1.dia > data2.dia) {
        return 1;
    } else if (data1.dia < data2.dia) {
        return -1;
    } else {
        return 0;
    }
}


int CalculaDiasAteMes(tData data) {
    int qtdDias = 0;

    for (int i = 1; i < data.mes; i++) {
        qtdDias += NumeroDiasMes(CriaData(1, i, data.ano));
    }

    return qtdDias;
}

int CalculaDiferencaDias(tData data1, tData data2) {
    if (ComparaData(data1, data2) == 1) {
        // A DATA 2 É MAIS ANTIGA QUE A DATA 1;
        return CalculaDiferencaDias(data2, data1);
    } else if (ComparaData(data1, data2) == 0) {
        return 0;
    }

    int qtdDias = 0;

    for (int i = data1.ano; i < data2.ano; i++) {
        if (VerificaBissexto(CriaData(1, 1, i))) {
            qtdDias += 366;
        } else {
            qtdDias += 365;
        }
    }

    qtdDias += (CalculaDiasAteMes(data2) + data2.dia) - (CalculaDiasAteMes(data1) + data1.dia);


    return qtdDias;
}