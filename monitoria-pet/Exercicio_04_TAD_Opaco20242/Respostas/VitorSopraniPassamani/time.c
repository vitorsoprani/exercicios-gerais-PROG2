#include <assert.h>
#include "time.h"

struct _Time {
    char nome[MAX_TIME_NOME];
    int qtdVitorias;
    int qtdDerrotas;
    int qtdEmpates;
    int golsMarcados;
    int golsSofridos;
};

tTime* LeTime() {
    tTime* t = (tTime*)malloc(sizeof(tTime));
    assert(t != NULL);

    scanf("%32[^\n]%*c", t->nome);

    t->qtdVitorias = 0;
    t->qtdDerrotas = 0;
    t->qtdEmpates = 0;
    t->golsMarcados = 0;
    t->golsSofridos = 0;

    return t;
}

int ObtemVitorias(tTime* t) {
    assert(t != NULL);

    return t->qtdVitorias;
}

int ObtemPartidas(tTime* t) {
    assert(t != NULL);

    return t->qtdVitorias + t->qtdDerrotas + t->qtdEmpates;
}

int ObtemDerrotas(tTime* t) {
    assert(t != NULL);

    return t->qtdDerrotas;
}

char* ObtemNomeTime(tTime* t) {
    assert(t != NULL);

    return t->nome;
}

int ObtemSaldo(tTime* t) {
    assert(t != NULL);

    return t->golsMarcados - t->golsSofridos;
}

void AtualizaVitorias(tTime* t) {
    assert(t != NULL);

    t->qtdVitorias++;
}

void AtualizaEmpates(tTime* t) {
    assert(t != NULL);

    t->qtdEmpates++;
}

void AtualizaDerrotas(tTime* t) {
    assert(t != NULL);

    t->qtdDerrotas++;
}

void AtualizaGolsMarcados(tTime* t, int gols) {
    assert(t != NULL);

    t->golsMarcados += gols;
}

void AtualizaGolsSofridos(tTime* t, int gols) {
    assert(t != NULL);

    t->golsSofridos += gols;
}

int ObtemPontos(tTime* t) {
    assert(t != NULL);

    return (t->qtdVitorias * 3) + t->qtdEmpates;
}

int DesempataTimes(tTime* t1, tTime* t2) {
    assert(t1 != NULL);
    assert(t2 != NULL);

    if (ObtemPontos(t1) > ObtemPontos(t2))
        return -1;
    if (ObtemPontos(t1) < ObtemPontos(t2))
        return 1;

    if (ObtemVitorias(t1) > ObtemVitorias(t2))
        return -1;
    if (ObtemVitorias(t1) < ObtemVitorias(t2))
        return 1;

    if (ObtemSaldo(t1) > ObtemSaldo(t2))
        return -1;
    if (ObtemSaldo(t1) < ObtemSaldo(t2))
        return 1;

    return 0;
}

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
*/
void ImprimeTime(tTime* t) {
    assert(t != NULL);

    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, ObtemPontos(t), t->qtdVitorias, t->qtdDerrotas, t->qtdEmpates, ObtemSaldo(t));
}

void DesalocaTime(tTime* t) {
    if (t != NULL)
        free(t);
}