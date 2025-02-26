#include <stdio.h>
#include <stdlib.h>

#include "matrizgenerica.h"
#include "numcomplexo.h"
#include "operacoesprimitivos.h"


//  TIPOS:
#define INT         0
#define FLOAT       1
#define DOUBLE      2
#define CHAR        3
#define COMPLEXO    4

//  OPERACOES:
#define IMPRIMIR            1
#define CVT_E_IMPRIMIR      2
#define CVT_E_MULTIPLICAR   3

//  OPCOES FECHAMENTO:
#define NOVA_MATRIZ 1
#define FECHAR      2

int main() {
    int numLinhas, numColunas, tipo, opt;

    while (1) {
        printf("Digite o número de linhas, colunas e o tipo da matriz (0 – inteiro, 1 – float, 2 – double, 3 – char, 4 – número complexo): ");
        scanf("%d %d %d%*c", &numLinhas, &numColunas, &tipo);

        tMatrizGenerica* mat;
        
        if (tipo == INT) {
            mat = CriaMatrizGenerica(numLinhas, numColunas, sizeof(int)); 
        } else if (tipo == FLOAT) {
            mat = CriaMatrizGenerica(numLinhas, numColunas, sizeof(float));
        } else if (tipo == DOUBLE) {
            mat = CriaMatrizGenerica(numLinhas, numColunas, sizeof(double));
        } else if (tipo == CHAR) {
            mat = CriaMatrizGenerica(numLinhas, numColunas, sizeof(char));
        } else if (tipo == COMPLEXO) {
            mat = CriaMatrizGenerica(numLinhas, numColunas, RetornaNumBytesComplexo());
        } else {
            continue;
        }
        
        for (int i = 0; i < numLinhas; i++) {
            for (int j = 0; j < numColunas; j++) {
                if (tipo == INT) {
                    int n;
                    scanf("%d%*c", &n);
                    AtribuiElementoMatrizGenerica(mat, i, j, &n);
                } else if (tipo == FLOAT) {
                    float n;
                    scanf("%f%*c", &n);
                    AtribuiElementoMatrizGenerica(mat, i, j, &n);
                } else if (tipo == DOUBLE) {
                    double n;
                    scanf("%lf%*c", &n);
                    AtribuiElementoMatrizGenerica(mat, i, j, &n);
                } else if (tipo == CHAR) {
                    char c;
                    scanf("%c%*c", &c);
                    AtribuiElementoMatrizGenerica(mat, i, j, &c);
                } else if (tipo == COMPLEXO) {
                    float real, imag;
                    scanf("(%f,%f)%*c", &real, &imag);
                    tNumComplexo* n = CriaNumComplexo(real, imag);
                    AtribuiElementoMatrizGenerica(mat, i, j, &n);
                    DestroiNumeroComplexo(n);
                }
            }   
        }

        printf("Digite a operação desejada\n");
        printf("\t1 - Apenas imprimir a matriz\n");
        printf("\t2 - Converter para o tipo complexo e imprimir\n");
        printf("\t3 - Calcular e imprimir a multiplicacao da matriz pela sua transposta.\n");

        scanf("%d%*c", &opt);

        if (opt == IMPRIMIR) {
            if (tipo == INT) {
                ImprimirMatrizGenerica(mat, ImprimeInt);
            } else if (tipo == FLOAT) {
                ImprimirMatrizGenerica(mat, ImprimeFloat);
            } else if (tipo == DOUBLE) {
                ImprimirMatrizGenerica(mat, ImprimeDouble);
            } else if (tipo == CHAR) {
                ImprimirMatrizGenerica(mat, ImprimeChar);
            } else if (tipo == COMPLEXO) {
                // ImprimirMatrizGenerica(mat, ImprimeNumeroComplexo);
            } 
        } else if (opt == CVT_E_IMPRIMIR) {
            if (tipo == INT) {
            } else if (tipo == FLOAT) {
            } else if (tipo == DOUBLE) {
            } else if (tipo == CHAR) {
            } else if (tipo == COMPLEXO) {
            } 
        } else if (opt == CVT_E_MULTIPLICAR) {
            if (tipo == INT) {
            } else if (tipo == FLOAT) {
            } else if (tipo == DOUBLE) {
            } else if (tipo == CHAR) {
            } else if (tipo == COMPLEXO) {
            } 
        } else {
            //TRATAMENTO DE ERRO
            continue;
        }

        printf("Digite a operacao desejada\n");
        printf("\t1 - Entrar com uma nova matriz\n");
        printf("\t2 - Encerrar o programa\n");
       
        scanf("%d%*c", &opt);
        
        if (opt == 1)
            continue;
        else
            break;    
    }
    

    return 0;
}