#include "conta.h"
#include <stdio.h>

int main()
{

    int qnt_contas;

    scanf("%d\n", &qnt_contas);
    tConta contas[qnt_contas + 1];
    char nome[50], cpf[15];
    int numero, comando;
    float valor;
    for (int i = 1; i <= qnt_contas; i++)
    {

        scanf("%d\n", &comando);
        scanf("%s", &nome);
        scanf("%s", &cpf);
        scanf("%d\n", &numero);

        if (comando == 3)
            contas[i] = CriaConta(numero, CriaUsuario(nome, cpf));
    }
    scanf("%d\n", &comando);
    while (comando != 0)
    {
        if (comando == 1 && VerificaConta(contas[numero], numero) == 1)
        {
            scanf("%d %f\n", &numero, &valor);
            contas[numero] = SaqueConta(contas[numero], valor);
        }

        if (comando == 2 && VerificaConta(contas[numero], numero) == 1)
        {
            scanf("%d %f\n", &numero, &valor);
            contas[numero] = DepositoConta(contas[numero], valor);
        }

        if (comando == 4)
        {
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 1; i <= qnt_contas; i++)
            {
                ImprimeConta(contas[i]);
            }
        }

        scanf("%d\n", &comando);
    }
}