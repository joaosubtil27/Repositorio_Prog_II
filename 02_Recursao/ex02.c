#include <stdio.h>
#include <stdlib.h>

int SomaElementosPares(int *vet, int numElementos);

int soma_pares = 0;
int elem_lidos = 0;
int main()
{

    int qnt_vet;
    int i;
    int j;
    int vetor[100];
    int qnt_elementos;

    scanf("%d ", &qnt_vet);

    for (j = 1; j <= qnt_vet; j++)
    {
        scanf("%d ", &qnt_elementos);

        for (i = 0; i < qnt_elementos; i++)
        {
            scanf("%d ", &vetor[i]);
        }
        printf("%d\n", SomaElementosPares(vetor, qnt_elementos));
        soma_pares = 0;
        elem_lidos = 0;
    }
}

int SomaElementosPares(int *vet, int numElementos)
{
    if (elem_lidos == numElementos)
        return soma_pares;

    else
    {   if (vet[elem_lidos]%2 == 0)
        soma_pares += vet[elem_lidos];

        elem_lidos++;
        SomaElementosPares(vet, numElementos);
    }
}