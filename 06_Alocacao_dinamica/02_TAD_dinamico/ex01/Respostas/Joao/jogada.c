#include <stdio.h>
#include <stdlib.h>
#include "jogada.h"

/**
 * Aloca e retorna uma estrutura do tipo tJogada.
 * Se a alocação falhar, o programa é encerrado.
 *
 * @return a estrutura do tipo tJogada alocada.
 */
tJogada *CriaJogada()
{
    /*tJogada *jogada = (tJogada *)calloc(1, sizeof(tJogada));
    if (jogada == NULL)
    {
        DestroiJogada(jogada);
        exit(1);
    }
    // LeJogada(jogada);
    return jogada;*/
}

/**
 * Libera a memória de uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser liberada.
 */
void DestroiJogada(tJogada *jogada)
{
    free(jogada);
}

/**
 * Lê uma jogada e armazena em uma estrutura do tipo tJogada.
 *
 * @param jogada a estrutura do tipo tJogada a ser preenchida.
 */
void LeJogada(tJogada *jogada)
{

    printf("Digite uma posicao (x e y):\n");
    scanf("%d %d\n", &jogada->x, &jogada->y);
    jogada->sucesso = FoiJogadaBemSucedida(jogada);
}

/**
 * Retorna a coordenada X da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada X da jogada.
 */
int ObtemJogadaX(tJogada *jogada)
{
    return jogada->x;
}

/**
 * Retorna a coordenada Y da jogada.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return a coordenada Y da jogada.
 */
int ObtemJogadaY(tJogada *jogada)
{
    return jogada->y;
}

/**
 * Retorna 1 se a jogada foi bem sucedida e 0 caso contrário.
 *
 * @param jogada a estrutura do tipo tJogada.
 *
 * @return 1 se a jogada foi bem sucedida, 0 caso contrário.
 */
int FoiJogadaBemSucedida(tJogada *jogada)
{
   /* if (jogada->x >= 0 && jogada->x < 3 && jogada->y >= 0 && jogada->y < 3)
    {

        return 1;
    }
    else
    {
        printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", jogada->x, jogada->y);
        return 0;
    }
}