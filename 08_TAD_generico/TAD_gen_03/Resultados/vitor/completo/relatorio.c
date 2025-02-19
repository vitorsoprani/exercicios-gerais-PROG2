#include <stdio.h>
#include "relatorio.h"
#include "aluno.h"


void ImprimeRelatorio(Vector* alunos) {
    float mediaNota = 0;
    int totalMasc = 0;
    int totalFem = 0;
    int totalOutros = 0;
    int totalAlunos = VectorSize(alunos);
    int totalAprovados = 0;

    for (int i = 0; i < totalAlunos; i++) {
        tAluno* a = (tAluno*)VectorGet(alunos, i);
        if (GetNotaAluno(a) >= 6) {
            totalAprovados++;
        }

        if (GetGeneroAluno(a) == 'F') {
            totalFem++;
        } else if ((GetGeneroAluno(a) == 'M')) {
            totalMasc++;
        } else if ((GetGeneroAluno(a) == 'O')) {
            totalOutros++;
        }

        mediaNota += GetNotaAluno(a) / totalAlunos;
    }

    printf("Media das notas: %.2f\n", mediaNota);
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (float)totalAprovados / (float)totalAlunos * 100.0);
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n", (float)totalMasc / (float)totalAlunos * 100.0);
    printf("Feminino: %.2f%%\n", (float)totalFem / (float)totalAlunos * 100.0);
    printf("Outro: %.2f%%\n", (float)totalOutros / (float)totalAlunos * 100.0);
}