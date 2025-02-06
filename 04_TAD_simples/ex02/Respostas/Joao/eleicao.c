/*
#include "candidato.h"
#include "eleitor.h"

#define MAX_CANDIDATOS_POR_CARGO 3
#define MAX_ELEITORES 10

typedef struct
{
    tCandidato presidentes[MAX_CANDIDATOS_POR_CARGO];
    int totalPresidentes;

    tCandidato governadores[MAX_CANDIDATOS_POR_CARGO];
    int totalGovernadores;

    int votosBrancosPresidente;
    int votosNulosPresidente;

    int votosBrancosGovernador;
    int votosNulosGovernador;

    tEleitor eleitores[MAX_ELEITORES];
    int totalEleitores;

} tEleicao;

/**
 * @brief Inicializa uma eleição com valores padrão (zerando os votos invalidos).
 * Ainda nessa função, é lido a quantidade de candidatos e os candidatos são lidos e armazenados.
 * @return Eleição inicializada.
 
tEleicao InicializaEleicao()
{
    tEleicao eleicao;
    tCandidato cand_cola;
    int qnt_candidatos;

    eleicao.totalGovernadores = 0;
    eleicao.totalPresidentes = 0;

    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;

    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;

    return eleicao;

    scanf("%d\n", &qnt_candidatos);

    if (qnt_candidatos > 20)
    {
        printf("ELEICAO ANULADA");
        exit(0);
    }
    else
    {
        for (int i = 0; i < qnt_candidatos; i++)
        {

            cand_cola = LeCandidato();
            if (cand_cola.cargo == 'P')
            {
                eleicao.presidentes[eleicao.totalPresidentes] = cand_cola;
                eleicao.totalPresidentes++;
            }
            else if (cand_cola.cargo == 'G')
            {
                eleicao.governadores[eleicao.totalGovernadores] = cand_cola;
                eleicao.totalGovernadores;
            }
        }
    }
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 
tEleicao RealizaEleicao(tEleicao eleicao)
{
    scanf("%d\n", &eleicao.totalEleitores);
    if (eleicao.totalEleitores > MAX_ELEITORES)
    {
        printf("ELEICAO ANULADA");
        exit(0);
    }
    else
    {
        for (int i = 0; i < eleicao.totalEleitores; i++)
        {
            eleicao.eleitores[i] = LeEleitor();
            if (ObtemVotoGovernador(eleicao.eleitores[i]) == 0)
                eleicao.votosBrancosGovernador++;

            if (ObtemVotoPresidente(eleicao.eleitores[i]) == 0)
                eleicao.votosBrancosPresidente++;
            else if (ObtemVotoGovernador(eleicao.eleitores[i]) != 0 && ObtemVotoPresidente(eleicao.eleitores[i]) != 0)
            {
                for (int j = 0; j < MAX_CANDIDATOS_POR_CARGO; j++)
                {
                    if (VerificaIdCandidato(eleicao.governadores[j], eleicao.eleitores[i].votoG))
                        IncrementaVotoCandidato(eleicao.governadores[j]);
                    else
                        eleicao.votosNulosGovernador++;

                    if (VerificaIdCandidato(eleicao.presidentes[j], eleicao.eleitores[i].votoP))
                        IncrementaVotoCandidato(eleicao.presidentes[j]);
                    else
                        eleicao.votosNulosGovernador++;
                }
            }
        }

        eleicao.votosNulosGovernador -= eleicao.totalGovernadores - 1;
        eleicao.votosNulosPresidente -= eleicao.totalPresidentes - 1;
    }

    tCandidato troca;
    for (int i = 0; i < MAX_CANDIDATOS_POR_CARGO - 1; i++)
    {
        for (int j = 0; j < MAX_CANDIDATOS_POR_CARGO - i - 1; j++)
        {
            if (eleicao.governadores[j].votos >= eleicao.governadores[j + 1].votos)
            {
                troca = eleicao.governadores[j];
                eleicao.governadores[j] = eleicao.governadores[j + 1];
                eleicao.governadores[j + 1] = troca;
            }
        }
    }

        for (int i = 0; i < MAX_CANDIDATOS_POR_CARGO - 1; i++)
    {
        for (int j = 0; j < MAX_CANDIDATOS_POR_CARGO - i - 1; j++)
        {
            if (eleicao.presidentes[j].votos >= eleicao.presidentes[j + 1].votos)
            {
                troca = eleicao.presidentes[j];
                eleicao.presidentes[j] = eleicao.presidentes[j + 1];
                eleicao.presidentes[j + 1] = troca;
            }
        }
    }

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 
void ImprimeResultadoEleicao(tEleicao eleicao)
{
}
*/