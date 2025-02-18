#include <stdio.h>
#include "tadgen.h"

int main() {
    int qtdElementos, t;
    Type tipo;
    scanf("%d ", &t);

    if (t == 1) {
        tipo = INT;
    } else if (t == 0) {
        tipo = FLOAT;
    }

    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos: ");
    scanf("%d%*c", &qtdElementos);

    tGeneric* vetor = CriaGenerico(tipo, qtdElementos);
    LeGenerico(vetor);
    ImprimeGenerico(vetor);

    DestroiGenerico(vetor);

    return 0;
}