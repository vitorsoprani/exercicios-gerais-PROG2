#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void ERRO(char* nomeFunc, char* descricaoErro) {
    printf("[ERRO] - Na funcao %s.\n\t%s", nomeFunc, descricaoErro);
    exit(1);
}