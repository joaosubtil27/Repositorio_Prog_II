#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ImprimeInvertido(char *string);

int inicio_p2 = 0;
int fim_p1 = 0;

int main()
{

    char palavras[1000];

    int i = 0;

    while (scanf("%c", &palavras[i]) != EOF)
    {
        i++;
    }
    palavras[i+1]=EOF;
    ImprimeInvertido(palavras);
}

void ImprimeInvertido(char *string)
{
    int i;

    while (string[inicio_p2] != ' ' && string[inicio_p2] != EOF)
    {   
        inicio_p2++;
    }

    for (i = inicio_p2; i >= fim_p1; i--)
    {
        printf("%c", string[i]);
    }
    
    if (string[inicio_p2+1] != EOF)
    {
        fim_p1 = inicio_p2;
        inicio_p2++;
        ImprimeInvertido(string);
    }
}