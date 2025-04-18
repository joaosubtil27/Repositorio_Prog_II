#include "servidor.h"
#include "registro.h"

#define MAX_PARTIDAS 1000
#define PASTA_LOGS "logs_partidas/"

/*
Função que lê todos os registros de partidas de um servidor a partir da entrada padrão e retorna um servidor
com todos os registros de partidas lidos. Conforme a especificação da atividade.

@return Servidor: Servidor com todos os registros de partidas lidos
*/
Servidor leRegistrosServidor()
{
    Servidor s;
    scanf("%d", &s.nPartidas);
    for (int i = 0; i < s.nPartidas; i++)
    {
        s.partidas[i] = leRegistro(i, PASTA_LOGS);
    }
    return s;
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
    Jogador j, r;
    r = inicializaJogador(-1);
    int valid = 0;
    for (int i = 0; i < s.nPartidas; i++)
    {
        j = buscaJogadorRegistro(s.partidas[i], idJog);
        if (j.id != -1)
        {
            r = atualizaJogador(r, j.id, j.kills, j.deaths, j.assists);
        }
    }

    return r;
}

/*
Função que recebe um servidor já criado e preenchido e imprime um relatório com as estatísticas de um conjunto de jogadores
solicitados a partir da entrada padrão. O relatório é impresso conforme o formato especificado na descrição da atividade.
*/
void criaRelatorioServidor(Servidor s)
{
    int qnt_procura;
    int num;
    Jogador j;
    scanf("%d\n", &qnt_procura);

    for (int i = 0; i < qnt_procura; i++)
    {
        scanf("%d\n", &num);
        j = buscaDadosJogadorServidor(s, num);
        if (j.id == -1)
            printf("Jogador %d: -\n", num);
        else
            printaJogador(j);
    }
}
