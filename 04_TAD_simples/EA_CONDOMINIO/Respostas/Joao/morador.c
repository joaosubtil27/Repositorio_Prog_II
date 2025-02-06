#include <string.h>

#include "data.h"

#define MAX_TAM_NOME 100
#define MAX_TAM_RESIDENCIA 10
#define MAX_TAM_CPF 15

typedef struct
{

    char nome[MAX_TAM_NOME];
    char cpf[MAX_TAM_CPF];
    Data dataNasc;
    char idResidencia[MAX_TAM_RESIDENCIA];

} Morador;

/*
 *  Função que lê um morador de acordo com o formato de entrada descrito na
 *  especificação
 *  Retorna o Morador lido
 */
Morador lerMorador()
{
    Morador m;

    int i = 0;
    while (1)
    {
        scanf("%c", &m.nome[i]);
        if (m.nome[i] == '\n')
            break;

        i++;
    }
    m.nome[i] = '\0';
    
    i = 0;
    while (1)
    {
        scanf("%c", &m.cpf[i]);
        if (m.cpf[i] == '\n')
            break;

        i++;
    }
    m.cpf[i] = '\0';
    
    m.dataNasc = lerData();
    i = 0;
    while (1)
    {
        scanf("%c", &m.idResidencia[i]);
        if (m.idResidencia[i] == '\n')
            break;

        i++;
    }
    m.idResidencia[i] = '\0';

    return m;
}

/**
 * Função que imprime todas as informações de uma Morador conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeMorador(Morador m)
{
    printf("Nome: ");
    int i = 0;
    while (m.nome[i] != '\0')
    {
        printf("%c", m.nome[i]);
        i++;
    }

    printf("\nCPF: ");
    i = 0;
    while (m.cpf[i] != '\0')
    {
        printf("%c", m.cpf[i]);
        i++;
    }

    printf("\nData de Nascimento: ");
    imprimeData(m.dataNasc);
    printf("Residência: ");
    i = 0;
    while (m.idResidencia[i] != '\0')
    {
        printf("%c", m.idResidencia[i]);
        i++;
    }
    printf ("\n");
}

/**
 * Verifica se dois moradores são iguais. A comparação é feita usando apenas o CPF.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int comparaMorador(Morador m1, Morador m2)
{
    if (strcmp(m1.cpf, m2.cpf) == 0)
    {
        return 1;
    }
    else
        return 0;
}

/**
 * Verifica se um dado CPF pertence ao morador.
 * Se for exatamente o mesmo, retorna 1. Caso contrário, retorna 0.
 */
int verificaCPFMorador(Morador m1, char *cpf)
{
    if (strcmp(m1.cpf, cpf) == 0)
    {   
        return 1;
    }
    else
        return 0;
}

/*
 *  Função que calcula a idade de um morador em relação a uma data de referência
 *  Retorna a idade do morador em anos
 */
int calculaIdadeMorador(Morador m, Data dataRef)
{   
    return calcularDiffAnosData(m.dataNasc, dataRef);
}
