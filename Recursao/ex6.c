#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);
int t0 = 0;
int t1 = 1;
int termo_lido = 1;
int main()
{

    int n;

    scanf("%d", &n);
    printf("%d", fibonacci(n));

    return 0;
}

int fibonacci(int n)
{
    int valor;

    if (n == 0)
        valor = 0;

    if (n == 1)
        valor = 1;

    else if (termo_lido <= n)
    {
        if (termo_lido % 2 == 0)
        {
            t0 = t1 + t0;
            valor = t0;
        }

        else
        {
            t1 = t0 + t1;
            valor = t1;
        }

        termo_lido++;
        if (termo_lido <= n)
        valor = fibonacci(n);
    }

    return valor;
}