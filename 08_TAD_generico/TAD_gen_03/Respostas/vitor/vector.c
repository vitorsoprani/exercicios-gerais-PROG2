#include <stdlib.h>
#include <assert.h>
#include "vector.h"

struct Vector {
    data_type* elementos;
    int tamanho;
};

Vector* VectorConstruct() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    assert(v != NULL);

    v->tamanho = 0;

    v->elementos = (data_type)malloc(sizeof(data_type) * v->tamanho);
    assert(v != NULL);

    return v;
}

void VectorPushBack(Vector* v, data_type val) {
    assert(v != NULL);
    assert(val != NULL);

    v->tamanho++;
    v->elementos = (data_type)realloc(v->elementos, sizeof(data_type) * v->tamanho);

    assert(v != NULL);
    v->elementos[v->tamanho - 1] = val;
}

data_type VectorGet(Vector* v, int i) {
    assert(v != NULL);

    if (i >= v->tamanho)
        return NULL;

    return v->elementos[i];
}

int VectorSize(Vector* v) {
    assert(v != NULL);
    return v->tamanho;
}

void VectorDestroy(Vector* v, void (*destroy)(data_type)) {
    if (v != NULL) {
        if (v->elementos != NULL)
            for (int i = 0; i < v->tamanho; i++)
                destroy(v->elementos[i]);
        free(v->elementos);
        free(v);
    }
}