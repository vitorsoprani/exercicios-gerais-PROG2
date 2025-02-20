#ifndef _tarefagenerica
#define _tarefagenerica

typedef struct tarefagenerica tTarefa;

/**
 * @brief Cria uma variavel do tipo tTarefa (generica);
 *
 * @param prioridade A prioridade da tarefa.
 * @param tarefa Um ponteiro para a tarefa.
 * @param executa A função de xecução da tarefa (callback).
 * @param destroi A função que desaloca a tarefa (callback).
 *
 * @return o ponteiro para a tarefa alocada.
*/
tTarefa* CriaTarefa(int prioridade, void* tarefa, void(*executa)(void*), void(*destroi)(void*));

/**
 * @brief Desaloca a tarefa de acordo com sua função especificada.
 *
 * @param tarefa A tarefa a ser desalocada.
 */
void DestroiTarefa(tTarefa* tarefa);

/**
 * @brief Executa a tarefa de acordo com sua função especificada.
 *
 * @param tarefa A tarefa a ser executada.
 */
void ExecutaTarefa(tTarefa* tarefa);

int GetPrioridadeTarefa(tTarefa* tarefa);

#endif