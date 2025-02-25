#include "time.h"
#include "tabela.h"
#include <stdlib.h>
#include <string.h>

struct _Tabela
{
    tTime **times;
    int qnt_times_atual;
    int qnt_times_alocado;
};

/**
 * @brief Construtor do tipo tabela. Deve criar os times.
 * @param numTimes Numero de times a serem criados.
 */
tTabela *CriaTabela(int numTimes)
{
    tTabela *t = (tTabela *)malloc(sizeof(tTabela));
    t->times = (tTime **)malloc(numTimes*sizeof(tTime *));

    t->qnt_times_atual = numTimes;
    t->qnt_times_alocado = 0;
    for (int i = 0; i < t->qnt_times_atual; i++)
    {
        t->times[i] = LeTime();
        if (t->times[i] != NULL)
            t->qnt_times_alocado++;
    }
    return t;
}

/**
 * @brief Libera a memoria alocada para a tabela e seus times.
 */
void DesalocaTabela(tTabela *tabela)
{
    for (int i = 0; i < tabela->qnt_times_alocado; i++)
    {
        DesalocaTime(tabela->times[i]);
    }
    free(tabela->times);
    free(tabela);
}

/**
 * @brief Ordena a tabela de acordo com os criterios definidos.
 */
void OrdenaTabela(tTabela *tabela)
{
    tTime *troca;
    for (int i = 0; i < tabela->qnt_times_atual - 1; i++)
    {
        for (int j = 0; j < tabela->qnt_times_atual - 1 - i; j++)
        if (DesempataTimes(tabela->times[j], tabela->times[j + 1]) == 1)
        {
            troca = tabela->times[j];
            tabela->times[j] = tabela->times[j + 1];
            tabela->times[j + 1] = troca;
        }
    }
}

/**
 * @brief Dado um nome, retorna o time correspondente.
 */
tTime *ObtemTimeTabela(tTabela *tabela, char *time)
{
    for (int i = 0; i < tabela->qnt_times_atual; i++)
    {
        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0)
            return tabela->times[i];
    }
}

/**
 * @brief Dado um nome, desaloca e remove o time correspondente da tabela.
 */
void RemoveTimeTabela(tTabela *tabela, char *time)
{
    tTime *troca;
    for (int i = 0; i < tabela->qnt_times_atual; i++)
    {
        if (strcmp(ObtemNomeTime(tabela->times[i]), time) == 0)
        {
            troca = tabela->times[i];
            tabela->times[i] = tabela->times[tabela->qnt_times_atual - 1];
            tabela->times[tabela->qnt_times_atual - 1] = troca;
            tabela->qnt_times_atual--;
        }
    }
}

/**
 * @brief Imprime a tela de premiacao no final do campeonato.
 */
void ImprimePremiacao(tTabela *tabela, float valorPremio)
{
    if (tabela->qnt_times_atual == 0)
    {
        printf("Premio de R$%.2f acumulado para a proxima edicao\n", valorPremio);
    }
    else if (tabela->qnt_times_atual == 2)
    {
        for (int i = 0; i < tabela->qnt_times_atual; i++)
        {
            printf("%dº lugar - %s: ", i + 1, ObtemNomeTime(tabela->times[i]));
            if (i == 0)
            {
                printf("R$%.2f\n", valorPremio * 0.6);
            }
            else if (i == 1)
            {
                printf("R$%.2f\n", valorPremio * 0.4);
            }
        }
    }
    else if (tabela->qnt_times_atual >= 3)
    {
        for (int i = 0; i < 3; i++)
        {
            printf("%dº lugar - %s: ", i + 1, ObtemNomeTime(tabela->times[i]));
            if (i == 0)
            {
                printf("R$%.2f\n", valorPremio * 0.5);
            }
            else if (i == 1)
            {
                printf("R$%.2f\n", valorPremio * 0.3);
            }
            else if (i == 2)
            {
                printf("R$%.2f\n", valorPremio * 0.2);
            }
        }
    }
}

/**
 * @brief Imprime todos os times da tabela.
 */
void ImprimeTabela(tTabela *tabela)
{
    printf("Classificação:\n");
    printf("Nome | Pontos | Vitorias | Derrotas | Empates | Saldo\n");
    for (int i = 0; i < tabela->qnt_times_atual; i++)
    {
        ImprimeTime(tabela->times[i]);
    }
}
