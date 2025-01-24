#include <stdio.h>
#include "circulo.h"

int main() {
    tCirculo c = NULL;
    tPonto p = NULL;
    float xCirculo, yCirculo, rCirculo, xPonto, yPonto;

    scanf("%f %f %f", &xCirculo, &yCirculo, &rCirculo);
    c = Circulo_Cria(xCirculo, yCirculo, rCirculo);

    scanf("%f %f", &xPonto, &yPonto);
    p = Pto_Cria(xPonto, yPonto);

    printf("%d\n", Circulo_Interior(c, p));

    Circulo_Apaga(c);
    Pto_Apaga(p);
    return 0;
}