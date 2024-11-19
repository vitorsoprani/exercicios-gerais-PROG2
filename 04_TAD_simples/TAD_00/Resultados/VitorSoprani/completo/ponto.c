#include "ponto.h"
#include <math.h>

/* Funcoes exportadas */

/* Funcao cria 
** Retorna um ponto com coordenadas (x,y)
*/
Ponto pto_cria (float x, float y) {
    Ponto p;
    p.y = y;
    p.x = x;
    return p;
}

/* Funcao acessa x
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_x (Ponto p) {
    return p.x;
}

/* Funcao acessa y
** Retorna o valor da coordenada x de um ponto
*/
float pto_acessa_y (Ponto p) {
    return p.y;
}

/* Funcao atribui x
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_x (Ponto p, float x) {
    p.x = x;
    return p;
}

/* Funcao atribui y
** Atribui novo valor as coordenada x de um ponto
*/
Ponto pto_atribui_y (Ponto p, float y) {
    p.y = y;
    return p;
}

/* Funcao distancia
** Retorna a distancia entre dois pontos
*/
float pto_distancia (Ponto p1, Ponto p2) {
    float deltaX = pto_acessa_x(p1) - pto_acessa_x(p2);
    float deltaY = pto_acessa_y(p1) - pto_acessa_y(p2);
    float distancia = sqrt(pow(deltaX, 2) + pow(deltaY, 2));

    return distancia;
}