/*programa para montar o triangulo de Floyd
PROPOSTA REVISÃO 3
Joao Arthur
23/10/2024 */

#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

int main()
{

    int qnt_livros;
    int cod_livros[1000];
    int i, j;
    int verif_igual;

    scanf("%d", &qnt_livros);

    for (i = 0; i < qnt_livros; i++)
    {

        scanf(" %d", &cod_livros[i]);
    }

    for (j = 0; j < qnt_livros; j++)
    {
        for (i = 0; i < qnt_livros; i++)
        {
            if (cod_livros[j] == cod_livros[i] && i!=j){
                verif_igual = VERDADEIRO;
                break;
        }
            else
                verif_igual = FALSO;
        }

        if (verif_igual == FALSO)
            printf("%d ", cod_livros[j]);
    }
}