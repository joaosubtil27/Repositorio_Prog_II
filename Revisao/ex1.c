/*programa para verificar se o tiro atingiu o alvo
PROPOSTA REVISÃO 1
Joao Arthur
22/10/2024 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct
{

    float x, y, r;

} tInfo;

int Pitagoras(tInfo tiro, tInfo alvo);

int main()
{

    tInfo tiro, alvo;

    scanf("\n%f %f %f", &alvo.x, &alvo.y, &alvo.r);
    scanf("%f %f %f", &tiro.x, &tiro.y, &tiro.r);

    if (Pitagoras(tiro, alvo) == VERDADEIRO)
        printf("ACERTOU");

    else
        printf("ERROU");
}

int Pitagoras(tInfo tiro, tInfo alvo)
{
    int soma_r;
    int dist_origem_x;
    int dist_origem_y;

    soma_r = tiro.r + alvo.r;
    dist_origem_x = abs(tiro.x - alvo.x);
    dist_origem_y = abs(tiro.y - alvo.y);

    if (soma_r >= sqrt(pow(dist_origem_x, 2) + pow(dist_origem_y, 2)))
        return VERDADEIRO;

    else
        return FALSO;
}