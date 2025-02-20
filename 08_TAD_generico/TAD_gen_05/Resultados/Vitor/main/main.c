#include <stdio.h>

#include "agendatarefas.h"
#include "tarefaimprime.h"
#include "tarefasoma.h"
#include "tarefamultiplica.h"

int main() {
    int qtdTarefas;
    printf("Digite o numero de tarefas: ");
    scanf("%d%*c", &qtdTarefas);

    tAgendaTarefas* tar = CriaAgendaDeTarefas(qtdTarefas);

    for (int i = 0; i < qtdTarefas; i++) {
        int prioridade;
        char tipoTarefa;

        scanf("%d %c%*c", &prioridade, &tipoTarefa);

        if (tipoTarefa == 'I') {
            char msg[100];
            scanf("%[^\n]%*c", msg);

            tImpr* t = CriaTarefaImprimir(msg);
            CadastraTarefaNaAgenda(tar, prioridade, t, ExecutaTarefaImprimir, DestroiTarefaImprimir);
        } else if (tipoTarefa == 'M') {
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);

            tMult* t = CriaTarefaMultiplicar(n1, n2);
            CadastraTarefaNaAgenda(tar, prioridade, t, ExecutaTarefaMultiplicar, DestroiTarefaMultiplicar);
        } else if (tipoTarefa == 'S') {
            float n1, n2;
            scanf("%f %f%*c", &n1, &n2);

            tSoma* t = CriaTarefaSoma(n1, n2);
            CadastraTarefaNaAgenda(tar, prioridade, t, ExecutaTarefaSoma, DestroiTarefaSoma);
        } else {
            printf("\nDigite um tipo de tarefa suportado (I/S/M))");
            scanf("%*[^0-9]");
            i--;
        }
    }

    ExecutarTarefasDaAgenda(tar);

    DestroiAgendaDeTarefas(tar);

    return 0;
}