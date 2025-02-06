
#include "vendedor.h"

#define MAX_VENDEDORES 10 /**< Número máximo de vendedores que uma loja pode ter */

typedef struct Loja
{
    int id;                               /**< ID da loja */
    int totalVendedores;                  /**< Número total de vendedores da loja */
    float aluguel;                        /**< Valor do aluguel da loja */
    float lucro;                          /**< Lucro da loja */
    tVendedor vendedores[MAX_VENDEDORES]; /**< Vetor de vendedores da loja */
} tLoja;


tLoja AbreLoja(int id, float aluguel)
{

    tLoja loja;
    loja.id = id;
    loja.aluguel = aluguel;
    loja.totalVendedores = 0;
    loja.lucro = 0;

    return loja;
}


int VerificaIdLoja(tLoja loja, int id)
{
    if (loja.id == id)
        return 1;
    else
        return 0;
}


tLoja ContrataVendedor(tLoja loja, tVendedor vendedor)
{
    loja.vendedores[loja.totalVendedores] = vendedor;
    loja.totalVendedores++;
    return loja;
}


tLoja RegistraVenda(tLoja loja, char nome[50], float valor)
{
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        if (VerificaNomeVendedor(loja.vendedores[i], nome) == 1)
        {   
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            
            break;
        }
    }

    return loja;
}


tLoja CalculaLucro(tLoja loja)
{
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        loja.lucro += loja.vendedores[i].valor_vendido - GetTotalRecebido(loja.vendedores[i]);
    }
    loja.lucro -= loja.aluguel;
    return loja;
}


void ImprimeRelatorioLoja(tLoja loja)
{
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);

    for (int i = 0; i < loja.totalVendedores; i++)
    {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}
