#include <stdlib.h>
#include "tabuleiro.h"
#include "jogada.h"
#include "jogador.h"
#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

/**
 * Aloca e retorna uma estrutura do tipo tjogador->
 * Se a alocação falhar, o programa é encerrado.
 *
 *  @param idJogador o ID do jogador (1 ou 2).
 *
 * @return a estrutura do tipo tJogador alocada.
 */
tJogador *CriaJogador(int idJogador)
{
    tJogador *j = (tJogador *)malloc(sizeof(tJogador));
    j->id = idJogador;
    return j;
}

/**
 * Libera a memória de uma estrutura do tipo tjogador->
 *
 * @param jogador a estrutura do tipo tJogador a ser liberada.
 */
void DestroiJogador(tJogador *jogador)
{
    free(jogador);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 */
void JogaJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    tJogada *j = CriaJogada();
    LeJogada(j);
    MarcaPosicaoTabuleiro(tabuleiro, jogador->id, j->x, j->y);
    DestroiJogada(j);
}

/**
 * Verifica se o jogador venceu o jogo.
 *
 * @param jogador o jogador atual.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador *jogador, tTabuleiro *tabuleiro)
{
    if (jogador->id == ID_JOGADOR_1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro->posicoes[i][0] == tabuleiro->peca1)
            {
                if (tabuleiro->posicoes[i][1] == tabuleiro->peca1 && tabuleiro->posicoes[i][2] == tabuleiro->peca1)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (tabuleiro->posicoes[0][1] == tabuleiro->peca1)
            {
                if (tabuleiro->posicoes[1][i] == tabuleiro->peca1 && tabuleiro->posicoes[2][i] == tabuleiro->peca1)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (i == 0 && tabuleiro->posicoes[i][0] == tabuleiro->peca1)
            {
                if (tabuleiro->posicoes[1][1] == tabuleiro->peca1 && tabuleiro->posicoes[2][2] == tabuleiro->peca1)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (i == 2 && tabuleiro->posicoes[0][2] == tabuleiro->peca1)
            {
                if (tabuleiro->posicoes[1][1] == tabuleiro->peca1 && tabuleiro->posicoes[2][0] == tabuleiro->peca1)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
        }
    }

    else if (jogador->id == ID_JOGADOR_2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro->posicoes[i][0] == tabuleiro->peca2)
            {
                if (tabuleiro->posicoes[i][1] == tabuleiro->peca2 && tabuleiro->posicoes[i][2] == tabuleiro->peca2)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (tabuleiro->posicoes[0][1] == tabuleiro->peca2)
            {
                if (tabuleiro->posicoes[1][i] == tabuleiro->peca2 && tabuleiro->posicoes[2][i] == tabuleiro->peca2)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (i == 0 && tabuleiro->posicoes[i][0] == tabuleiro->peca2)
            {
                if (tabuleiro->posicoes[1][1] == tabuleiro->peca2 && tabuleiro->posicoes[2][2] == tabuleiro->peca2)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
            else if (i == 2 && tabuleiro->posicoes[0][2] == tabuleiro->peca2)
            {
                if (tabuleiro->posicoes[1][1] == tabuleiro->peca2 && tabuleiro->posicoes[2][0] == tabuleiro->peca2)
                {
                    DestroiJogador(jogador);
                    DestroiTabuleiro(tabuleiro);
                    return 1;
                }
            }
        }
    }

    return 0;
}
