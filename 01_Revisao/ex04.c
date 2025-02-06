/*programa para transformar numero de base decimal em base octal
PROPOSTA REVISÃO 4
Joao Arthur
23/10/2024 */

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int num_dec, num_oct;
    int cosciente, resto;
    int digitos[100];
    int qnt_digitos;
    int i = 0;
    scanf("%d", &num_dec);

    if (num_dec % 8 != 0)
    {
        resto = num_dec % 8;
        cosciente = (num_dec - resto) / 8;
        digitos[i] = resto;
        i++;
    }

    while (cosciente >= 8)
    {
        resto = cosciente % 8;
        cosciente = (cosciente - resto) / 8;
        digitos[i] = resto;
        i++;
    }

    if (cosciente > 0)
        digitos[i] = cosciente;
    
    qnt_digitos=i;
    for (i=qnt_digitos; i>=0; i--){
     printf ("%d", digitos[i]);
    }
}