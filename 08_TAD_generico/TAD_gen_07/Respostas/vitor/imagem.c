#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "imagem.h"

#define DEBUG 1

struct tImagem {
    Tipo tipo;
    int altura;
    int largura;
    void* pixels;
};

int ObterAltura(Imagem *img) {
    #if DEBUG
        assert(img != NULL);
    #endif

    return img->altura;
}

int ObterLargura(Imagem *img) {
    #if DEBUG
        assert(img != NULL);
    #endif

    return img->largura;
}

Tipo ObterTipoImagem(Imagem *img) {
    #if DEBUG
        assert(img != NULL);
    #endif

    return img->tipo;
}

void *ObterDadosImagem(Imagem *img) {
    #if DEBUG
        assert(img != NULL);
        assert(img->pixels != NULL);
    #endif

    return img->pixels;
}

Imagem *CriarImagem(int altura, int largura, Tipo tipo) {
    #if DEBUG
        assert(altura > 0);
        assert(largura > 0);
        assert(tipo == INT || tipo == FLOAT);
    #endif

    Imagem* img = (Imagem*)malloc(sizeof(Imagem));
    assert(img != NULL);

    if(tipo == INT) {
        img->pixels = malloc(sizeof(int) * altura * largura);
    } else if (tipo == FLOAT) {
        img->pixels = malloc(sizeof(float) * altura * largura);
    }

    assert(img->pixels != NULL);

    img->largura = largura;
    img->altura = altura;
    img->tipo = tipo;

    return img;
}

Imagem *LerImagem() {
    int largura = 0, altura = 0, tipo = 0;
    Imagem* img = NULL;

    scanf("%d %d %d%*c", &altura, &largura, &tipo);
    img = CriarImagem(altura, largura, tipo);

    if (ObterTipoImagem(img) == INT) {
        for(int i = 0; i < ObterLargura(img) * ObterLargura(img); i++)
            scanf("%d ", &((int*)img->pixels)[i]);
    } else if (ObterTipoImagem(img) == FLOAT) {
        for(int i = 0; i < ObterLargura(img) * ObterLargura(img); i++) 
            scanf("%f ", &((float*)img->pixels)[i]);
    } else {
        return NULL;
    }

    return img;
}

void ImprimirImagem(Imagem *img) {
    #if DEBUG
        assert(img != NULL);
        assert(img->pixels != NULL);
    #endif

    if (ObterTipoImagem(img) == INT) {
        for (int i = 0; i < ObterLargura(img) * ObterLargura(img); i++)
            printf("%d ", ((int*)img->pixels)[i]);
    } else if (ObterTipoImagem(img) == FLOAT) {
        for (int i = 0; i < ObterLargura(img) * ObterLargura(img); i++)
            printf("%f ", ((float*)img->pixels)[i]);
    }
}

void DestruirImagem(Imagem *img) {
    if (img != NULL) {
        if (img->pixels != NULL)
            free(img->pixels);
        free(img);
    }
}