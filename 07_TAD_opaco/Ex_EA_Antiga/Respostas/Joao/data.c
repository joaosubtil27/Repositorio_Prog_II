#include "data.h"
#include <stdlib.h>

struct Data
{
    int dia;
    int mes;
    int ano;
};

Data *leData()
{
    int dia, mes, ano;
    scanf("%d/%d/%d\n", &dia, &mes, &ano);
    Data *d = criaData(dia, mes, ano);
    return d;
}

Data *criaData(int dia, int mes, int ano)
{
    Data *d = (Data *)malloc(sizeof(Data));
    d->dia = dia;
    d->mes = mes;
    d->ano = ano;

    return d;
}

void liberaData(Data *d)
{
    free(d);
}

int calculaDiffAnosData(Data *d, Data *atual)
{
    int diff = atual->ano - d->ano;
    if (d->mes > atual->mes || (d->mes == atual->mes && d->dia > atual->dia))
        diff--;

    return diff;
}

void imprimeData(Data *d)
{

    printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
}