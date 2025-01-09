#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

float CalculaMedia(tDepartamento depto) {
    return (float)(depto.m1 + depto.m2 + depto.m3) / 3.0;
}

tDepartamento CriaDepartamento(char* curso1, char* curso2, char* curso3, char* nome, int m1, int m2, int m3, char* diretor) {
    tDepartamento depto;

    strcpy(depto.curso1, curso1);
    strcpy(depto.curso2, curso2);
    strcpy(depto.curso3, curso3);

    strcpy(depto.nome, nome);

    strcpy(depto.diretor, diretor);

    depto.m1 = m1;
    depto.m2 = m2;
    depto.m3 = m3;

    return depto;
}

void ImprimeAtributosDepartamento(tDepartamento depto) {
    printf("\nDepartamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);
    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);
    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);
    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);
    printf("\tMedia dos cursos: %.2f", CalculaMedia(depto));
}

void OrdenaDepartamentosPorMedia(tDepartamento* vetor_deptos, int num_deptos) {
    for (int i = 0; i < num_deptos - 1; i++) {
        for (int j = i; j < num_deptos - i - 1; j++) {
            if (CalculaMedia(vetor_deptos[j]) < CalculaMedia(vetor_deptos[j])) {
                tDepartamento aux = vetor_deptos[j];
                vetor_deptos[j] = vetor_deptos[j + 1];
                vetor_deptos[j + 1] = aux;
            }
        }
    }
}