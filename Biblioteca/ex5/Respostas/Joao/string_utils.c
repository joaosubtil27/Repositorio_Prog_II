#include "string_utils.h"
#include <stdio.h>

int string_length(char *str)
{
    int tamanho = 0;
    while (str[tamanho] != '\n')
    {
        tamanho++;
    }
    return tamanho;
}

void string_copy(char *src, char *dest)
{
    int i = 0;
    int tamanho;
    while (src[i] != '\n')
    {
        dest[i] = src[i];
        printf("%c", dest[i]);
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

        printf("%c", str[i]);
        i++;
    }
}

void string_lower(char *str)
{

    int i = 0;

    while (str[i] != '\n')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;

        printf("%c", str[i]);
        i++;
    }
}

void string_reverse(char *str)
{
    int i;
    int tamanho;
    char troca;

    tamanho = string_length(str);

    for (i = 0; i < tamanho; i++)
    {
        troca = str[i];
        str[i] = str[tamanho - i];
        str[tamanho - i] = troca;
        printf("%c", str[i]);
    }
}
