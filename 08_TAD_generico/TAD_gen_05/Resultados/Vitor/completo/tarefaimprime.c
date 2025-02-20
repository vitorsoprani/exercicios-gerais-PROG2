#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "tarefaimprime.h"

#define cast(x) ((tImpr*)x)

struct impr {
    char* msg;
};

tImpr* CriaTarefaImprimir(char* msg) {
    tImpr* imp = (tImpr*)malloc(sizeof(tImpr));
    assert(imp != NULL);

    imp->msg = (char*)malloc(sizeof(char) * strlen(msg) + 1);
    assert(imp->msg != NULL);

    strcpy(imp->msg, msg);

    return imp;
}

void ExecutaTarefaImprimir(void* imp) {
    assert(imp != NULL);

    printf("\n%s", cast(imp)->msg);
}

void DestroiTarefaImprimir(void* imp) {
    if (imp != NULL) {
        if (cast(imp)->msg != NULL)
            free(cast(imp)->msg);

        free(imp);
    }
}