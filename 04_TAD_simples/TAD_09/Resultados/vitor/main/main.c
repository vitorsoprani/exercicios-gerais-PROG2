#include <stdio.h>
#include "empresa.h"

int main() {
    int qtdEmpresas;
    scanf("%d\n", &qtdEmpresas);

    tEmpresa empresas[qtdEmpresas];

    for (int i = 0; i < qtdEmpresas; i++) {
        empresas[i] = leEmpresa();
    }

    for (int i = 0; i < qtdEmpresas; i++) {
        imprimeEmpresa(empresas[i]);
    }

    return 0;
}