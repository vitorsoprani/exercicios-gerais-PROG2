#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

#include "histograma.h"

#define DEBUG 1

struct tHistograma{
    int nIntervalos;
    int amplitudeIntervalos;

    int* valores;
};

Histograma *CalcularHistograma(Imagem *img, int nIntervalos) {
    #if DEBUG
        assert(img != NULL);
        assert(nIntervalos > 0);
    #endif

    Histograma* histograma = (Histograma*)malloc(sizeof(Histograma));
    assert(histograma != NULL);

    histograma->valores = (int*)calloc(nIntervalos, sizeof(int));
    assert(histograma->valores != NULL);

    int amplitude = ceil((float)256 / (float)nIntervalos); //FUnção "teto"
    
    histograma->nIntervalos = nIntervalos;
    histograma->amplitudeIntervalos = amplitude;

    int qtdPixels = ObterLargura(img) * ObterAltura(img);
    
    if (ObterTipoImagem(img) == INT) {
        int* dados = (int*)ObterDadosImagem(img);
        
        for(int i = 0; i < qtdPixels; i++) {
            for (int j = 0; j < nIntervalos; j++) {
                if (dados[i] < (j + 1) * amplitude) {
                    histograma->valores[j]++;
                    break;
                }
            }
        }
    } else if (ObterTipoImagem(img) == FLOAT) {
        float* dados = (float*)ObterDadosImagem(img);
        
        for(int i = 0; i < qtdPixels; i++) {
            for (int j = 0; j < nIntervalos; j++) {
                if ((int)(dados[i]*255) < (j + 1) * amplitude) {
                    histograma->valores[j]++;
                    break;
                }
            }
        } 
    }

    return histograma;
}

void MostrarHistograma(Histograma *histograma) {
    #if DEBUG
        assert(histograma != NULL);
        assert(histograma->valores != NULL);
    #endif

    for (int i = 0; i < histograma->nIntervalos; i++) {
        printf("[%d, %d): %d\n", i * histograma->amplitudeIntervalos, (i + 1) * histograma->amplitudeIntervalos, histograma->valores[i]);
    }
}

void DestruirHistograma(Histograma *histograma) {
    if (histograma != NULL) {
        if (histograma->valores != NULL)
            free(histograma->valores);
        free(histograma);
    }
}