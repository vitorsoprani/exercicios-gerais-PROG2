#include <stdio.h>

#include "aluno.h"
#include "base_alunos.h"

int main() {
    tBaseAlunos* base = CriarBaseAlunos();
    char nomeArquivo[100];

    scanf("%[^\n]%*c", nomeArquivo);

    LerBaseAlunos(base, nomeArquivo);

    printf("Coeficiente de Rendimento Medio da base de alunos: %.2f\n", GetCoeficienteRendimentoMedioBaseAlunos(base));

    DestruirBaseAlunos(base);

    return 0;
}