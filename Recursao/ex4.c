#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
// AINDA HA ALGO DE ERRADO NOS EXEMPLOS
int palindromo(char *string, int tamanho);

int elem_lidos = 0;
int validacao = VERDADEIRO;
int main()
{

    int qnt_letras = 0;
    char palavra[100];

    while (palavra[qnt_letras] != EOF)
    {
        scanf("%c", &palavra[qnt_letras]);

        if (palavra[qnt_letras] == '\n' || palavra[qnt_letras] == EOF)
        {

            if (palindromo(palavra, qnt_letras - 1) == VERDADEIRO)
                printf("SIM\n");

            else
            {
                printf("NAO\n");
            }

            qnt_letras = 0;
            validacao = VERDADEIRO;
            elem_lidos = 0;
        }
        else
            qnt_letras++;
    }
    return 0;
}

int palindromo(char *string, int tamanho)
{

    if (string[elem_lidos] == string[tamanho] && elem_lidos <= tamanho)
    {
        elem_lidos++;
        validacao = palindromo(string, tamanho - 1);
    }
    else if (string[elem_lidos] != string[tamanho] && elem_lidos <= tamanho)
    {
        validacao = FALSO;
    }

    return validacao;
}
