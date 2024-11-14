#include "string_utils.h"
#include <stdio.h>
#include <stdlib.h>

void imprimeTexto();

char str[150], dest[150];

int main()
{
    int i = 0;
    int opcao = 0;

    while (1)
    {
        scanf("%c", &str[i]);
        if (str[i] == '\n')
            break;
        i++;
    }
    str[i+1] = '\0';

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

            i = 0;
            while (str[i] != '\n')
            {
                printf("%c", dest[i]);
                i++;
            }

            printf("\n\n");
        }

        else if (opcao == 3)
        {
            printf("String convertida para maiusculas: ");
            string_upper(str);

            i = 0;
            while (str[i] != '\n')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("\n\n");
        }

        else if (opcao == 4)
        {
            printf("String convertida para minusculas: ");
            string_lower(str);
            i = 0;
            while (str[i] != '\n')
            {
                printf("%c", str[i]);
                i++;
            }
            printf("\n\n");
        }

        else if (opcao == 5)
        {
            printf("String invertida: ");
            string_reverse(str);
            i = 0;
            while (str[i] != '\n')
            {
                printf("%c", str[i]);
                i++;
            }
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