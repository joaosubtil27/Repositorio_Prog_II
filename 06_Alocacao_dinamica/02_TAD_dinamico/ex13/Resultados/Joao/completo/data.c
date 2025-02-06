#include <stdio.h>
#include <stdlib.h>
#include "data.h"

/**
 * @brief Lê uma data da entrada padrão.
 * @return Um ponteiro para a data lida.
 */
tData *LeData()
{

    tData *d;

    int dia, mes, ano;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    d = CriaData(dia, mes, ano);
    return d;
}

/**
 * @brief Cria uma data com o dia, mês e ano fornecidos. Se a alocação falhar, o programa é encerrado.
 * @param dia O dia da data.
 * @param mes O mês da data.
 * @param ano O ano da data.
 * @return Um ponteiro para a data criada.
 */
tData *CriaData(int dia, int mes, int ano)
{

    tData *d = (tData*) malloc(sizeof(tData));

    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    if (d == NULL)
        exit(1);

    return d;
}

/**
 * @brief Libera a memória alocada para uma data.
 * @param d Um ponteiro para a data a ser liberada.
 */
void LiberaData(tData *d)
{
    free(d);
}

/**
 * @brief Calcula a idade de uma pessoa com base na data de nascimento e em uma data para calcular a idade.
 * @param nascimento Um ponteiro para a data de nascimento da pessoa.
 * @param diacalc Um ponteiro para a data para calcular a idade.
 * @return A idade da pessoa.
 */
int CalculaIdadeData(tData *nascimento, tData *diacalc)
{
    int diff = diacalc->ano - nascimento->ano;
    if (diacalc->mes < nascimento->mes || (diacalc->mes == nascimento->mes && diacalc->dia < nascimento->dia))
        diff--;

    return diff;
}

/**
 * @brief Imprime uma data na saída padrão.
 * @param d Um ponteiro para a data a ser impressa.
 */
void ImprimeData(tData *d)
{
    printf("%d/%d/%d", d->dia, d->mes, d->ano);
}
