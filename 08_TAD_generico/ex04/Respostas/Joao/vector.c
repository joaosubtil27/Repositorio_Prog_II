#include "vector.h"
#include <stdlib.h>

typedef void *data_type; // void pointer

#define TAM_INICIAL 5
struct Vector
{
    void **vet;
    int tam_atual;
    int tam_alocado;
};

/**
 * @brief Cria um vetor vazio
 *
 * @return A estrutura Vector inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
Vector *VectorConstruct()
{
    Vector *v = (Vector *)malloc(sizeof(Vector));
    v->tam_atual = 0;
    v->tam_alocado = TAM_INICIAL;
    v->vet = (void **)malloc(v->tam_alocado * sizeof(void *));
    if (v == NULL)
        exit(1);

    return v;
}

/**
 * @brief Adiciona um elemento no final do vetor
 *
 * @param v Ponteiro para o vetor
 * @param val Valor a ser adicionado
 */
void VectorPushBack(Vector *v, data_type val)
{
    if (v->tam_alocado == v->tam_atual)
    {
        v->tam_alocado += TAM_INICIAL;
        v->vet = (void **)realloc(v->vet, v->tam_alocado * sizeof(void *));
    }
    v->vet[v->tam_atual] = val;
    v->tam_atual++;
}

/**
 * @brief Retorna o i-ésimo elemento do vetor
 *
 * @param v Ponteiro para o vetor
 * @param i Índice do elemento
 * @return data_type Elemento do vetor
 */
data_type VectorGet(Vector *v, int i)
{
    return v->vet[i];
}

/**
 * @brief Retorna o tamanho do vetor
 *
 * @param v Ponteiro para o vetor
 * @return int Tamanho do vetor
 */
int VectorSize(Vector *v)
{
    return v->tam_atual;
}

/**
 * @brief Libera a memória alocada para o vetor
 *
 * @param v Ponteiro para o vetor
 * @param destroy Função que libera a memória alocada para cada elemento do vetor
 */
void VectorDestroy(Vector *v, void (*destroy)(data_type))
{
    for (int i = 0; i < v->tam_atual; i++)
    {
        destroy(v->vet[i]);
    }
    free(v->vet);
    free(v);
}
