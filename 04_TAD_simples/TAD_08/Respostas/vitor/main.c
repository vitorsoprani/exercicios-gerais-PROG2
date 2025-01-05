#include <stdio.h>
#include "departamento.h"

int main() { 
    int qtdDepto;
    scanf("%d%*c", &qtdDepto);
    tDepartamento deptos[qtdDepto];

    for (int i = 0; i < qtdDepto; i++) {
        char nome[STRING_MAX], diretor[STRING_MAX];
        char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
        int m1, m2, m3;

        scanf("%s%*c", nome);
        scanf("%s%*c", diretor);
        
        scanf("%s%*c", c1);
        scanf("%s%*c", c2);
        scanf("%s%*c", c3);

        scanf("%d %d %d%*c", &m1, &m2, &m3);

        deptos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(deptos, qtdDepto);

    for (int i = 0; i < qtdDepto; i++) {
        imprimeAtributosDepartamento(deptos[i]);
        printf("\n");
    }

    return 0;
} 