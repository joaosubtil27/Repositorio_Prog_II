#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

int string_length(char *str)
{
    int tamanho = 1;

    while (str[tamanho-1] != '\0')
    {
        if (str[tamanho-1] == '\n')
            break;
        tamanho++;
    }
    tamanho++;
    return tamanho;
}

void string_copy(char *src, char *dest)
{
    int i = 0;
    while (1)
    {
        dest[i] = src[i];
        if (src[i] == '\0')
            break;
        i++;
    }
}

void string_upper(char *str)
{
    int i = 0;

    while (str[i] != '\n')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;

        if (str[i] == '\0')
            break;
        i++;
    }
}

void string_lower(char *str)
{

    int i = 0;

    while (1)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

        if (str[i] == '\0')
            break;
        i++;
    }
}

void string_reverse(char *str)
{
    int tamanho = 0;
    int i;
    char troca;

    tamanho = string_length(str);
    tamanho = tamanho - 2;
    for (i = 0; i < tamanho / 2; i++)
    {

        troca = str[i];
        str[i] = str[tamanho - i - 1];
        str[tamanho - i - 1] = troca;
    }
}
