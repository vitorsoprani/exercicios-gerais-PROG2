#include <stdio.h>
#include <string.h>
#include <math.h>
#include "departamento.h"

tDepartamento criaDepartamento(char* c1, char* c2, char* c3, char* nome, int m1, int m2, int m3, char* diretor) {
    tDepartamento depto;

    strcpy(depto.c1, c1);
    strcpy(depto.c2, c2);
    strcpy(depto.c3, c3);

    strcpy(depto.nome, nome);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    strcpy(depto.diretor, diretor);

    depto.media_geral = calculaMediaGeralDepartamento(depto);

    return depto;
}

void imprimeAtributosDepartamento(tDepartamento depto) {
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2lf\n", depto.media_geral);
    printf("desvio padrao => %.2lf\n", calculaDesvioPadraoDepartamento(depto));
}

int validaMediaDepartamento(int media) {
    return media <= 10 && media >= 0;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto) {
    double soma = 0;
    double desvioPadrao = 0;

    soma += pow((depto.m1 - depto.media_geral), 2);
    soma += pow((depto.m2 - depto.media_geral), 2);
    soma += pow((depto.m3 - depto.media_geral), 2);

    return sqrt(soma / 3);
}

double calculaMediaGeralDepartamento(tDepartamento depto) {
    return ((double)depto.m1 + (double)depto.m2 + (double)depto.m3) / (double)3;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (d[j].media_geral < d[j + 1].media_geral) {
                tDepartamento aux = d[j];
                d[j] = d[j + 1];
                d[j + 1] = aux;
            }
        }
    }
}