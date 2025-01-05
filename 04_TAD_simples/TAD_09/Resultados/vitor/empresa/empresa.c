#include <stdio.h>
#include "empresa.h"

tEmpresa criaEmpresa(int id) {
    tEmpresa empresa;

    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa() {
    int id, qtdFuncionarios;
    tEmpresa empresa;

    scanf("%d %d\n", &id, &qtdFuncionarios);
    empresa = criaEmpresa(id);


    for (int i = 0; i < qtdFuncionarios; i++) {
        tFuncionario funcionario;
        funcionario = leFuncionario();
        empresa = contrataFuncionarioEmpresa(empresa, funcionario);
    }

    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario) {
    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        if (getIdFuncionario(empresa.funcionarios[i]) == getIdFuncionario(funcionario)) {
            printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, getIdFuncionario(funcionario));

            return empresa;
        }
    }

    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa) {
    printf("Empresa %d:\n", empresa.id);

    for (int i = 0; i < empresa.qtdFuncionarios; i++) {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}