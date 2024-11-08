#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERDADEIRO 1
#define FALSO 0

int palindromo(char *string, int tamanho);

int elem_lidos = 0;
int validacao=1;
int main()
{

    int qnt_letras = 0;
    char palavra[100];
    while (scanf("%c", &palavra[qnt_letras]) != '\0')
    {
        if (palavra[qnt_letras] == '\n')
        {

            if (palindromo(palavra, qnt_letras - 1) == VERDADEIRO)
                printf("SIM\n");

            else
                printf("NAO\n");

            qnt_letras = 0;
            validacao = VERDADEIRO;
            elem_lidos = 0;
        }
        else
            qnt_letras++;
    }
}

int palindromo(char *string, int tamanho){

if (string[elem_lidos] == string[tamanho-elem_lidos]){
elem_lidos++;
validacao = palindromo(string, tamanho);
}
else 
validacao = FALSO;

return validacao;

}
