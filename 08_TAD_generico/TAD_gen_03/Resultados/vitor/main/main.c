#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "aluno.h"

int main() {
    Vector* v = VectorConstruct();
    tAluno* a;
    int qtdAlunos;
    scanf("%d%*c", &qtdAlunos);

    for (int i = 0; i < qtdAlunos; i++) {
        a = CriaAluno();
        LeAluno(a);

        VectorPushBack(v, a);
    }

    ImprimeRelatorio(v);

    VectorDestroy(v, DestroiAluno);

    return 0;
}