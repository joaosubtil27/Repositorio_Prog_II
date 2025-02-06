#include "pessoa.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Cria uma nova pessoa com nome vazio (primeiro caractere igual a '\0') e inicializa os ponteiros para pai e mae com NULL.
 *
 * @return Uma nova pessoa e sem pais.
 */
tPessoa CriaPessoa()
{
    tPessoa pessoa;

    pessoa.nome[0] = '\0';
    pessoa.pai = NULL;
    pessoa.mae = NULL;

    return pessoa;
}

/**
 * @brief Lê os dados de uma pessoa.
 *
 * @param pessoa Ponteiro para a pessoa a ser lida.
 */
void LePessoa(tPessoa *pessoa)
{

    scanf("%[^\n]", pessoa->nome);
}

/**
 * @brief Verifica se uma pessoa tem pai e/ou mae associado(s).
 * Ou seja, verifica pelo menos um dos ponteiros pai e mae é diferente de NULL.
 *
 * @param pessoa Ponteiro para a pessoa a ser verificada.
 *
 * @return 1 se a pessoa tiver pai e/ou mae associado(s) e 0 caso contrário.
 */
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->mae != NULL || pessoa->pai != NULL)
        return 1;
    else
        return 0;
}

/**
 * @brief Imprime os dados de uma pessoa caso tenha pai e/ou mae associado(s).
 * Dica: use a função VerificaSeTemPaisPessoa para verificar se a pessoa tem pai e/ou mae associado(s).
 * Alem disso, imprimir o nome do irmao caso exista.
 *
 * @param pessoa Ponteiro para a pessoa a ser impressa.
 */
void ImprimePessoa(tPessoa *pessoa)
{
    if (VerificaSeTemPaisPessoa(pessoa) == 1)
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);

        // Verifique se 'pai' é NULL antes de acessar
        if (pessoa->pai != NULL && pessoa->pai->nome[0] != '\0')
            printf("PAI: %s\n", pessoa->pai->nome);
        else
            printf("PAI: NAO INFORMADO\n");

        // Verifique se 'mae' é NULL antes de acessar
        if (pessoa->mae != NULL && pessoa->mae->nome[0] != '\0')
            printf("MAE: %s\n\n", pessoa->mae->nome);
        else
            printf("MAE: NAO INFORMADO\n\n");
    }
}


/**
 * @brief Le as associciacoes da entrada padrao e altera as pessoas de forma a representar as associacoes lidas
 *
 * @param pessoas Ponteiro para a lista de pessoas a serem associadas.
 */
    void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    tPessoa pessoa;
    int troca = 0;
    int qnt_associacoes = 0;
    int i = 0;
    scanf("\n");
    
    while (1)
    {
        LePessoa(&pessoas[i]);

        if (scanf("%*c%d\n", &qnt_associacoes) == 1)
            break;
        else
            i++;
    }

    int mae[qnt_associacoes], pai[qnt_associacoes], filho[qnt_associacoes];

    for (int i = 0; i < qnt_associacoes; i++)
    {
        scanf("mae: %d, pai: %d, filho: %d\n", &mae[i], &pai[i], &filho[i]);
    }

    for (int i = 0; i < qnt_associacoes - 1; i++)
    {
        for (int j = 0; j < qnt_associacoes - i - 1; j++)
        {
            if (filho[j] > filho[j + 1])
            {
                troca = filho[j];
                filho[j] = filho[j + 1];
                filho[j + 1] = troca;

                troca = mae[j];
                mae[j] = mae[j + 1];
                mae[j + 1] = troca;

                troca = pai[j];
                pai[j] = pai[j + 1];
                pai[j + 1] = troca;
            }
        }
    }

    for (int i = 0; i < qnt_associacoes; i++)
    {
        strcpy(pessoa.nome, pessoas[filho[i]].nome);

        // Verifique se o valor de pai e mae não é -1 antes de atribuir
        if (pai[i] != -1)
            pessoa.pai = &pessoas[pai[i]];
        else
            pessoa.pai = NULL;

        if (mae[i] != -1)
            pessoa.mae = &pessoas[mae[i]];
        else
            pessoa.mae = NULL;

        ImprimePessoa(&pessoa);
    }
}
