#include "time.h"
#include "tabela.h"
#include <string.h>
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
    scanf("%d %d %d", &c->qnt_times_entram, &c->qnt_partidas, &c->premio);
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
    char time1[MAX_TIME_NOME], time2[MAX_TIME_NOME];

    for (int i = 0; i < 2; i++)
    {
        scanf("%s %d x %d %s\n", time1, &gols1, &gols2, time2);
        AtualizaGolsMarcados(ObtemTimeTabela(br->tabela_jogo, time1), gols1);
        AtualizaGolsMarcados(ObtemTimeTabela(br->tabela_jogo, time2), gols2);

        AtualizaGolsSofridos(ObtemTimeTabela(br->tabela_jogo, time1), gols1);
        AtualizaGolsSofridos(ObtemTimeTabela(br->tabela_jogo, time2), gols2);

        if (gols1 > gols2)
        {
            AtualizaVitorias(ObtemTimeTabela(br->tabela_jogo, time1));
            AtualizaDerrotas(ObtemTimeTabela(br->tabela_jogo, time2));
        }
        else if (gols2 > gols1)
        {
            AtualizaVitorias(ObtemTimeTabela(br->tabela_jogo, time2));
            AtualizaDerrotas(ObtemTimeTabela(br->tabela_jogo, time1));
        }
        else if (gols1 == gols2)
        {
            AtualizaEmpates(ObtemTimeTabela(br->tabela_jogo, time1));
            AtualizaEmpates(ObtemTimeTabela(br->tabela_jogo, time2));
        }
    }
}

/**
 * @brief Imprime o menu e trata cada opcao.
 */
void RealizaCamp(BRA *br)
{
    char op;
    while (1)
    {
        printf("Menu:\n");
        printf("C - Continuar\n");
        printf("R - Retirar 2 times e seguir\n");
        printf("F - Finalizar\n\n");

        scanf("%c\n", &op);
        if (op == 'C')
        {
            RealizaRodada(br);
            ImprimeTabela(br->tabela_jogo);
        }
        else if (op == 'R')
        {
            RemoveTimesCamp(br);
            ImprimeTabela(br->tabela_jogo);
        }
        else if (op == 'F')
        {
            FinalizaCamp(br);
            break;
        }
        if (br->qnt_times_entram == br->qnt_times_sairam)
        {
            FinalizaCamp(br);
        }
        printf("\n\n%d %d\n\n", br->qnt_times_entram, br->qnt_times_sairam);
        OrdenaTabela(br->tabela_jogo);
    }
}

/**
 * @brief Le 2 nomes da entrada padrao e remove os times correspondentes da competicao.
 */
void RemoveTimesCamp(BRA *br)
{
    char time1[MAX_TIME_NOME], time2[MAX_TIME_NOME];
    scanf("%s %s\n", time1, time2);
    RemoveTimeTabela(br->tabela_jogo, time1);
    RemoveTimeTabela(br->tabela_jogo, time2);
    br->qnt_times_sairam += 2;
}

/**
 * @brief Libera a memoria do campeonato.
 */
void DesalocaCamp(BRA *br)
{
    free(br);
}

/**
 * @brief Imprime a tabela final, premiacao e desaloca o campeonato.
 */
void FinalizaCamp(BRA *br)
{
    ImprimeTabela(br->tabela_jogo);
    ImprimePremiacao(br->tabela_jogo, br->premio);
    // DesalocaCamp(br);
}
