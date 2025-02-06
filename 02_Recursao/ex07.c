#include <stdio.h>
#include <stdlib.h>

int somaDigitos(int n);
int soma = 0;
int main()
{

    int n;

    scanf("%d", &n);
    printf("%d", somaDigitos(n));

    return 0;
}

int somaDigitos(int n)
{

    if (n >= 10)
    {
        soma += (n - 10*(n / 10));
        n = n / 10;
        somaDigitos(n);
    }

    else if (n < 10)
    {
        soma += n;
    }

    return soma;
}