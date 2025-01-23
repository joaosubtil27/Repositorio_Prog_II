#include "empresa.h"
#include <stdio.h>

int main()
{
    int qnt_empresas;

    scanf("%d", &qnt_empresas);

    tEmpresa empresas[qnt_empresas];

    for (int i = 0; i < qnt_empresas; i++)
    {

        empresas[i] = leEmpresa();
    }
    for (int i = 0; i < qnt_empresas; i++)
    {
        imprimeEmpresa(empresas[i]);
    }
}