#include <stdlib.h>
#include <assert.h>

#include "midia.h"

struct Midia {
    void* dado;
    PrintFunction print_fn;
    FreeFunction free_fn;
};

Midia *midia_construct(void *dado, PrintFunction print_fn, FreeFunction free_fn) {
    assert(dado != NULL);
    assert(print_fn != NULL);
    assert(free_fn != NULL);

    Midia* m = (Midia*)malloc(sizeof(Midia));
    assert(m != NULL);

    m->dado = dado;
    m->print_fn = print_fn;
    m->free_fn = free_fn;

    return m;
}

void midia_print(Midia* m) {
    assert(m != NULL);

    m->print_fn(m->dado);
}

void midia_destroy(Midia* m) {
    assert(m != NULL);

    m->free_fn(m->dado);
    free(m);
}