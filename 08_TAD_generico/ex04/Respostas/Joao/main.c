#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

int main()
{
    tBanco *b = CriaBanco();
    tAgencia *a;
    tConta *c;
    int num_agencia;
    LeBanco(b);
    char op;
    while (1)
    {
        scanf("%c\n", &op);
        if (op == 'A')
        {
            a = CriaAgencia();
            LeAgencia(a);
            AdicionaAgencia(b, a);
        }
        else if (op == 'C')
        {
            c = CriaConta();
            LeConta(c);
            scanf("%d\n", &num_agencia);
            InsereContaBanco(b, num_agencia, c);
        }
        else if (op == 'F')
            break;
    }
    ImprimeRelatorioBanco(b);
    DestroiBanco(b);
    return 0;
}