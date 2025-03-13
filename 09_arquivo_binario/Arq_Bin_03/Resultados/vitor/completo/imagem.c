#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "imagem.h"

struct tImagem {
    int nLinhas;
    int nColunas;
    int nBytesLidos;

    Tipo tipo;

    void* dados;
};

Imagem *LerImagem(const char *caminho) {
    Imagem* img = (Imagem*)malloc(sizeof(Imagem));
    assert(img != NULL);

    FILE* imgBin = fopen(caminho, "rb");
    assert(imgBin != NULL);

    img->nBytesLidos = 0;
    img->nBytesLidos += sizeof(int) * fread(&img->nColunas, sizeof(int), 1, imgBin);
    img->nBytesLidos += sizeof(int) * fread(&img->nLinhas, sizeof(int), 1, imgBin);
    img->nBytesLidos += sizeof(int) * fread(&img->tipo, sizeof(int), 1, imgBin);
    
    if (img->tipo == INT) {
        img->dados = (void*)malloc(sizeof(int) * img->nLinhas * img->nColunas);
        
        for(int i = 0; i < (img->nLinhas * img->nColunas); i++) {
            img->nBytesLidos += sizeof(int) * fread(&((int*)img->dados)[i], sizeof(int), 1, imgBin);
        }
    } else if (img->tipo == FLOAT) {
        img->dados = (void*)malloc(sizeof(float) * img->nLinhas * img->nColunas);
        
        for(int i = 0; i < (img->nLinhas * img->nColunas); i++) {
            img->nBytesLidos += sizeof(float) * fread(&((float*)img->dados)[i], sizeof(float), 1, imgBin);        
        }
    } else {
        printf("tipo de dado nao identificado\n");
        exit(1);
    }

    assert(!feof(imgBin));

    fclose(imgBin);

    return img;
}

void DestruirImagem(Imagem *img) {
    if (img != NULL) {
        free(img->dados);
        free(img);
    }
}

int ObterNumeroBytesLidos(Imagem *img) {
    assert(img != NULL);

    return img->nBytesLidos;
}

void ImprimirImagem(Imagem *img) {
    assert (img != NULL);
    
    if (img->tipo == INT) {
        for (int i = 0; i < img->nLinhas; i++) {
            for (int j = 0; j < img->nColunas; j++) {
                printf("%d ", ((int*)img->dados)[j]);
            }
            printf("\n");
        }
    } else if (img->tipo == FLOAT) {
        for (int i = 0; i < img->nLinhas; i++) {
            for (int j = 0; j < img->nColunas; j++) {
                printf("%.2f ", ((float*)img->dados)[j]);
            }
            printf("\n");
        }
    } else {
        printf("tipo nao ideintidinisd");
        exit(1);
    }
}