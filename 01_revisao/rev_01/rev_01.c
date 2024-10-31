#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
    float raio;
} tCirculo;

tCirculo InicializaCirculo(float x, float y, float r);

tCirculo LeCirculo();

float RetornaXCirculo(tCirculo c);

float RetornaYCirculo(tCirculo c);

float RetornaRaioCirculo(tCirculo c);

/* Retorna a distância entre o centro do circulo 1 e o centro do circulo 1 */
float DistanciaCirculo1E2(tCirculo c1, tCirculo c2);

int ColidiuCirculo1Com2(tCirculo c1, tCirculo c2);

int main() {
    tCirculo alvo = LeCirculo();
    tCirculo tiro = LeCirculo();

    if (ColidiuCirculo1Com2(tiro, alvo)) {
        printf("ACERTOU");
    } else {
        printf("ERROU");
    }

    return 0;
}


tCirculo InicializaCirculo(float x, float y, float r) {
    tCirculo c;
    c.x = x;
    c.y = y;
    c.raio = r;

    return c;
}

tCirculo LeCirculo() {
    float x, y, r;
    scanf("%f %f %f", &x, &y, &r);

    return InicializaCirculo(x, y, r);
}

float RetornaXCirculo(tCirculo c) {
    return c.x;
}

float RetornaYCirculo(tCirculo c) {
    return c.y;
}

float RetornaRaioCirculo(tCirculo c) {
    return c.raio;
}

float DistanciaCirculo1E2(tCirculo c1, tCirculo c2) {
    float deltaX = RetornaXCirculo(c1) - RetornaXCirculo(c2);
    float deltaY = RetornaYCirculo(c1) - RetornaYCirculo(c2);

    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}

int ColidiuCirculo1Com2(tCirculo c1, tCirculo c2) {
    return DistanciaCirculo1E2(c1, c2) <= (RetornaRaioCirculo(c1) + RetornaRaioCirculo(c2));
}