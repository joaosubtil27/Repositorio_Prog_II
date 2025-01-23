#include "data.h"
#include <stdio.h>
#include <stdlib.h>
// AINDA NAO ESTA DANDO CERTO
int main()
{
    tData data1, data2;
    int dia, mes, ano;

    scanf("%d/%d/%d", &dia, &mes, &ano);
    data1 = CriaData(dia,mes,ano);

    scanf("%d/%d/%d", &dia, &mes, &ano);
    data2 = CriaData(dia,mes,ano);

    if (VerificaDataValida(data1) == 1 && VerificaDataValida(data2) == 1)
    {

        printf("Primeira data: ");
        ImprimeDataExtenso(data1);
        printf("Segunda data: ");
        ImprimeDataExtenso(data2);

        if (ComparaData(data1, data2) == -1)
            printf("A primeira data eh mais antiga\n");

        else if (ComparaData(data1, data2) == 1)
            printf("A segunda data eh mais antiga\n");

        else if (ComparaData(data1, data2) == 0)
            printf("As datas sao iguais\n");

        printf("A diferenca em dias entre as datas eh: %02d dias\n", CalculaDiferencaDias(data1, data2));
    }
    else
        printf("A primeira e/ou segunda data(s) invalida(s)\n");

    return 0;
}