#include "ponto.h"
#include <math.h>
#include <stdlib.h>
/********************************************************************
    TAD: Ponto (x,y)

********************************************************************/
/* TAD Opaco */
struct ponto
{
    float x;
    float y;
};

/* Funcoes exportadas */

/**
 * @brief Cria uma variável do tipo Ponto
 * @param x o valor da coordenada x do ponto
 * @param y o valor da coordenada y do ponto
 * @return A variável do tipo Ponto criada
 */
tPonto Pto_Cria(float x, float y)
{
    tPonto p = (tPonto) malloc(sizeof(tPonto));;
    p->x = x;
    p->y = y;
    return p;
}

/**
 * @brief Apaga (Libera a memória) alocada pelo ponto
 * @param p A variável do tipo ponto que será apagada e terá sua memória liberada
 */
void Pto_Apaga(tPonto p)
{
    free(p);
}

/**
 * @brief Função que acessa a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada x de um ponto p
 */
float Pto_Acessa_x(tPonto p)
{
    return p->x;
}

/**
 * @brief Função que acessa a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @return O valor da coordenada y de um ponto p
 */
float Pto_Acessa_y(tPonto p)
{
    return p->y;
}

/**
 * @brief Função que atribui a coordenada "x" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param x O novo valor da coordenada x do ponto p
 */
void Pto_Atribui_x(tPonto p, float x)
{
    p->x = x;
}

/**
 * @brief Função que atribui a coordenada "y" do ponto p
 * @param p A variável que representa um ponto qualquer
 * @param y O novo valor da coordenada y do ponto p
 */
void Pto_Atribui_y(tPonto p, float y)
{
    p->y = y;
}

/**
 * @brief Função que calcula a distância euclidiana entre dois pontos: p1 e p2
 * @param p1 A variável que representa um primeiro ponto
 * @param p2 A variável que representa um segundo ponto
 * @return A distância euclidiana entre p1 e p2
 */
float Pto_Distancia(tPonto p1, tPonto p2)
{

    return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));
}
