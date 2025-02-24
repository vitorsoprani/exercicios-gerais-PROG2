#include <stdio.h>
#include <string.h>
#include "fila.h"
#include "movel.h"

int main() {
    int qtdOperacoes = 0;
    Fila* f = FilaConstruct();
    
    scanf("%d%*c", &qtdOperacoes);

    char op[10];

    for (int i = 0; i < qtdOperacoes; i++) {
        scanf("%s", op);
        
        if (strcmp(op, "ENTRADA") == 0) {
            tMovel* m = LeMovel();
            FilaPush(f, m);   
        } else if (strcmp(op, "PRODUZIR") == 0) {
            tMovel* m = (tMovel*)FilaPop(f);
            ImprimeMovel(m);
            DestroiMovel(m);
        } else {
            i--;
        }
    }


    FilaDestroy(f, DestroiMovel);
    return 0;
}