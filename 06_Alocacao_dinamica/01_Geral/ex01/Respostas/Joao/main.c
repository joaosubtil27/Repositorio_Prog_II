#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tamanho;
    int *vetor;
    scanf("%d\n", &tamanho);

    vetor = CriaVetor(tamanho);
    LeVetor(vetor, tamanho);
    printf("%.2f\n", CalculaMedia(vetor, tamanho));
    LiberaVetor(vetor);
}