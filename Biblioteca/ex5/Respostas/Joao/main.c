#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

void imprimeTexto();

int main()
{
    int i = 0;
    int opcao = 0;
    char str[100], dest[100];

    while (scanf("%c", &str[i]) != '\n')
    {
        i++;
    }
    imprimeTexto();
    while (opcao != 6)
    {
        imprimeTexto();
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            printf("Tamanho da string: %d\n", string_length(str));
        }

        else if (opcao == 2)
        {
            printf("String copiada: ");
            string_copy(str, dest);
            printf("\n\n");
        }

        else if (opcao == 3)
        {
            printf("String convertida para maiusculas: ");
            string_upper(str);
            printf("\n\n");
        }

        else if (opcao == 4)
        {
            printf("String convertida para minusuclas: ");
            string_lower(str);
            printf("\n\n");
        }

        else if (opcao == 5)
        {
            printf("String invertida: ");
            string_reverse(str);
            printf("\n\n");
        }

        else if (opcao == 6)
            break;
    }
    return 0;
}

void imprimeTexto()
{
    printf("1 - Tamanho da string\n");
    printf("2 - Copiar string\n");
    printf("3 - Converter string para letras maiusculas\n");
    printf("4 - Converter string para letras minusculas\n");
    printf("5 - Imprimir string ao contrario\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}