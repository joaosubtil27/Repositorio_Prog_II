#include <stdio.h>
#include <stdlib.h>
#include "utils_char2.h"
#include <string.h>

int main()
{

    char *v = CriaVetorTamPadrao();
    int tamanho = strlen(v);
    v = LeVetor(v, &tamanho);
    ImprimeString(v);
    LiberaVetor(v);
}