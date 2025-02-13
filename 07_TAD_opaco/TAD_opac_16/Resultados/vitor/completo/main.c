#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "data.h"

int main() {
    char* str = (char*)malloc(sizeof(char) * 40);
    assert(str != NULL);

    tData* data = CriaData();

    str = fgets(str, 40, stdin);

    ProcessaDiaMesAno(data, str);
    ProcessaDiaDaSemana(data, str);
    ProcessaHorario(data, str);

    DestroiData(data);
    return 0;
}