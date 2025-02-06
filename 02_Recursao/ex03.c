#include <stdio.h>
#include <stdlib.h>

int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado);

int qnt_iguais = 0;
int elem_lidos = 0;
int main()
{

    int qnt_casos;
    int procurado;
    int qnt_elementos;
    int i;
    int j;
    int vetor[100];

    scanf("%d ", &qnt_casos);

    for (i = 1; i <= qnt_casos; i++)
    {

        scanf("%d %d ", &procurado, &qnt_elementos);

        for (j = 0; j < qnt_elementos; j++)
        {
            scanf("%d ", &vetor[j]);
        }
        printf("%d\n", ContaOcorrencias(vetor, qnt_elementos, procurado));
        qnt_iguais=0;
        elem_lidos=0;
    
    }
}

int ContaOcorrencias(int *vet, int numElementos, int numeroProcurado)
{
    if (elem_lidos == numElementos)
        return qnt_iguais;

    else
    {
        if (vet[elem_lidos] == numeroProcurado)
            qnt_iguais++;

        elem_lidos++;
        ContaOcorrencias(vet, numElementos, numeroProcurado);
    }
}