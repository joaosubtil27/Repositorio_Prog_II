#include <stdio.h>
#include <stdlib.h>
#include "pacote.h"

struct pacote
{
    Type tipo;
    int tam;
    int soma_termos;
    void *vetor;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar um pacote a ser transmitido
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tPacote *CriaPacote(Type type, int numElem)
{
    tPacote *p = (tPacote *)malloc(sizeof(tPacote));
    p->tipo = type;
    p->soma_termos = 0;
    p->tam = numElem;
    switch (p->tipo)
    {
    case INT:
        p->vetor = (int *)malloc(p->tam * sizeof(int));
        break;
    case CHAR:
        p->vetor = (char *)malloc((p->tam+1)* sizeof(char));
        break;
    }
    return p;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param pac - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiPacote(tPacote *pac)
{
    free(pac->vetor);
    free(pac);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param pac - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LePacote(tPacote *pac)
{
    printf("\nDigite o conteúdo do vetor/mensagem:");
    scanf("%*c");
    switch (pac->tipo)
    {
    case INT:
        for (int i = 0; i < pac->tam; i++)
        {
            scanf("%d ", (int *)pac->vetor + i);
        }
        scanf("\n");
        break;
    case CHAR:
        scanf("%[^\n]\n", (char *)pac->vetor);
        break;
    }
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param pac - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimePacote(tPacote *pac)
{
    CalculaSomaVerificacaoPacote(pac);
    printf("%d ", pac->soma_termos);
    switch (pac->tipo)
    {
    case INT:
        for (int i = 0; i < pac->tam; i++)
        {
            printf("%d ", *((int *)pac->vetor + i));
        }
        printf("\n");
        break;
    case CHAR:
        printf("%s\n", ((char *)pac->vetor));
        break;
    }
}

/**
 * @brief Calcula a soma de verificacao de um pacote e a armazena internamente
 *
 * @param pac - O vetor genérico que terá sua soma de verificacao calculada
 */
void CalculaSomaVerificacaoPacote(tPacote *pac)
{
    switch (pac->tipo)
    {
    case INT:
        for (int i = 0; i < pac->tam; i++)
        {
            pac->soma_termos += *((int *)pac->vetor + i);
        }
        break;
    case CHAR:
        for (int i = 0; i < pac->tam; i++)
        {
            pac->soma_termos += (int)*((char *)pac->vetor + i);
        }
        break;
    }
}
