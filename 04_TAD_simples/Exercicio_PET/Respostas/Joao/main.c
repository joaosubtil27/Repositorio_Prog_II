#include <stdio.h>
#include "store.h"

void Imprime_Menu();

int main()
{

    tStore loja;
    tProduct produto;
    loja = abreLoja();
    char c = 1;
    int id, qtd;
    float desconto;
    while (scanf("%c\n", &c) != 'F')
    {
        Imprime_Menu();
        if (c == 'C')
        {
            produto = leProduto();
            loja = adicionaProduto(loja, criaProduto(produto.nome, produto.desconto, produto.preco, produto.estoque, produto.id));
        }
        else if (c == 'E')
        {
            printf("Digite o id do Produto: Digite o numero de unidades: ");
            scanf("%d\n%d\n", &id, &qtd);
            loja = aumentaEstoqueLoja(loja, id, qtd);
        }
        else if (c == 'V')
        {
            printf("Digite o id do Produto: Digite o numero de unidades: ");
            scanf("%d\n%d\n", &id, &qtd);
            loja = vendeProdutoLoja(loja, id, qtd);
        }
        else if (c == 'D')
        {   printf ("Digite o id do Produto: Digite o novo desconto: ");
            scanf("%d\n%f\n", &id, &desconto);
            loja = atualizaDescontoLoja(loja, id, desconto);
        }
        else if (c == 'I')
        {
            imprimeProdutosLoja(loja);
        }
        else if (c == 'R')
        {
            imprimeRelatorio(loja);
        }
        else if (c == 'F')
        {
            break;
        }
        printf("\n");
    }
    return 0;
}

void Imprime_Menu()
{

    printf("Menu:\n");
    printf(" C - Cadastrar Produto\n");
    printf(" E - Estocar Produto\n");
    printf(" V - Vender Produto\n");
    printf(" D - Atualizar desconto de Produto\n");
    printf(" I - Imprimir Produtos\n");
    printf(" R - Imprimir Relatorio de Vendas\n");
    printf(" F - Finalizar Programa\n");
}