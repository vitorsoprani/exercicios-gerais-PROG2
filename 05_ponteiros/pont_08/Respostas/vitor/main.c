#include <stdio.h>
#include "tDepartamento.h"

int main() {
    int qtdDeptos, deptosCadastrados = 0;
    scanf("%d%*c", &qtdDeptos);

    tDepartamento deptos[qtdDeptos];


    while (deptosCadastrados < qtdDeptos) {
        char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], nome[STRING_MAX], diretor[STRING_MAX];
        int m1, m2, m3;

        scanf("%s%*c%s%*c", nome, diretor);
        scanf("%s%*c%s%*c%s%*c", curso1, curso2, curso3);
        scanf("%d %d %d%*c", &m1, &m2, &m3);

        if (m1 < 0 || m2 < 0 || m3 < 0 || m1 > 10 || m2 > 10 || m3 > 10) {
            printf("\nDigite um departamento com médias válidas");
        } else {
            deptos[deptosCadastrados] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
            deptosCadastrados++;
        }
    }

    OrdenaDepartamentosPorMedia(deptos, qtdDeptos);

    for (int i = 0; i < qtdDeptos; i++) {
        ImprimeAtributosDepartamento(deptos[i]);
    }

    return 0;
}