#include <stdio.h>
#include <stdlib.h>
#include "eleicao.h"
#include "candidato.h"
#include "eleitor.h"


#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

tEleicao InicializaEleicao() {
    tEleicao eleicao;

    int qtdCandidatos;
    scanf("%d\n", &qtdCandidatos);

    int candidatoAtualP = 0;
    int candidatoAtualG = 0;

    for (int i = 0; i < qtdCandidatos; i++) {

        tCandidato candidato;
        candidato = LeCandidato();

        if (ObtemCargo(candidato) == 'P') {
            if (candidatoAtualP + 1 > MAX_CANDIDATOS_POR_CARGO) {
                printf("ELEICAO ANULADA");
                exit(1);
            }
            eleicao.presidentes[candidatoAtualP] = candidato;
            candidatoAtualP++;
        } else {
            if (candidatoAtualG + 1 > MAX_CANDIDATOS_POR_CARGO) {
                printf("ELEICAO ANULADA");
                exit(1);
            }
            eleicao.governadores[candidatoAtualG] = candidato;
            candidatoAtualG++;
        }

    }

    eleicao.totalPresidentes = candidatoAtualP;
    eleicao.totalGovernadores = candidatoAtualG;
    eleicao.totalEleitores = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.votosNulosPresidente = 0;

    return eleicao;
}

tEleicao RealizaEleicao(tEleicao eleicao) {
    int qtdEleitores;
    scanf("%d\n", &qtdEleitores);

    if (qtdEleitores > MAX_ELEITORES) {
        printf("ELEICAO ANULADA\n", qtdEleitores);
        exit(1);
    }

    for (int i = 0; i < qtdEleitores; i++) {
        tEleitor eleitor = LeEleitor();

        //checa se o eleitor ja foi registrado:
        for (int j = 0; j < eleicao.totalEleitores; j++) {
            if (EhMesmoEleitor(eleitor, eleicao.eleitores[j])) {
                printf("ELEICAO ANULADA\n");
                exit(1);
            }
        }

        //contabiliza o voto presidente:
        if (ObtemVotoPresidente(eleitor) != 0) {
            int votou = 0;
            for (int j = 0; j < eleicao.totalPresidentes; j++) {
                if (VerificaIdCandidato(eleicao.presidentes[j], ObtemVotoPresidente(eleitor))) {
                    eleicao.presidentes[j] = IncrementaVotoCandidato(eleicao.presidentes[j]);
                    votou = 1;
                    break;
                }
            }
            if (!votou)
                eleicao.votosNulosPresidente++;
        } else {
            eleicao.votosBrancosPresidente++;
        }

        //contabiliza o voto gorvernador:
        if (ObtemVotoGovernador(eleitor) != 0) {
            int votou = 0;
            for (int j = 0; j < eleicao.totalGovernadores; j++) {
                if (VerificaIdCandidato(eleicao.governadores[j], ObtemVotoGovernador(eleitor))) {
                    eleicao.governadores[j] = IncrementaVotoCandidato(eleicao.governadores[j]);
                    votou = 1;
                    break;
                }
            }
            if (!votou)
                eleicao.votosNulosGovernador++;
        } else {
            eleicao.votosBrancosGovernador++;
        }

        eleicao.eleitores[i] = eleitor;
        eleicao.totalEleitores++;
    }

    return eleicao;
}

void ImprimeResultadoEleicao(tEleicao eleicao) {
    int votosInvalidosPresidente = eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente;
    int votosInvalidosGovernador = eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador;
    int houveEmpate;


    //APURA VOTOS PARA PRESIDENTE:
    int totalVotosPresidente = 0;
    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        totalVotosPresidente += ObtemVotos(eleicao.presidentes[i]);
    }

    printf("- PRESIDENTE ELEITO: ");
    tCandidato presidenteEleito = CriaCandidato("-", "-", '-', 0);
    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        if (ObtemVotos(eleicao.presidentes[i]) > ObtemVotos(presidenteEleito)) {
            presidenteEleito = eleicao.presidentes[i];
        }
    }


    //checa se houve empate para presidente
    houveEmpate = 0;
    for (int i = 0; i < eleicao.totalPresidentes; i++) {
        if (ObtemVotos(eleicao.presidentes[i]) == ObtemVotos(presidenteEleito)) {
            if (!EhMesmoCandidato(eleicao.presidentes[i], presidenteEleito)) {
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                houveEmpate = 1;
                break;
            }
        }
    }
    if (!houveEmpate) {
        //checa se houveram msi votos nulos
        if (ObtemVotos(presidenteEleito) < votosInvalidosPresidente) {
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(presidenteEleito, CalculaPercentualVotos(presidenteEleito, totalVotosPresidente + votosInvalidosPresidente));
        }
    }



    //APURA VOTOS PARA GOVERNADOR:
    int totalVotosgovernador = 0;
    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        totalVotosgovernador += ObtemVotos(eleicao.governadores[i]);
    }

    printf("- GOVERNADOR ELEITO: ");
    tCandidato governadorEleito = CriaCandidato("-", "-", '-', 0);
    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        if (ObtemVotos(eleicao.governadores[i]) > ObtemVotos(governadorEleito)) {
            governadorEleito = eleicao.governadores[i];
        }
    }



    //checa se houve empate para governador
    houveEmpate = 0;
    for (int i = 0; i < eleicao.totalGovernadores; i++) {
        if (ObtemVotos(eleicao.governadores[i]) == ObtemVotos(governadorEleito)) {
            if (!EhMesmoCandidato(eleicao.governadores[i], governadorEleito)) {
                printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
                houveEmpate = 1;
                break;
            }
        }
    }
    if (!houveEmpate) {
        //checa se houveram msi votos nulos
        if (ObtemVotos(governadorEleito) < votosInvalidosGovernador) {
            printf("SEM DECISAO\n");
        } else {
            ImprimeCandidato(governadorEleito, CalculaPercentualVotos(governadorEleito, totalVotosgovernador + votosInvalidosGovernador));
        }
    }


    printf("- NULOS E BRANCOS: %d, %d", eleicao.votosNulosGovernador + eleicao.votosNulosPresidente, eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente);
}