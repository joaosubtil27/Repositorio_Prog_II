#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Cadastra um novo produto no vetor de produtos.
 */
void cadastrarProduto(Produto **vetorProdutos, int *tamanho, int *alocado)
{
    char nome[50];
    float preco;
    int quantidade;
    Produto p;
    scanf("%s %f %d", p.nome, &p.preco, &p.quantidade);


    vetorProdutos = (Produto **)realloc(vetorProdutos, (*tamanho + 1) * sizeof(Produto *));
    strcpy(vetorProdutos[*tamanho]->nome, p.nome);
    vetorProdutos[*tamanho]->preco = p.preco;
    vetorProdutos[*tamanho]->quantidade = p.quantidade;

    (*tamanho)++;
    (*alocado)++;
    exibirLista(vetorProdutos, *tamanho);
}

/**
 * @brief Exibe a lista de produtos ordenada.
 */
void exibirLista(Produto **vetorProdutos, int tamanho)
{
    printf("Lista de produtos cadastrados:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetorProdutos[i]->nome);
        printf("Preco: %.2f\n", vetorProdutos[i]->preco);
        printf("Quantidade em estoque: %d\n", vetorProdutos[i]->quantidade);
    }
}

/**
 * @brief Compara dois produtos.
 */
int compararProduto(const void *a, const void *b)
{
    const Produto *p1 = (Produto *)a;
    const Produto *p2 = (Produto *)b;

    int diff = p1->quantidade - p2->quantidade;
    if (diff == 0)
    {
        return strcmp(p1->nome, p2->nome);
    }
    else
        return diff;
}

/**
 * @brief Ordena a lista de produtos.
 */
void ordenarLista(Produto **vetorProdutos, int tamanho)
{
    qsort(vetorProdutos, tamanho, sizeof(Produto *), compararProduto);
}

/**
 * @brief Desaloca a lista de produtos e todos os seus produtos.
 */
void desalocaLista(Produto **vetorProdutos, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        free(vetorProdutos[i]);
    }
    free(vetorProdutos);
}

/**
 * @brief Escreve a lista em um arquivo binário.
 */
void salvarLista(Produto **vetorProdutos, int tamanho)
{
    int tam;
    int qnt_alocs = tamanho;
    FILE *f = fopen("produtos.bin", "wb");
    fwrite(&qnt_alocs, sizeof(int), 1, f);
    for (int i = 0; i < tamanho; i++)
    {
        tam = strlen(vetorProdutos[i]->nome) + 1;
        fwrite(&tam, sizeof(int), 1, f);
        fwrite(vetorProdutos[i]->nome, sizeof(char), tam, f);
        fwrite(&vetorProdutos[i]->preco, sizeof(float), 1, f);
        fwrite(&vetorProdutos[i]->quantidade, sizeof(int), 1, f);
    }
    fclose(f);
}

/**
 * @brief Le uma lista de produtos salva em formato binário e a retorna.
 */
Produto **lerLista(int *tamanho, int *alocado)
{
    int tam;
    int qnt_alocs;
    FILE *f = fopen("produtos.bin", "rb");
    fread(&qnt_alocs, sizeof(int), 1, f);
    Produto **vetorProdutos = (Produto **)malloc(qnt_alocs * sizeof(Produto *));
    for (int i = 0; i < *tamanho; i++)
    {
        fread(&tam, sizeof(int), 1, f);
        fread(vetorProdutos[i]->nome, sizeof(char), tam, f);
        fread(&vetorProdutos[i]->preco, sizeof(float), 1, f);
        fread(&vetorProdutos[i]->quantidade, sizeof(int), 1, f);
    }
    fclose(f);

    return vetorProdutos;
}
