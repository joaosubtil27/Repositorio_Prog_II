#include "tadgen.h"
#include <stdlib.h>
#include <stdio.h>
struct generic
{
    int tam;
    void *dado;
    Type tipo;
};

/**
 * @brief Cria uma estrutura genérica e dinâmica que pode armazenar tanto inteiros quanto floats
 *
 * @param type - Tipo do vetor genérico. Segue o Enum definido acima.
 * @param numElem A quantidade de elementos que serão armazenados no vetor
 *
 * @return O vetor genérico
 */
tGeneric *CriaGenerico(Type type, int numElem)
{
    tGeneric *g = (tGeneric *)malloc(sizeof(tGeneric));
    g->tam = numElem;
    g->tipo = type;
    switch (g->tipo)
    {
    case INT:
        g->dado = (int *)malloc(g->tam * sizeof(int));
        break;
    case FLOAT:
        g->dado = (float *)malloc(g->tam * sizeof(float));
        break;
    }
    return g;
}

/**
 * @brief Destroi o vetor genérico (libera a memória alocada dinamicamente)
 *
 * @param gen - O vetor genérico que terá seu conteúdo liberado/destruído
 */
void DestroiGenerico(tGeneric *gen)
{
    free(gen->dado);
    free(gen);
}

/**
 * @brief Lê o conteúdo do vetor genérico e salva no local adequado
 *
 * @param gen - O vetor genérico que terá seu conteúdo preenchido/lido
 */
void LeGenerico(tGeneric *gen)
{
        printf("\nDigite o vetor:\n");
        switch (gen->tipo)
        {
        case INT:
        for (int i = 0; i < gen->tam; i++)
        {
            scanf("%d ", (int*)gen->dado+i);
        }
            break;
        case FLOAT:
        for (int i = 0; i < gen->tam; i++)
        {
            scanf("%f ", (float*)gen->dado+i);
        }
            break;
        }
    
}

/**
 * @brief Busca uma conta na agencia que possui um id específico
 *
 * @param gen - O vetor genérico que terá seu conteúdo impresso em tela
 */
void ImprimeGenerico(tGeneric *gen)
{
    switch (gen->tipo)
    {
    case INT:
    for (int i = 0; i < gen->tam; i++)
    {
        printf("%d ", *((int*)gen->dado+i));
    }
        break;
    case FLOAT:
    for (int i = 0; i < gen->tam; i++)
    {
        printf("%.2f ", *((float*)gen->dado+i));
    }
        break;
    }
}
