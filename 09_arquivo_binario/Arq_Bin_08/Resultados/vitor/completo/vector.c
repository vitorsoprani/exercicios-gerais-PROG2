#include <stdlib.h>
#include <assert.h>

#include "vector.h"

struct Vector {
    DataType* elementos;
    int tamanho;
};

Vector* VectorConstruct() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    assert(v != NULL);

    v->tamanho = 0;

    v->elementos = (DataType)malloc(sizeof(DataType) * v->tamanho);
    assert(v != NULL);

    return v;
}

void VectorPushBack(Vector* v, DataType val) {
    assert(v != NULL);
    assert(val != NULL);

    v->tamanho++;
    v->elementos = (DataType)realloc(v->elementos, sizeof(DataType) * v->tamanho);

    assert(v != NULL);
    v->elementos[v->tamanho - 1] = val;
}

void VectorRemove(Vector *v, int i) {
    assert(v != NULL);
    assert(i < v->tamanho);
    assert(i > 0);

    v->tamanho--;

    for (int j = i; j < v->tamanho; j++) {
        v->elementos[j] = v->elementos[j + 1];
    }

    v->elementos = (DataType*)realloc(v->elementos, v->tamanho * sizeof(DataType));

    assert(v->elementos != NULL);
}

DataType VectorGet(Vector* v, int i) {
    assert(v != NULL);

    if (i >= v->tamanho)
        return NULL;

    return v->elementos[i];
}

int VectorSize(Vector* v) {
    assert(v != NULL);
    return v->tamanho;
}

void VectorDestroy(Vector* v, void (*destroy)(DataType)) {
    if (v != NULL) {
        if (v->elementos != NULL)
            for (int i = 0; i < v->tamanho; i++)
                destroy(v->elementos[i]);
        free(v->elementos);
        free(v);
    }
}