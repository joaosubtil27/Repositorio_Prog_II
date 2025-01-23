#include <stdio.h>
#include <string.h>
#include "pessoa.h"

int main()
{
    int qnt_pessoas;
    scanf("%d", &qnt_pessoas);

    tPessoa pessoas[qnt_pessoas];

    for (int i = 0; i < qnt_pessoas; i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }

    AssociaFamiliasGruposPessoas(pessoas);

    for (int i = 0; i < qnt_pessoas; i++)
    {

        ImprimePessoa(&pessoas[i]);
    }
}