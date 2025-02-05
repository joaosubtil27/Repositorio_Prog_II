#define MAXTAM_NOME 100
#define MAXTAM_PRISIONEIRO 100

#include "stdlib.h"
#include "stdio.h"
#include "string.h"

typedef struct
{
    char nome[MAXTAM_NOME];
    int pena;
    int tempoPassado;
} tPrisioneiro;

/**
 * @brief Cria o prisioneiro a partir dos parâmetros fornecidos
 * @param nome Nome do prisioneiro
 * @param pena Pena a ser cumprida pelo prisioneiro
 */
tPrisioneiro criaPrisioneiro(char *nome, int pena)
{

    tPrisioneiro prisioneiro;
    strcpy(prisioneiro.nome, nome);
    prisioneiro.pena = pena;
    prisioneiro.tempoPassado = 0;

    return prisioneiro;
}

/**
 * @brief Aumenta o tempo passado do prisioneiro
 */
void passaTempoPrisioneiro(tPrisioneiro *prisioneiro)
{
    prisioneiro->tempoPassado++;
}

/**
 * @brief Imprime a fuga do prisioneiro na tela e chama a função de desalocação
 */
void fogePrisioneiro(tPrisioneiro *prisioneiro)
{
    printf("Detento %s fugiu!\n", prisioneiro->nome);
}

/**
 * @brief Retorna 1 quando a pena do prisioneiro termina
 */
int acabouPenaPrisioneiro(tPrisioneiro *prisioneiro)
{
    if (prisioneiro->pena <= prisioneiro->tempoPassado)
        return 1;
    else
        return 0;
}

/**
 * @brief Imprime a liberação do prisioneiro na tela
 */
void liberaPrisioneiroCumpriuPena(tPrisioneiro *prisioneiro)
{
    printf("Detento %s cumpriu sua pena e foi liberado\n", prisioneiro->nome);
}

/**
 * @brief Imprime a liberação do prisioneiro na tela para encerrar o programa
 */
void liberaPrisioneiroFimPrograma(tPrisioneiro *prisioneiro)
{
    printf("Detento %s liberado para finalizar programa\n", prisioneiro->nome);
}
