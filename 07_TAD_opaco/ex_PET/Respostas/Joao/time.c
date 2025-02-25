
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

#define MAX_TIME_NOME 33

struct _Time
{
char nome[MAX_TIME_NOME];
int vitorias;
int partidas;
int derrotas;
int empates;
int gol_feito;
int gol_adv;
int saldo;
}
;

/**
 * @brief Construtor do tipo time. Deve ler um nome pela entrada padrao.
 */
tTime *LeTime()
{
    tTime *t = malloc(sizeof(tTime));

    scanf("%[^\n]\n", t->nome);

    t->vitorias = 0;
    t->partidas = 0;
    t->derrotas = 0;
    t->empates = 0;
    t->gol_feito = 0;
    t->gol_adv = 0;
    t->saldo = 0;

    return t;
}

/**
 * @brief Retona o numero de vitorias do time.
 */
int ObtemVitorias(tTime *t)
{
    return t->vitorias;
}

/**
 * @brief Retona o numero de partidas.
 */
int ObtemPartidas(tTime *t)
{
    return t->partidas;
}

/**
 * @brief Retona o numero de derrotas do time.
 */
int ObtemDerrotas(tTime *t)
{
    return t->derrotas;
}

/**
 * @brief Retona a string do nome do time.
 */
char *ObtemNomeTime(tTime *t)
{
    return t->nome;
}

/**
 * @brief Retona o saldo de gols da equipe.
 */
int ObtemSaldo(tTime *t)
{
    return t->saldo;
}

/**
 * @brief Aumenta o numero de vitorias em 1.
 */
void AtualizaVitorias(tTime *t)
{
    t->vitorias++;
}

/**
 * @brief Aumenta o numero de empates em 1.
 */
void AtualizaEmpates(tTime *t)
{
    t->empates++;
};

/**
 * @brief Aumenta o numero de derrotas em 1.
 */
void AtualizaDerrotas(tTime *t)
{
    t->derrotas++;
};

/**
 * @brief Aumenta a quantidade de gols marcados.
 */
void AtualizaGolsMarcados(tTime *t, int gols)
{
    t->gol_feito += gols;
    t->saldo += gols;
}

/**
 * @brief Aumenta a quantidade de gols sofridos.
 */
void AtualizaGolsSofridos(tTime *t, int gols)
{
    t->gol_adv += gols;
    t->saldo -= gols;
}

/**
 * @brief Retorna a pontuacao do time.
 */
int ObtemPontos(tTime *t)
{

    return (ObtemVitorias(t) * 3) + t->empates;
};

/**
 * @brief Usa os criterios de classificacao para indicar qual time possui melhor colocacao. Retorna -1 para t1, 1 para t2.
 */
int DesempataTimes(tTime *t1, tTime *t2)
{
    if (ObtemPontos(t1) > ObtemPontos(t2))
        return -1;
    else if (ObtemPontos(t1) < ObtemPontos(t2))
        return 1;
    else
    {
        if (ObtemVitorias(t1) > ObtemVitorias(t2))
            return -1;
        else if (ObtemVitorias(t1) < ObtemVitorias(t2))
            return 1;
        else
        {
            if (ObtemSaldo(t1) > ObtemSaldo(t2))
                return -1;
            else if (ObtemSaldo(t1) < ObtemSaldo(t2))
                return 1;

            else
                return 0;
        }
    }
};

/**
 * @brief Imprime os dados do time na ordem: Nome | Pontos | Vitorias | Derrotas | Empates | Saldo.
 * Dica: Use a seguinte formatacao no printf: "%-12s | %02d | %02d | %02d | %02d | %+03d\n".
 */
void ImprimeTime(tTime *t)
{
    printf("%-12s | %02d | %02d | %02d | %02d | %+03d\n", t->nome, ObtemPontos(t), t->vitorias, t->derrotas, t->empates, ObtemSaldo(t));
}

/**
 * @brief Libera a memoria alocada para time.
 */
void DesalocaTime(tTime *t)
{
    free(t);
}
