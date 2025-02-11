#include "tabuleiro.h"
#include <stdlib.h>
#include <stdio.h>
#define TAM_TABULEIRO 3
#define PECA_1 1
#define PECA_2 2

/**
 * Aloca e retorna uma estrutura do tipo tTabuleiro.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tTabuleiro alocada.
 */
tTabuleiro *CriaTabuleiro()
{
    tTabuleiro *t = (tTabuleiro*)malloc(sizeof(tTabuleiro));
    t->posicoes = (char **)malloc(TAM_TABULEIRO * sizeof(char*));
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        t->posicoes[i] = (char *)malloc(TAM_TABULEIRO * sizeof(char));
    }

    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            t->posicoes[i][j] = '-';
        }
    }
    t->peca1 = 'X';
    t->peca2 = '0';
    return t;
}

/**
 * Libera a memória de uma estrutura do tipo tTabuleiro.
 *
 * @param tabuleiro a estrutura do tipo tTabuleiro a ser liberada.
 */
void DestroiTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
        free(tabuleiro->posicoes[i]);

    free(tabuleiro->posicoes);
    free(tabuleiro);
}

/**
 * Marca uma posição do tabuleiro com a peça do jogador.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param peca a peça do jogador (1 ou 2).
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 */
void MarcaPosicaoTabuleiro(tTabuleiro *tabuleiro, int peca, int x, int y)
{
    if (peca == PECA_1)
        tabuleiro->posicoes[y][x] = tabuleiro->peca1;
    else if (peca == PECA_2)
        tabuleiro->posicoes[y][x] = tabuleiro->peca2;
}

/**
 * Verifica se há alguma posição livre no tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se há alguma posição livre, 0 caso contrário.
 */
int TemPosicaoLivreTabuleiro(tTabuleiro *tabuleiro)
{
    int valid = 0;
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            if (tabuleiro->posicoes[i][j] == '-')
                valid = 1;
        }
    }
    return valid;
}

/**
 * Verifica se a posição do tabuleiro está marcada com a peça do jogador.
 *
 * @param tabuleiro - o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 * @param peca a peça do jogador (1 ou 2).
 *
 * @return 1 se a posição está marcada com a peça do jogador, 0 caso contrário.
 */
int EstaMarcadaPosicaoPecaTabuleiro(tTabuleiro *tabuleiro, int x, int y, int peca)
{
    int valid = 0;

    if ((tabuleiro->posicoes[y][x] == 'X' && peca == PECA_1) || (tabuleiro->posicoes[y][x] == '0' && peca == PECA_2))
        valid = 1;
    return valid;
}

/**
 * Verifica se a posição do tabuleiro está livre.
 *
 * @param tabuleiro o tabuleiro atual.
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição está livre, 0 caso contrário.
 */
int EstaLivrePosicaoTabuleiro(tTabuleiro *tabuleiro, int x, int y)
{
    int valid = 0;

    if (tabuleiro->posicoes[y][x] == '-')
        valid = 1;
    return valid;
}

/**
 * Verifica se a posição do tabuleiro é válida.
 *
 * @param x a coordenada X da posição.
 * @param y a coordenada Y da posição.
 *
 * @return 1 se a posição é válida, 0 caso contrário.
 */
int EhPosicaoValidaTabuleiro(int x, int y)
{
    if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO)
        return 1;
    else
        return 0;
}

/**
 * Imprime o tabuleiro.
 *
 * @param tabuleiro o tabuleiro atual.
 */
void ImprimeTabuleiro(tTabuleiro *tabuleiro)
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%c", tabuleiro->posicoes[i][j]);
        }
        printf("\n");
    }
}
