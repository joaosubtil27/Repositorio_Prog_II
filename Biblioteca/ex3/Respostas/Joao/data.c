#include "data.h"
#include <stdio.h>

int verificaDataValida(int dia, int mes, int ano)
{
    if ((dia >= 1 && dia <= numeroDiasMes(mes, ano)) && (mes >= 1 && mes <= 12) && ano >= 0)
    {
        return 1;
    }
    else
        return 0;
}

void imprimeMesExtenso(int mes)
{
    if (mes == 1)
        printf("Janeiro");

    else if (mes == 2)
        printf("Fevereiro");

    else if (mes == 3)
        printf("Março");

    else if (mes == 4)
        printf("Abril");

    else if (mes == 5)
        printf("Maio");

    else if (mes == 6)
        printf("Junho");

    else if (mes == 7)
        printf("Julho");

    else if (mes == 8)
        printf("Agosto");

    else if (mes == 9)
        printf("Setembro");

    else if (mes == 10)
        printf("Outubro");

    else if (mes == 11)
        printf("Novembro");

    else if (mes == 12)
        printf("Dezembro");
}

void imprimeDataExtenso(int dia, int mes, int ano)
{
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %02d\n", ano);
}

int verificaBissexto(int ano)
{
    if (ano % 4 == 0)
        return 1;

    else
        return 0;
}

int numeroDiasMes(int mes, int ano)
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
    {
        return 31;
    }

    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
    {
        return 30;
    }
    else if (mes == 2)
    {
        if (verificaBissexto(ano) == 1)
        {
            return 29;
        }
        else
        {
            return 28;
        }
    }
    else
        return 0;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2))
        return -1;

    else if (ano1 < ano2 || (ano1 == ano2 && mes1 < mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 < dia2))
        return 1;

    else
        return 0;
}

int calculaDiasAteMes(int mes, int ano)
{
    int soma = 0;
    int i;
    for (i = mes; i <= 12; i++)
    {
        soma += numeroDiasMes(i, ano);
    }
    return soma;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int soma = 0;
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        if (ano1 < ano2)
        {
            for (int i = ano1 + 1; i < ano2; i++)
            {
                soma += 365;
                if (verificaBissexto(i) == 1)
                {
                    soma += 1;
                }
            }
        }

        if (mes1 < mes2)
        {
            if (ano1 == ano2)
            {
                for (int i = mes1 + 1; i < mes2; i++)
                {
                    soma += numeroDiasMes(i, ano1);
                }
                soma += numeroDiasMes(mes1, ano1) - dia1;
                soma += dia2;
            }
            else
            {
                soma += calculaDiasAteMes(mes1, ano1) - dia1;
                for (int i = 1; i < mes2; i++)
                {
                    soma += numeroDiasMes(i, ano2);
                }
                soma += dia2;
            }
        }

        else if (mes1 > mes2)
        {

            soma += calculaDiasAteMes(mes1, ano1) - dia1;
            for (int i = 1; i < mes2; i++)
            {
                soma += numeroDiasMes(i, ano2) + dia2;
            }
        }

        else if (mes1 == mes2)
        {
            soma += dia2 - dia1;
        }
    }

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
    {
        if (ano2 < ano1)
        {
            for (int i = ano2 + 1; i < ano1; i++)
            {
                soma += 365;
                if (verificaBissexto(i) == 1)
                {
                    soma += 1;
                }
            }
        }

        if (mes2 < mes1)
        {
            if (ano1 == ano2)
            {
                for (int i = mes2 + 1; i < mes1; i++)
                {
                    soma += numeroDiasMes(i, ano1);
                }
                soma += numeroDiasMes(mes2, ano1) - dia2;
                soma += dia1;
            }
            else
            {
                soma += calculaDiasAteMes(mes2, ano2) - dia2;
                for (int i = 1; i < mes1; i++)
                {
                    soma += numeroDiasMes(i, ano1) + dia1;
                }
            }
        }

        else if (mes2 > mes1)
        {

            soma += calculaDiasAteMes(mes2, ano2) - dia2;
            for (int i = 1; i < mes1; i++)
            {
                soma += numeroDiasMes(i, ano1) + dia1;
            }
        }

        else if (mes1 == mes2)
        {
            soma += dia1 - dia2;
        }
    }

    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 0)
        soma = 0;

    return soma;
}
