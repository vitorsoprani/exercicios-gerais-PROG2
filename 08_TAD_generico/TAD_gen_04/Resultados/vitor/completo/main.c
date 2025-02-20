#include <stdio.h>
#include "banco.h"

#define AGENCIA 'A'
#define CONTA   'C'
#define FIM     'F'

int main() {
    tBanco* banco = CriaBanco();
    LeBanco(banco);

    char opt = 0;

    while (1) {
        scanf("%c", &opt);

        if (opt == '\n') continue;

        if (opt == AGENCIA) {
            tAgencia* a = CriaAgencia();
            LeAgencia(a);

            AdicionaAgencia(banco, a);
        } else if (opt == CONTA) {
            tConta* c = CriaConta();
            int numAgencia = 0;

            LeConta(c);
            scanf("%*[\n]");
            scanf("%d%*c", &numAgencia);

            InsereContaBanco(banco, numAgencia, c);
        } else if (opt == FIM) {
            break;
        }
    }

    ImprimeRelatorioBanco(banco);

    DestroiBanco(banco);
    return 0;
}