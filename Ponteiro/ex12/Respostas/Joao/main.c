#include <stdio.h>
#include "vetor.h"

int adicao(int a, int b)
{
    return a + b;
}

int multiplicacao(int a, int b)
{
    return a * b;
}

int main()
{

    Vetor vet;
    Operation op;

    int soma = 0;
    int produto = 0;
    LeVetor(&vet);
    for (int i = 0; i < vet.tamanhoUtilizado; i++)
    {
        scanf("%d ", &vet.elementos[i]);
    }
    op = adicao;
    printf("Soma: %d\n", AplicarOperacaoVetor(&vet, op));
    op = multiplicacao;
    printf("Produto: %d\n", AplicarOperacaoVetor(&vet, op));

    return 0;
}