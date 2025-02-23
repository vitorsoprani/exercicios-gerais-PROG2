#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "numcomplexo.h"

struct complexo {
    float R;
    float I;
};

tNumComplexo* CriaNumComplexo(float real, float imag) {
    tNumComplexo* cplx = (tNumComplexo*)malloc(sizeof(tNumComplexo));
    assert(cplx != NULL);

    cplx->R = real;
    cplx->I = imag;

    return cplx;
}

float PegaParteImagComplexo(tNumComplexo* cplx) {
    assert(cplx != NULL);

    return cplx->I;
}

float PegaParteRealComplexo(tNumComplexo* cplx) {
    assert(cplx != NULL);

    return cplx->R;
}

void ImprimeNumeroComplexo(tNumComplexo* cplx) {
    assert(cplx != NULL);

    printf("%.2f + i%.2f", PegaParteRealComplexo(cplx), PegaParteImagComplexo(cplx));
}

void DestroiNumeroComplexo(tNumComplexo* cplx) {
    if (cplx != NULL) {
        free(cplx);
    }
}

int RetornaNumBytesComplexo() {
    return sizeof(tNumComplexo);
}

tNumComplexo* SomaComplexos(tNumComplexo* n1, tNumComplexo* n2) {
    assert(n1 != NULL);
    assert(n2 != NULL);

    return CriaNumComplexo(n1->R + n2->R, n1->I + n2->I);
}

tNumComplexo* MultComplexos(tNumComplexo* n1, tNumComplexo* n2) {
    assert(n1 != NULL);
    assert(n2 != NULL);

    return CriaNumComplexo((n1->R * n2->R - n1->I * n2->I), (n1->R * n2->I + n2->R * n1->I));
}
