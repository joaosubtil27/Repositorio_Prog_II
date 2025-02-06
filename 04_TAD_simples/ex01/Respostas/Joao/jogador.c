#ifndef _JOGADOR_H
#define _JOGADOR_H

#include "tabuleiro.h"

#define ID_JOGADOR_1 1
#define ID_JOGADOR_2 2

typedef struct
{
    int id;
} tJogador;

/**
 * Cria um jogador com o id passado como parâmetro e retorna o jogador criado.
 *
 * @param idJogador o id do jogador (1 ou 2).
 *
 * @return tJogador o jogador criado.
 */
tJogador CriaJogador(int idJogador)
{
    tJogador jogador;
    if (idJogador == ID_JOGADOR_1)
        jogador.id = ID_JOGADOR_1;

    else if (idJogador == ID_JOGADOR_2)
        jogador.id = ID_JOGADOR_2;

    return jogador;
}

/**
 * Recebe um jogador e um tabuleiro e retorna o tabuleiro com a jogada do jogador.
 *
 * @param jogador o jogador que fará a jogada.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return o tabuleiro atualizado com a jogada do jogador.
 */
tTabuleiro JogaJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    if (jogador.id == ID_JOGADOR_1)
        tabuleiro.peca1 = 'X';
    if (jogador.id == ID_JOGADOR_2)
        tabuleiro.peca2 = '0';

    return tabuleiro;
}

/**
 * Recebe um jogador e um tabuleiro e retorna 1 se o jogador venceu e 0 caso contrário.
 *
 * @param jogador o jogador a ser verificado.
 * @param tabuleiro o tabuleiro atual.
 *
 * @return 1 se o jogador venceu, 0 caso contrário.
 */
int VenceuJogador(tJogador jogador, tTabuleiro tabuleiro)
{
    if (jogador.id == ID_JOGADOR_1)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro.posicoes[i][0] == tabuleiro.peca1)
            {
                if (tabuleiro.posicoes[i][1] == tabuleiro.peca1 && tabuleiro.posicoes[i][2] == tabuleiro.peca1)
                    return 1;
            }
            else if (tabuleiro.posicoes[0][1] == tabuleiro.peca1)
            {
                if (tabuleiro.posicoes[1][i] == tabuleiro.peca1 && tabuleiro.posicoes[2][i] == tabuleiro.peca1)
                    return 1;
            }
            else if (i == 0 && tabuleiro.posicoes[i][0] == tabuleiro.peca1)
            {
                if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][2] == tabuleiro.peca1)
                    return 1;
            }
            else if (i == 2 && tabuleiro.posicoes[0][2] == tabuleiro.peca1)
            {
                if (tabuleiro.posicoes[1][1] == tabuleiro.peca1 && tabuleiro.posicoes[2][0] == tabuleiro.peca1)
                    return 1;
            }
        }
    }

    else if (jogador.id == ID_JOGADOR_2)
    {
        for (int i = 0; i < 3; i++)
        {
            if (tabuleiro.posicoes[i][0] == tabuleiro.peca2)
            {
                if (tabuleiro.posicoes[i][1] == tabuleiro.peca2 && tabuleiro.posicoes[i][2] == tabuleiro.peca2)
                    return 1;
            }
            else if (tabuleiro.posicoes[0][1] == tabuleiro.peca2)
            {
                if (tabuleiro.posicoes[1][i] == tabuleiro.peca2 && tabuleiro.posicoes[2][i] == tabuleiro.peca2)
                    return 1;
            }
            else if (i == 0 && tabuleiro.posicoes[i][0] == tabuleiro.peca2)
            {
                if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][2] == tabuleiro.peca2)
                    return 1;
            }
            else if (i == 2 && tabuleiro.posicoes[0][2] == tabuleiro.peca2)
            {
                if (tabuleiro.posicoes[1][1] == tabuleiro.peca2 && tabuleiro.posicoes[2][0] == tabuleiro.peca2)
                    return 1;
            }
        }
    }

    return 0;
}

#endif