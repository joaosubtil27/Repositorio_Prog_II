#include "registro.h"
#include "jogador.h"
#include "string.h"
#define MAX_JOGADOR_PARTIDA 5

/*
Função que recebe o número de um log e o caminho da pasta de logs e retorna um Registro de partida
lido do arquivo binário correspondente ao log.

@param logNum: Número do log
@param pastaLogs: Caminho da pasta de logs (já com a barra no final)
*/
Registro leRegistro(int logNum, char *pastaLogs)
{
    FILE *f;
Registro r;
Jogador j;
int i = 0;
char str[200];
sprintf(str, "%slog_%d.bin", pastaLogs, logNum);

f = fopen(str, "rb");
fread(&r.idPartida, sizeof(int), 1, f);

while (i < MAX_JOGADOR_PARTIDA)
{
    r.jogadores[i] = leJogador(f);

    i++;
}
fclose(f);
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
    Jogador j;
    j.id = -1;
    for (int i = 0; i < MAX_JOGADOR_PARTIDA; i++)
    {
        if (r.jogadores[i].id == idJog)
        {
            return r.jogadores[i];
        }
    }
    return j;
}
