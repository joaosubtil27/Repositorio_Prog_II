#include "lesao.h"
#include <stdlib.h>
#include <stdio.h>
struct Lesao
{
    char *id;        // salva o id da lesão
    char *diag;      // salva o diagnóstico da lesão
    char *regiao;    // salva a região da lesão
    int malignidade; // salva o grau de malignidade da lesão
};


Lesao *leLesao()
{
    Lesao *l = (Lesao *)malloc(sizeof(Lesao));
    l->id = (char *)malloc(TAM_ID * sizeof(char));
    l->diag = (char *)malloc(TAM_DIAG * sizeof(char));
    l->regiao = (char *)malloc(TAM_REG * sizeof(char));

    scanf("%[^\n]\n", l->id);
    scanf("%[^\n]\n", l->diag);
    scanf("%[^\n]\n", l->regiao);
    scanf("%d\n", &l->malignidade);

    return l;
}

void liberaLesao(Lesao *l)
{
    free(l->id);
    free(l->diag);
    free(l->regiao);
    free(l);
}


char *getIdLesao(Lesao *l)
{
    return l->id;
}


int precisaCirurgiaLesao(Lesao *l)
{
    if (l->malignidade > 50)
        return 1;
    else
        return 0;
}
