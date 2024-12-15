#include <stdio.h>
#include "loja.h"

int VerificaTodosID(tLoja lojas[], int qnt_lojas_criadas, int id);
void Lenome();
int main()
{
    int qnt_lojas_possiveis;
    int qnt_lojas_criadas = 0;
    int comando = 1;
    int id, aluguel;
    int contratante;
    float valor;
    float salario, comissao;
    char nome[50];

    scanf("%d\n", &qnt_lojas_possiveis);
    tLoja lojas[qnt_lojas_possiveis];

    while (comando != 0 && qnt_lojas_criadas <= qnt_lojas_possiveis)
    {
        scanf("%d\n", &comando);
        if (comando == 1)
        {
            scanf("%d %d\n", &id, &aluguel);
            if (VerificaTodosID(lojas, qnt_lojas_criadas, id) == 1)
            {
                lojas[qnt_lojas_criadas] = AbreLoja(id, aluguel);
                qnt_lojas_criadas++;
            }
        }
        else if (comando == 2)
        {
            scanf("%s %f %f\n%d\n", &nome, &salario, &comissao, &contratante);
            lojas[contratante - 1] = ContrataVendedor(lojas[contratante - 1], RegistraVendedor(nome, salario, comissao));
        }
        else if (comando == 3)
        {
            scanf("%d %s %f\n", &id, &nome, &valor);
            int j;
            for (j=0; j<qnt_lojas_criadas; j++){
                if (VerificaIdLoja(lojas[j], id) == 1)
                break;
            }
            for (int i = 0; i < lojas[j].totalVendedores; i++)
            {
                if (VerificaNomeVendedor(lojas[j].vendedores[i], nome) == 1)
                {
                    lojas[j].vendedores[i] = ContabilizaVenda(lojas[j].vendedores[i], valor);

                    break;
                }
            }
            lojas[id] = RegistraVenda(lojas[id], nome, valor);
        }
        else if (comando == 4)
        {
            for (int i = 0; i < qnt_lojas_criadas; i++)
            {

                /*for (int j = 0; i < lojas[i].totalVendedores; i++)
                {
                    lojas[i].lucro += lojas[i].vendedores[j].valor_vendido - GetTotalRecebido(lojas[i].vendedores[j]);
                }
                lojas[i].lucro -= lojas[i].aluguel;*/

                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }

    return 0;
}

int VerificaTodosID(tLoja lojas[], int qnt_lojas_criadas, int id)
{
    int valid = 1;

    for (int i = 0; i < qnt_lojas_criadas; i++)
    {
        if (VerificaIdLoja(lojas[i], id) == 1)
            valid = 0;
    }

    return valid;
}
