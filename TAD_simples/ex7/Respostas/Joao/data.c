#include "data.h"

/**
 * @brief Cria uma data a partir de valores de dia, mês e ano.
 *
 * @param dia Dia da data a ser criada.
 * @param mes Mês da data a ser criada.
 * @param ano Ano da data a ser criada.
 * @return tData Data criada a partir dos valores de dia, mês e ano.
 */
tData CriaData(int dia, int mes, int ano)
{
    tData data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

/**
 * @brief Verifica se uma data é válida.
 *
 * @param data Data a ser verificada.
 * @return int 1 se a data é válida, 0 caso contrário.
 */
int VerificaDataValida(tData data)
{
    int valid = 0;

    if (data.ano >= 0 && data.mes >= 1 && data.mes <= 12 && 1 <= data.dia && data.dia <= NumeroDiasMes(data))
        valid = 1;

    return valid;
}

/**
 * @brief Imprime o mês de uma data em formato extenso.
 *
 * @param data Data cujo mês será impresso em formato extenso.
 */
void ImprimeMesExtenso(tData data)
{
    if (data.mes == 1)
        printf("Janeiro");

    else if (data.mes == 2)
        printf("Fevereiro");

    else if (data.mes == 3)
        printf("Março");

    else if (data.mes == 4)
        printf("Abril");

    else if (data.mes == 5)
        printf("Maio");

    else if (data.mes == 6)
        printf("Junho");

    else if (data.mes == 7)
        printf("Julho");

    else if (data.mes == 8)
        printf("Agosto");

    else if (data.mes == 9)
        printf("Setembro");

    else if (data.mes == 10)
        printf("Outubro");

    else if (data.mes == 11)
        printf("Novembro");

    else if (data.mes == 12)
        printf("Dezembro");
}

/**
 * @brief Imprime uma data em formato extenso.
 *
 * @param data Data a ser impressa em formato extenso.
 */
void ImprimeDataExtenso(tData data)
{
    printf("%02d de ", data.dia);
    ImprimeMesExtenso(data);
    printf(" de %04d\n", data.ano);
}

/**
 * @brief Verifica se um ano é bissexto.
 *
 * @param data Data cujo ano será verificado.
 * @return int 1 se o ano é bissexto, 0 caso contrário.
 */
int VerificaBissexto(tData data)
{

    if (data.ano % 4 == 0)
        return 1;

    else
        return 0;
}

/**
 * @brief Retorna o número de dias de um determinado mês.
 *
 * @param data Data cujo mês terá o número de dias retornado.
 * @return int Número de dias do mês da data.
 */
int NumeroDiasMes(tData data)
{

    if (data.mes == 1 || data.mes == 3 || data.mes == 5 || data.mes == 7 || data.mes == 8 || data.mes == 10 || data.mes == 12)
    {
        return 31;
    }

    else if (data.mes == 4 || data.mes == 6 || data.mes == 9 || data.mes == 11)
    {
        return 30;
    }
    else if (data.mes == 2)
    {
        if (VerificaBissexto(data) == 1)
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

/**
 * @brief Compara duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int 1 se data1 é maior que data2, -1 se data1 é menor que data2, 0 se as datas são iguais.
 * A data ser maior significa que ela é mais recente.
 */
int ComparaData(tData data1, tData data2)
{
    int valid;

    if ((data1.ano > data2.ano) || (data1.ano == data2.ano && data1.mes > data2.mes) || (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia > data2.dia))
        valid = 1;

    else if ((data1.ano < data2.ano) || (data1.ano == data2.ano && data1.mes < data2.mes) || (data1.ano == data2.ano && data1.mes == data2.mes && data1.dia < data2.dia))
        valid = -1;

    else
        valid = 0;

    return valid;
}

/**
 * @brief Calcula o número de dias até o início do mês de uma determinada data.
 *
 * @param data Data cujo número de dias até o início do mês será calculado.
 * @return int Número de dias até o início do mês da data.
 */
int CalculaDiasAteMes(tData data)
{
    int soma = 0;
    int i;
    for (i = data.mes; i <= 12; i++)
    {
        soma += NumeroDiasMes(data);
    }
    return soma;
}

/**
 * @brief Calcula a diferença em dias entre duas datas.
 *
 * @param data1 Primeira data a ser comparada.
 * @param data2 Segunda data a ser comparada.
 * @return int Número de dias entre as duas datas.
 */
int CalculaDiferencaDias(tData data1, tData data2)
{
    int soma = 0;
    tData verifica;

    if (ComparaData(data1, data2) == -1)
    {
        if (data1.ano < data2.ano)
        {
            for (int i = data1.ano + 1; i < data2.ano; i++)
            {
                soma += 365;
                verifica.ano = i;
                if (VerificaBissexto(verifica) == 1)
                {
                    soma += 1;
                }
            }
            data1.ano = data2.ano - 1;
        }
        while (1)
        {
            soma++;
            data1.dia++;

            if (data2.ano == data1.ano && data2.mes == data1.mes && data2.dia == data1.dia)
                break;

            if (data1.dia == NumeroDiasMes(data1))
            {
                data1.dia = 1;
                soma++;
                data1.mes++;
            }

            if (data1.mes > 12)
            {
                data1.mes = 1;
                data1.dia = 1;
                soma++;
                data1.ano++;
            }
        }
    }
    else if (ComparaData(data1, data2) == 1)
    {
        if (data2.ano < data1.ano)
        {
            for (int i = data2.ano + 1; i < data1.ano; i++)
            {
                soma += 365;
                verifica.ano = i;
                if (VerificaBissexto(verifica) == 1)
                {
                    soma += 1;
                }
            }
            data2.ano = data1.ano - 1;
        }

        while (1)
        {
            soma++;
            data2.dia++;

            if (data2.ano == data1.ano && data2.mes == data1.mes && data2.dia == data1.dia)
                break;

            if (data2.dia == NumeroDiasMes(data2))
            {
                data2.dia = 1;
                soma++;
                data2.mes++;
            }

            if (data2.mes > 12)
            {
                data2.mes = 1;
                data2.dia = 1;
                soma++;
                data2.ano++;
            }
        }
    }
    else if (ComparaData(data1, data2) == 0)
    {
        soma = 0;
    }

    return soma;
}
