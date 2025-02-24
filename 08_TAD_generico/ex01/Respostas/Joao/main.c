#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main()
{

    int qnt_termos;
    Type tipo;
    printf("tad_gen_01\n");
    printf("Digite o tipo e numero de elementos:\n");
    scanf("%d %d", &tipo, &qnt_termos);

    tGeneric *g = CriaGenerico(tipo, qnt_termos);
    LeGenerico(g);
    ImprimeGenerico(g);
    DestroiGenerico(g);
}