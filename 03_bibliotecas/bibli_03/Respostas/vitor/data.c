#include "data.h"
#include<stdio.h>



int verificaDataValida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12) return 0;
    if (dia < 1 || dia > numeroDiasMes(mes, ano)) return 0;
    return 1;
}

void imprimeMesExtenso(int mes) {
    switch (mes) {
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

void imprimeDataExtenso(int dia, int mes, int ano) {
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %d\n", ano);
}

int verificaBissexto(int ano) {
    if (ano % 400 == 0)
        return 1;
    else if (ano % 4 == 0 && ano % 100 != 0)
        return 1;
    else
        return 0;
}

int numeroDiasMes(int mes, int ano) {
    if (mes == 2) {
        if (verificaBissexto(ano)) {
            return 29;
        } else {
            return 28;
        }
    }
    if (mes == 1 ||
        mes == 3 ||
        mes == 5 ||
        mes == 7 ||
        mes == 8 ||
        mes == 10 ||
        mes == 12) {
        return 31;
    }
    return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (ano1 > ano2) {
        return 1;
    } else if (ano1 < ano2) {
        return -1;
    } else if (mes1 > mes2) {
        return 1;
    } else if (mes1 < mes2) {
        return -1;
    } else if (dia1 > dia2) {
        return 1;
    } else if (dia1 < dia2) {
        return -1;
    } else {
        return 0;
    }
}

int calculaDiasAteMes(int mes, int ano) {
    int qtdDias = 0;

    for (int i = 1; i < mes; i++) {
        qtdDias += numeroDiasMes(i, ano);
    }

    return qtdDias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2) {
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1) {
        // A DATA 2 É MAIS ANTIGA QUE A DATA 1;
        return calculaDiferencaDias(dia2, mes2, ano2, dia1, mes1, ano1);
    } else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0) {
        return 0;

    }

    int qtdDias = 0;

    for (int i = ano1; i < ano2; i++) {
        qtdDias += calculaDiasAteMes(12, i) + numeroDiasMes(12, i);
    }

    qtdDias += (calculaDiasAteMes(mes2, ano2) + dia2) - (calculaDiasAteMes(mes1, ano1) + dia1);


    return qtdDias;
}