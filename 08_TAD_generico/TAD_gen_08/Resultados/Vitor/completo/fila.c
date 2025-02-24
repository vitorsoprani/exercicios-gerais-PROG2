#include <stdlib.h>
#include <assert.h>

#include "fila.h"

#define DEBUG 1

struct Fila {
    Vector* conteudo;
};

Fila *FilaConstruct() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    assert(f != NULL);

    f->conteudo = VectorConstruct();

    return f;
}

void FilaDestroy(Fila *f, void (*destroy)(DataType)) {
    #if DEBUG
        assert(f != NULL);
    #else 
        if(f == NULL) return;
    #endif    

    if (f != NULL) {
        if (f->conteudo != NULL)
            VectorDestroy(f->conteudo, destroy);
        free(f);
    }
}

int FilaSize(Fila *f) {
    #if DEBUG
        assert(f != NULL);
    #else 
        if (f == NULL) return -1;
    #endif
    
    return VectorSize(f->conteudo);
}

DataType FilaPop(Fila *f) {
    #if DEBUG
        assert(f != NULL);
    #else 
        return NULL;
    #endif

    return VectorPopFront(f->conteudo);
}

void FilaPush(Fila *f, DataType val) {
    #if DEBUG
        assert(f != NULL);
        assert(val != NULL);
    #else 
        if (f == NULL || val == NULL) return;
    #endif

    VectorPushBack(f->conteudo, val);
}