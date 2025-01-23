#include "vetor.h"
#include <stdio.h>
#define TAMANHO_MAXIMO 10

/**
 * @brief Ponteiro para função que recebe dois inteiros e realiza uma operação matemática.
 *
 * return int Resultado da operação matemática.
 */
typedef int (*Operation)(int, int);

/**
 * Lê um vetor da entrada padrão.
 *
 * @param vetor Ponteiro para o vetor que será lido.
 */
void LeVetor(Vetor *vetor)
{
    scanf("%d\n", &vetor->tamanhoUtilizado);
    for (int i = 0; i < vetor->tamanhoUtilizado; i++)
    {
        scanf("%d ", &vetor->elementos[i]);
    }
}

/**
 * Aplica uma operação em um vetor.
 *
 * @param vetor Ponteiro para o vetor que será utilizado.
 * @param op Ponteiro para a função que será aplicada.
 * @return O resultado da operação.
 */
int AplicarOperacaoVetor(Vetor *vetor, Operation op)
{
    int resultado;

    for (int i = 0; i < vetor->tamanhoUtilizado - 1; i++)
    {
        if (i == 0)
            resultado = vetor->elementos[i];
        resultado = op(resultado, vetor->elementos[i + 1]);
    }
    return resultado;
}
