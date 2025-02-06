#ifndef _JOGO_H
#define _JOGO_H

#include "jogador.h"
#include "tabuleiro.h"

typedef struct
{
    tTabuleiro tabuleiro;
    tJogador jogador1;
    tJogador jogador2;

} tJogo;

/**
 * Cria um jogo e retorna o jogo criado.
 *
 * @return o jogo criado.
 */
tJogo CriaJogo()
{   tJogo jogo;

     jogo.tabuleiro = CriaTabuleiro();
     jogo.jogador1 = CriaJogador(ID_JOGADOR_1);
     jogo.jogador2 = CriaJogador(ID_JOGADOR_2);

    return jogo;
}

/**
 * Inicia o jogo, definindo o tabuleiro e os jogadores.
 *
 * @param jogo o jogo a ser iniciado.
 */
void ComecaJogo(tJogo jogo)
{
    jogo = CriaJogo();

}

/**
 * Verifica se o jogo acabou (se não há mais posições livres no tabuleiro).
 *
 * @param jogo o jogo atual.
 *
 * @return 1 se o jogo acabou, 0 caso contrário.
 */
int AcabouJogo(tJogo jogo)
{
    if (TemPosicaoLivreTabuleiro == 0)
        return 1;
    else
        return 0;
}

/**
 * Verifica se o usuário deseja jogar novamente.
 *
 * @return 1 se o usuário deseja jogar novamente, 0 caso contrário.
 */
int ContinuaJogo()
{
    char c;
    scanf("%c", &c);
    if (c == 's')
        return 1;

    else if (c == 'n')
        return 0;
}

#endif