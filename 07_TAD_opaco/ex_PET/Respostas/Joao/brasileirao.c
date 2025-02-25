#include "time.h"
#include "tabela.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "brasileirao.h"

#define MAX_TIMES 20

struct _BRA
{
    int qnt_times_entram;
    int qnt_times_sairam;
    int qnt_partidas;
    int premio;
    tTabela *tabela_jogo;
};

/**
 * @brief Construtor do campeonato. Le da entrada padrao numero de times, numero de rodadas e pontuacao.
 */
BRA *CriaCamp()
{

    BRA *c = (BRA *)malloc(sizeof(BRA));

    printf("Insira o num de times, rodadas e premio total:\n");
    scanf("%d %d %d\n", &c->qnt_times_entram, &c->qnt_partidas, &c->premio);
    c->tabela_jogo = CriaTabela(c->qnt_times_entram);
    c->qnt_times_sairam = 0;
    return c;
}

/**
 * @brief Le da entrada padrao as partidas da rodada, computa os resultados e atualiza a tabela.
 */
void RealizaRodada(BRA *br)
{
    int gols1, gols2;
    char nome1[MAX_TIME_NOME], nome2[MAX_TIME_NOME];
    tTime *time1, *time2;

    scanf("\n%s %d x %d %s", nome1, &gols1, &gols2, nome2);
    time1 = ObtemTimeTabela(br->tabela_jogo, nome1);
    time2 = ObtemTimeTabela(br->tabela_jogo, nome2);
    if (time1 != NULL && time2 != NULL)
    {

        AtualizaGolsMarcados(time1, gols1);
        AtualizaGolsMarcados(time2, gols2);

        AtualizaGolsSofridos(time1, gols2);
        AtualizaGolsSofridos(time2, gols1);

        if (gols1 > gols2)
        {
            AtualizaVitorias(time1);
            AtualizaDerrotas(time2);
        }
        else if (gols2 > gols1)
        {
            AtualizaVitorias(time2);
            AtualizaDerrotas(time1);
        }
        else if (gols1 == gols2)
        {
            AtualizaEmpates(time1);
            AtualizaEmpates(time2);
        }
    }
    OrdenaTabela(br->tabela_jogo);
}

/**
 * @brief Imprime o menu e trata cada opcao.
 */
void RealizaCamp(BRA *br)
{   int partidas_realizadas=0;
    char op;
    while (1)
    {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");

        scanf("\n%c", &op);
        if (op == 'C')
        {
            for (int i = 0; i < (br->qnt_times_entram - br->qnt_times_sairam) / 2; i++)
            {
                RealizaRodada(br);
            }
            ImprimeTabela(br->tabela_jogo);
            partidas_realizadas++;
        }
        else if (op == 'R')
        {
            printf("Times a serem retirados:\n");
            RemoveTimesCamp(br);
        }
        if (op == 'F' || partidas_realizadas == br->qnt_partidas)
        {
            printf("Esta foi a tabela final:\n");
            ImprimeTabela(br->tabela_jogo);
            break;
        }
        if (br->qnt_times_entram == br->qnt_times_sairam)
        {
            break;
        }
    }
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
 */
void RemoveTimesCamp(BRA *br)
{
    char time1[MAX_TIME_NOME], time2[MAX_TIME_NOME];
    scanf("\n%s %s", time1, time2);
    RemoveTimeTabela(br->tabela_jogo, time1);
    RemoveTimeTabela(br->tabela_jogo, time2);
    printf("Os times %s e %s se retiraram do campeonato\n", time1, time2);
    br->qnt_times_sairam += 2;
    if (br->qnt_times_entram - br->qnt_times_sairam > 1)
    {
        RealizaRodada(br);
        ImprimeTabela(br->tabela_jogo);
    }
}

/**
 * @brief Libera a memoria do campeonato.
 */
void DesalocaCamp(BRA *br)
{
    DesalocaTabela(br->tabela_jogo);
    free(br);
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
 */
void FinalizaCamp(BRA *br)
{
    ImprimePremiacao(br->tabela_jogo, br->premio);
    printf("Fim do campeonato\n");
    DesalocaCamp(br);
}
