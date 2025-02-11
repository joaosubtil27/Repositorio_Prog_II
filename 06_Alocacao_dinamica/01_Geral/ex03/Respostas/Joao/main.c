#include <stdio.h>
#include <stdlib.h>
#include "utils_char.h"

int main()
{

    int tamanho;
    scanf("%d\n", &tamanho);
    char *v = CriaVetor(tamanho);
    ImprimeString(v, tamanho);
    LeVetor(v, tamanho);
    ImprimeString(v, tamanho);
    LiberaVetor(v);
}