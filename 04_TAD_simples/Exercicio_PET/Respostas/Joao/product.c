#include <stdbool.h>
#include <string.h>

#define MAX_NOME 100

typedef struct Product
{
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, vendas, id;
} tProduct;

tProduct leProduto()
{
    tProduct produto;
    char nome[MAX_NOME];
    float desconto, preco;
    int estoque, id;
    printf("Nome do Produto: ID: Preco: Desconto: Estoque:\n");
    int i = 0;
    while (1)
    {
        scanf("%c", &produto.nome[i]);
        if (produto.nome[i] == '\n')

            break;
        i++;
    }
    produto.nome[i] = '\0';

    scanf("%d\n", &produto.id);
    scanf("%f\n", &produto.preco);
    scanf("%f\n", &produto.desconto);
    scanf("%d\n", &produto.estoque);
    produto.vendas = 0;

    return produto;
}

tProduct criaProduto(char *nome, float desconto, float preco, int estoque, int id)
{
    tProduct produto;
    strcpy(produto.nome, nome);
    produto.desconto = desconto;
    produto.estoque = estoque;
    produto.id = id;
    produto.preco = preco;
    produto.vendas = 0;

    return produto;
}

float obtemDesconto(tProduct produto)
{
    return produto.desconto;
}

float obtempreco(tProduct produto)
{
    return produto.preco;
}

float obtemPrecoComDesconto(tProduct produto)
{
    return produto.preco - produto.preco * produto.desconto;
}

int obtemEstoque(tProduct produto)
{
    return produto.estoque;
}

int obtemVendas(tProduct produto)
{
    return produto.vendas;
}

int obtemId(tProduct produto)
{
    return produto.id;
}

tProduct aumentaEstoqueProduto(tProduct produto, int qtd)
{
    if (qtd > 0)
        produto.estoque = produto.estoque + qtd;
    else
        printf("Quantidade inválida.");

    return produto;
}

tProduct vendeProduto(tProduct produto, int qtd)
{
    if (produto.estoque >= qtd && qtd > 0)
    {
        produto.estoque = produto.estoque - qtd;
        produto.vendas = produto.vendas + qtd;
    }
    else
        printf("Quantidade inválida.");

    return produto;
}

tProduct atualizaDesconto(tProduct produto, float desconto)
{
    if (desconto >= 0 && desconto <= 1)
    {
        produto.desconto = desconto;
    }
    else
        printf("Quantidade inválida.");
    return produto;
}

bool ehMesmoId(tProduct produto, int id)
{
    if (obtemId(produto) == id)
        return true;
    else
        return false;
}

void imprimeProduto(tProduct produto)
{
    printf("Produto: ");
    int i = 0;
    while (produto.nome[i] != '\0')
    {
        printf("%c", produto.nome[i]);
        i++;
    }
    printf(", Preco atual: %.2f,", obtemPrecoComDesconto(produto));
    printf(" Qtd no estoque: %d,", obtemEstoque(produto));
    printf(" Qtd vendida: %d\n", obtemVendas(produto));
}
