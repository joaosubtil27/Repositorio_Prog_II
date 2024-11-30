
#ifndef _REGISTRO_H_
#define _REGISTRO_H_

#include "jogador.h"

#define MAX_JOGADOR_PARTIDA 5

typedef struct
{
    int idPartida;
    Jogador jogadores[MAX_JOGADOR_PARTIDA];
} Registro;

/*
Função que lê apenas um registro de partida a partir da entrada padrão. O registro de uma partida
é composto das informações de 5 jogadores. Verifique a especificação da atividade para mais detalhes.

@param idPartida: ID da partida
@return Registro: Registro de uma partida
*/
Registro leRegistro(int idPartida)
{
    Registro r;

    int id;
    r.idPartida = idPartida;
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        scanf("%d: ", &id);
        if (id == -1)
            break;
        else
        {
            r.jogadores[i] = leJogador(id);
            r.jogadores[i].valorKDA = calculaKDA(r.jogadores[i]);
        }
    }
    return r;
}

/*
Função que busca um jogador em um registro de partida a partir do ID do jogador.
Se o jogador for encontrado, ele é retornado. Caso contrário, um jogador é criado com ID -1 e retornado.

@param r: Registro de uma partida
@param idJog: ID do jogador a ser buscado
*/
Jogador buscaJogadorRegistro(Registro r, int idJog)
{
    Jogador jog_return;
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        if (r.jogadores[i].id == idJog)
            return r.jogadores[i];
    }
    jog_return.id = -1;
    return jog_return;
}

#endif
