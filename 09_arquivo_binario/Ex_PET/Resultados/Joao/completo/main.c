#include <stdlib.h>
#include <stdio.h>
#include "produtos.h"

int main()
{
    int tamanho = 0, alocado = 0;
    int op;
    Produto **vetorProdutos = (Produto **)malloc(sizeof(Produto *));
    while (1)
    {
        printf("===== Sistema de Registro de Produtos =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Exibir lista de produtos cadastrados\n");
        printf("3 - Salvar lista de produtos em arquivo\n");
        printf("4 - Ler lista de produtos de arquivo\n");
        printf("5 - Sair do programa\n");
        printf("Escolha uma opcao:\n");
        scanf("%d\n", &op);
        if (op == 1)
        {  
                        cadastrarProduto(vetorProdutos, &tamanho, &alocado);
     
        }
        else if (op == 2)
        {
            exibirLista(vetorProdutos, tamanho);
        }
        else if (op == 3)
        {
            printf("Lista de produtos salva no arquivo 'produtos.bin'.\n");
            salvarLista(vetorProdutos, tamanho);
        }
        else if (op == 4)
        {
            desalocaLista(vetorProdutos, tamanho);
            vetorProdutos = lerLista(&tamanho, &alocado);
        }
        else if (op == 5)
        {
            printf("Encerrando o programa.\n");
            break;
        }
    }
    desalocaLista(vetorProdutos, tamanho);
    return 0;
}