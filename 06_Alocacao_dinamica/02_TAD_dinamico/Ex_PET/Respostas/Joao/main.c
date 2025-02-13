#include "conta.h"
#include "usuario.h"
#include <stdio.h>
#include <stdlib.h>

#define QTD_CONTAS 10
#define TAM_STR 20

void Imprime_Relatorio_Individual(Conta *conta);

int main()
{

    Conta *contas[QTD_CONTAS];
    char nome[TAM_STR];

    int op;
    int qnt_contas = 0;
    int cpf, n_conta, qnt_transacoes;
    float valor;
    int ori, dest;
    while (1)
    {
        scanf("%d\n", &op);

        if (op == 0)
        {
            break;
        }
        else if (op == 1)
        {
            scanf("%d %f\n", &n_conta, &valor);
            Saque(BuscaConta(contas, qnt_contas, n_conta), valor);
        }
        else if (op == 2)
        {
            scanf("%d %f\n", &n_conta, &valor);
            Deposito(BuscaConta(contas, qnt_contas, n_conta), valor);
        }
        else if (op == 3)
        {
            scanf("%d %d %f\n", &ori, &dest, &valor);
            Transferencia(BuscaConta(contas, qnt_contas, ori), BuscaConta(contas, qnt_contas, dest), valor);
        }
        else if (op == 4)
        {
            scanf("%s %d %d\n", nome, &cpf, &n_conta);
            contas[qnt_contas] = CriaConta(CriaUsuario(nome, cpf), n_conta);
            qnt_contas++;
        }
        else if (op == 5)
        {
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < qnt_contas; i++)
            {
                Imprime_Relatorio_Individual(contas[i]);
            }
        }
        else if (op == 6)
        {
            scanf("%d %d", &n_conta, &qnt_transacoes);

            printf("===| Imprimindo Extrato |===\n");
            Imprime_Relatorio_Individual(BuscaConta(contas, qnt_contas, n_conta));

            if (qnt_transacoes <= BuscaConta(contas, qnt_contas, n_conta)->qtdMovimentacoes)
            {

                printf("Ultimas %d transações\n", qnt_transacoes);

                for (int j = BuscaConta(contas, qnt_contas, n_conta)->qtdMovimentacoes - 1; j >= BuscaConta(contas, qnt_contas, n_conta)->qtdMovimentacoes - qnt_transacoes; j--)
                {
                    printf("%.2f\n", BuscaConta(contas, qnt_contas, n_conta)->movimentacoes[j]);
                }
            }
            else
            {
                printf("Ultimas %d transações\n", BuscaConta(contas, qnt_contas, n_conta)->qtdMovimentacoes);

                for (int j = BuscaConta(contas, qnt_contas, n_conta)->qtdMovimentacoes - 1; j >= 0; j--)
                {
                    printf("%.2f\n", BuscaConta(contas, qnt_contas, n_conta)->movimentacoes[j]);
                }
            }
            printf("\n");
        }
    }
    for (int i = 0; i < qnt_contas; i++)
    {
        DestroiUsuario(contas[i]->usuario);
        DestroiConta(contas[i]);
    }

    return 0;
}

void Imprime_Relatorio_Individual(Conta *conta)
{
    printf("Conta: %d\n", conta->nConta);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    printf("Nome: %s\n", conta->usuario->nome);
    printf("CPF: %d\n\n", conta->usuario->cpf);
}