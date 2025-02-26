#include "roteiro.h"
#include "midia.h"
#include <stdio.h>
#include <stdlib.h>

#define INICIAL_MIDIA 3
struct Roteiro
{
    Midia **m;
    int qnt_midia_atual;
    int qnt_midia_alocada;
};

// Aloca dinamicamente um novo objeto Roteiro e retorna o ponteiro para ele.
// Retorna: Ponteiro para o Roteiro recém-criado.
Roteiro *roteiro_construct()
{
    Roteiro *r = (Roteiro *)malloc(sizeof(Roteiro));

    r->qnt_midia_atual = 0;
    r->qnt_midia_alocada = INICIAL_MIDIA;

    r->m = (Midia **)malloc(r->qnt_midia_alocada * sizeof(Midia *));
    return r;
}

// Aumenta o espaço de armazenamento de mídias no Roteiro, insere a nova mídia
// utilizando o construtor de mídia (midia_construct), e incrementa o contador de mídias.
// Parâmetros:
//  r       - Ponteiro para o Roteiro onde a mídia será inserida.
//  dado    - Ponteiro genérico contendo os dados da nova mídia a ser inserida.
//  print_fn - Função de impressão personalizada para a mídia.
//  free_fn  - Função de liberação personalizada para os recursos da mídia.
void roteiro_inserir_midia(Roteiro *r, void *dado, PrintFunction print_fn, FreeFunction free_fn)
{
    if (r->qnt_midia_alocada == r->qnt_midia_atual)
    {
        r->qnt_midia_alocada += INICIAL_MIDIA;
        r->m = (Midia *)realloc(r->m, r->qnt_midia_alocada * sizeof(Midia **));
    }
    r->m[r->qnt_midia_atual] = midia_construct(dado, print_fn, free_fn);
    r->qnt_midia_atual++;
}

// Imprime todas as mídias presentes no Roteiro. Se não houver mídias,
// imprime a mensagem "SEM MIDIAS PARA IMPRIMIR".
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser impresso.
void roteiro_imprimir_midias(Roteiro *r)
{
    if (r->qnt_midia_atual == 0)
    {
        printf("SEM MIDIAS PARA IMPRIMIR\n");
    }
    else
    {
        printf("IMPRIMINDO MIDIAS\n");
        for (int i = 0; i < r->qnt_midia_atual; i++)
        {
            printf("MIDIA %d: ", i + 1);
            midia_print(r->m[i]);
            printf("\n");
        }
    }
}

// Libera a memória alocada para o Roteiro e suas mídias, desalocando
// adequadamente cada um dos elementos armazenados.
// Parâmetros:
//  r - Ponteiro para o Roteiro a ser destruído.
void roteiro_destroy(Roteiro *r)
{
    for (int i = 0; i < r->qnt_midia_atual; i++)
    {
        midia_destroy(r->m[i]);
    }
    free(r->m);
    free(r);
}
