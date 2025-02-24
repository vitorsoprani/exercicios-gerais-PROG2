#include <stdlib.h>
#include <assert.h>

#include "vector.h"

#define DEBUG 1

struct Vector {
    int size;
    DataType *buffer;
};

Vector *VectorConstruct() {
    Vector* v = (Vector*)malloc(sizeof(Vector));
    assert(v != NULL);

    v->buffer = (DataType*)malloc(sizeof(DataType));
    assert(v->buffer != NULL);

    v->size = 0;

    return v;
}

void VectorPushBack(Vector *v, DataType val) {
    #if DEBUG
        assert(v != NULL);
    #else
        if(v == NULL) return;
    #endif

    v->size++;
    v->buffer = (DataType*)realloc(v->buffer, sizeof(DataType) * v->size);

    v->buffer[v->size - 1] = val;
}

DataType VectorPopFront(Vector *v) {
    #if DEBUG
        assert(v != NULL);
    #else
        if (v == NULL) return;
    #endif

    DataType returnValue = v->buffer[0];

    for (int i = 0; i < v->size - 1; i++)
        v->buffer[i] = v->buffer[i + 1];
    
    v->size--;
    v->buffer = (DataType*)realloc(v->buffer, sizeof(DataType) * v->size);

    return returnValue;
}

DataType VectorGet(Vector *v, int i) {
    #if DEBUG
        assert(v != NULL);
        assert(i < v->size && i>=0);
    #else
        if (v == NULL) return;
        if (i >= v->size || i < 0) return;
    #endif

    return v->buffer[i];
}

int VectorSize(Vector *v) {
    #if DEBUG
        assert(v != NULL);
    #else
        if (v == NULL) return -1;
    #endif

    return v->size;
}

void VectorDestroy(Vector *v, void (*destroy)(DataType)) {
    if (v != NULL) {
        if (v->buffer != NULL) {
            for (int i = 0; i < v->size; i++)
                destroy(v->buffer[i]);
            free(v->buffer);
        }
        free(v);
    }
}