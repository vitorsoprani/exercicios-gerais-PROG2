#include <stdio.h>

struct tJogador {
    int linha;
    int coluna;

    int lFinal;
    int cFinal;

    char prioridade[4];
};
typedef struct tJogador tJogador;

//Le o ponto inicial, final e prioridade de movimentos do jogador
tJogador LeJogador() {
    tJogador j;
    scanf("%d %d\n", &j.linha, &j.coluna);
    scanf("%d %d\n", &j.lFinal, &j.cFinal);

    j.linha--;
    j.coluna--;
    j.lFinal--;
    j.cFinal--;

    for (int i = 0; i < 4; i++) {
        scanf("%c", &j.prioridade[i]);
    }

    return j;
}

int PodeMoverJogador(tJogador jogador, int l, int c, int mat[l][c]) {
    if (jogador.linha - 1 >= 0) {
        if (mat[jogador.linha - 1][jogador.coluna] == 0) return 1;
    }
    if (jogador.coluna - 1 >= 0) {
        if (mat[jogador.linha][jogador.coluna - 1] == 0) return 1;
    }
    if (jogador.coluna + 1 < c) {
        if (mat[jogador.linha][jogador.coluna + 1] == 0) return 1;
    }
    if (jogador.linha + 1 < l) {
        if (mat[jogador.linha + 1][jogador.coluna] == 0) return 1;
    }

    return 0;
}

int ChegouJogador(tJogador jogador) {
    return jogador.linha == jogador.lFinal && jogador.coluna == jogador.cFinal;
}

tJogador MoveJogador(tJogador jogador, int l, int c, int mat[l][c]) {
    int moveu = 0;
    for (int i = 0; i < 4; i++) {
        if (moveu) break;

        switch (jogador.prioridade[i]) {
        case 'C':
            if (jogador.linha - 1 >= 0 && mat[jogador.linha - 1][jogador.coluna] != 1) {
                mat[jogador.linha][jogador.coluna] = 1;
                jogador.linha--;
                moveu = 1;
            }
            break;
        case 'E':
            if (jogador.coluna - 1 >= 0 && mat[jogador.linha][jogador.coluna - 1] != 1) {
                mat[jogador.linha][jogador.coluna] = 1;
                jogador.coluna--;
                moveu = 1;
            }
            break;
        case 'D':
            if (jogador.coluna + 1 < c && mat[jogador.linha][jogador.coluna + 1] != 1) {
                mat[jogador.linha][jogador.coluna] = 1;
                jogador.coluna++;
                moveu = 1;
            }
            break;
        case 'B':
            if (jogador.linha + 1 < l && mat[jogador.linha + 1][jogador.coluna] != 1) {
                mat[jogador.linha][jogador.coluna] = 1;
                jogador.linha++;
                moveu = 1;
            }
            break;
        }
    }
    return jogador;
}

void ImprimePosiçãoJogador(tJogador jogador) {
    printf("(%d,%d)", jogador.linha + 1, jogador.coluna + 1);
}


void LeMatrizInt(int l, int c, int mat[l][c]) {
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
        scanf("%*c"); //apaga a quebra de linha;
    }
}

void ImprimeMatrizInt(int l, int c, int mat[l][c]) {
    printf("\n");
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {

    //LEITURA DA MATRIZ:
    int linhas, colunas;
    scanf("%d %d\n", &linhas, &colunas);
    int mat[linhas][colunas];

    LeMatrizInt(linhas, colunas, mat);

    tJogador jogador = LeJogador();

    while (PodeMoverJogador(jogador, linhas, colunas, mat) && !ChegouJogador(jogador)) {
        ImprimePosiçãoJogador(jogador);
        printf(" ");
        jogador = MoveJogador(jogador, linhas, colunas, mat);

        // ImprimeMatrizInt(linhas, colunas, mat);
    }

    ImprimePosiçãoJogador(jogador);
    printf(" ");
    return 0;
}