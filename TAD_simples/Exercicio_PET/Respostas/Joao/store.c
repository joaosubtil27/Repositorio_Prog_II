
#include "product.h"

#define MAX_PRODUCTS 50

typedef struct store
{
    tProduct produtos[MAX_PRODUCTS];
    int nmProdutos, nmVendas;
    float faturamento;
} tStore;

tStore abreLoja()
{
    tStore loja;
    loja.faturamento = 0;
    loja.nmProdutos = 0;
    loja.nmVendas = 0;

    return loja;
}

tStore adicionaProduto(tStore loja, tProduct produto)
{
    loja.produtos[loja.nmProdutos] = produto;
    loja.nmProdutos++;
    return loja;
}

int buscaProduto(tStore loja, int id)
{
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        if (ehMesmoId(loja.produtos[i], id) == 1)
            return i;
    }
    return -1;
}

tStore aumentaEstoqueLoja(tStore loja, int id, int qtd)
{
    int ordem_produto = buscaProduto(loja, id);
    if (ordem_produto != -1)
    {
        loja.produtos[ordem_produto] = aumentaEstoqueProduto(loja.produtos[ordem_produto], qtd);
    }
    return loja;
}

tStore vendeProdutoLoja(tStore loja, int id, int qtd)
{
    int ordem_produto = buscaProduto(loja, id);
    if (ordem_produto != -1)
    {
        loja.produtos[ordem_produto] = vendeProduto(loja.produtos[ordem_produto], qtd);
        loja.nmVendas += qtd;
        loja.faturamento += qtd * obtemPrecoComDesconto(loja.produtos[ordem_produto]);
    }
    return loja;
}

tStore atualizaDescontoLoja(tStore loja, int id, float desconto)
{
    int ordem_produto = buscaProduto(loja, id);
    if (ordem_produto != -1)
    {
        loja.produtos[ordem_produto] = atualizaDesconto(loja.produtos[ordem_produto], desconto);
    }
    return loja;
}

void imprimeProdutosLoja(tStore loja)
{
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        imprimeProduto(loja.produtos[i]);
    }
}

void imprimeRelatorio(tStore loja)
{
    printf("RELATORIO DE VENDAS ATUALIZADO:\n");
    printf("TOTAL DE VENDAS: %d\n", loja.nmVendas);
    printf("FATURAMENTO: %.2f\n", loja.faturamento);
    printf("PRODUTOS EM ESTOQUE: %d\n", obtemEstoqueLoja(loja));
    imprimeMaisVendido(loja);
}

int obtemEstoqueLoja(tStore loja)
{
    int soma = 0;
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        soma += obtemEstoque(loja.produtos[i]);
    }
    return soma;
}

void imprimeMaisVendido(tStore loja)
{
    int venda = 0, prod_vend = 0;

    printf("PRODUTO MAIS VENDIDO:\n");
    for (int i = 0; i < loja.nmProdutos; i++)
    {
        if (loja.produtos[i].vendas > venda)
        {
            prod_vend = i;
            venda = loja.produtos[i].vendas;
        }
    }
    printf("Produto: ");
    int i = 0;
    while (loja.produtos[prod_vend].nome[i] != '\0')
    {
        printf("%c", loja.produtos[prod_vend].nome[i]);
        i++;
    }
    printf(", Preco atual: %.2f,", obtemPrecoComDesconto(loja.produtos[prod_vend]));
    printf(" Qtd no estoque: %d,", obtemEstoque(loja.produtos[prod_vend]));
    printf(" Qtd vendida: %d\n", obtemVendas(loja.produtos[prod_vend]));
}
