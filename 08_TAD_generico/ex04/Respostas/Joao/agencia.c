#include "agencia.h"
#include "conta.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX_STR 50
/**
 * @brief Estrutura para representar uma agência bancária.
 */
struct Agencia
{
    char nome[MAX_STR];
    int n_agencia;
    Vector *contas;
};

/**
 * @brief Função para criar uma nova agência bancária.
 * @return Um ponteiro para a nova agência bancária criada. Se a memória não puder ser alocada, a função imprime uma mensagem de erro e termina o programa.
 */
tAgencia *CriaAgencia()
{
    tAgencia *a = (tAgencia *)malloc(sizeof(tAgencia));
    a->contas = VectorConstruct();
    return a;
}

/**
 * @brief Função para destruir uma agência bancária.
 * @param agencia A agência bancária a ser destruída.
 */
void DestroiAgencia(DataType agencia)
{
    tAgencia *a = agencia;
    VectorDestroy(a->contas, DestroiConta);
    free(a);
}

/**
 * @brief Função para ler uma agência bancária no formato "numero;nome".
 * @param agencia A agência bancária a ser lida.
 */
void LeAgencia(tAgencia *agencia)
{
    scanf("%d;%[^\n]\n", &agencia->n_agencia, agencia->nome);
}

/**
 * @brief Função para adicionar uma conta bancária a uma agência bancária.
 * @param agencia A agência bancária.
 * @param conta A conta bancária a ser adicionada.
 */
void AdicionaConta(tAgencia *agencia, tConta *conta)
{
    VectorPushBack(agencia->contas, conta);
}

/**
 * @brief Função para comparar um número de agência bancária com uma agência bancária.
 * @param numAgencia O número da agência bancária.
 * @param agencia2 A agência bancária a ser comparada.
 * @return 1 se os números forem iguais, 0 caso contrário.
 */
int ComparaAgencia(int numAgencia, tAgencia *agencia2)
{
    if (numAgencia == agencia2->n_agencia)
        return 1;
    else
        return 0;
}

/**
 * @brief Função para obter o saldo médio das contas de uma agência bancária.
 * @param agencia A agência bancária.
 * @return O saldo médio das contas da agência.
 */
float GetSaldoMedioAgencia(tAgencia *agencia)
{
    float soma = 0;
    int qnt_contas = VectorSize(agencia->contas);
    for (int i = 0; i < qnt_contas; i++)
    {
        soma += GetSaldoConta(VectorGet(agencia->contas, i));
    }
    return soma / qnt_contas;
}

/**
 * @brief Função para imprimir os dados de uma agência bancária (nome, número, número de contas cadastradas e saldo médio).
 * @param agencia A agência bancária.
 */
void ImprimeDadosAgencia(tAgencia *agencia)
{
    printf("    Nome: %s\n", agencia->nome);
    printf("    Numero: %d\n", agencia->n_agencia);
    printf("    Numero de contas cadastradas: %d\n", VectorSize(agencia->contas));
    printf("    Saldo médio: R$%.2f\n", GetSaldoMedioAgencia(agencia));
}