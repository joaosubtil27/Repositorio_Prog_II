
#ifndef _SERVIDOR_H_
#define _SERVIDOR_H_

#include "registro.h"

#define MAX_PARTIDAS 1000

typedef struct
{
    Registro partidas[MAX_PARTIDAS];
    int nPartidas;
} Servidor;

/*
Função que lê todos os registros de partidas de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de partidas lidos. Conforme a especificação da atividade, a leitura é encerrada quando
um ID de partida igual a -1 é lido.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor()
{

    Servidor serv;
    serv.nPartidas = 0;
    int idPartida;
    while (1)
    {
        scanf("%d\n", &idPartida);
        if (idPartida == -1)
            break;

        serv.partidas[serv.nPartidas].idPartida = idPartida;
        serv.partidas[serv.nPartidas] = leRegistro(idPartida);
        serv.nPartidas++;
    }
    return serv;
}

/*
Função que recebe um servidor já preenchido com os dados de todas as partidas e um ID de jogador.
A partir dessas informações, ela busca as estatísticas do jogador em todas as partidas que ele participou.
Se o jogar não for encontrado, um jogador com ID -1 é criado e retornado.
Se o jogador for encontrado em apenas uma partida, ele é retornado.
Se o jogador for encontrado em mais de uma partida, suas estatísticas são agregadas e o jogador é retornado.

@param s: Servidor
@param idJog: ID do jogador
*/
Jogador buscaDadosJogadorServidor(Servidor s, int idJog)
{
    int i = 0;
    int qnt_aparicoes = 0;
    Jogador jog_return, jog_busca;
    jog_return.id = -1;

    for (i = 0; i < s.nPartidas; i++)
    {
        jog_busca = buscaJogadorRegistro(s.partidas[i], idJog);
        if (jog_busca.id != -1)
        {
            qnt_aparicoes++;
            if (qnt_aparicoes > 1)
                jog_return = atualizaJogador(jog_return, idJog, jog_busca.kills, jog_busca.deaths, jog_busca.assists);
            else
                jog_return = jog_busca;
        }
    }
    return jog_return;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(Servidor s)
{
    int qnt_jog;
    int idJog;
    Jogador jog;
    scanf("%d\n", &qnt_jog);

    while (qnt_jog > 0)
    {
        scanf("%d", &idJog);

        jog = buscaDadosJogadorServidor(s, idJog);

        if (jog.id == -1)
            printf("Jogador %d: -\n", idJog);

        else if (jog.id == idJog)
            printaJogador(jog);

        qnt_jog--;
    }
}

#endif
