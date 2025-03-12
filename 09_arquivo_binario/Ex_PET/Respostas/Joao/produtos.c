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
    if (*tamanho == *alocado)
    {
        *alocado += 5;
        vetorProdutos = (Produto **)realloc(vetorProdutos, (*tamanho + 1) * sizeof(Produto *));
    }
    Produto *p = (Produto *)malloc(sizeof(Produto));
    scanf("%s %f %d", p->nome, &p->preco, &p->quantidade);
    int valid = 1;
    for (int i = 0; i < *tamanho; i++)
    {
        if (strcmp(p->nome, vetorProdutos[i]->nome) == 0)
        {
            vetorProdutos[i]->preco = p->preco;
            vetorProdutos[i]->quantidade += p->quantidade;
            free(p);
            valid = 0;
            break;
        }
    }
    if (valid == 1)
    {
        vetorProdutos[*tamanho] = p;
        (*tamanho)++;
    }
    // exibirLista(vetorProdutos, *tamanho);
}

/**
 * @brief Exibe a lista de produtos ordenada.
 */
void exibirLista(Produto **vetorProdutos, int tamanho)
{
    printf("\nLista de produtos cadastrados:\n");
    for (int i = 0; i < tamanho; i++)
    {
        printf("Produto %d:\n", i + 1);
        printf("Nome: %s\n", vetorProdutos[i]->nome);
        printf("Preco: %.2f\n", vetorProdutos[i]->preco);
        printf("Quantidade em estoque: %d\n\n", vetorProdutos[i]->quantidade);
    }
}

/**
 * @brief Compara dois produtos.
 */
int compararProduto(const void *a, const void *b)
{
    Produto *p1 = *(Produto **)a;
    Produto *p2 = *(Produto **)b;

    if (p1->preco * p1->quantidade > p2->preco * p2->quantidade)
        return -1;
    else if (p1->preco * p1->quantidade < p2->preco * p2->quantidade)
        return 1;
    else
        return strcmp(p1->nome, p2->nome);
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
    FILE *f = fopen("produtos.bin", "wb");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    if (tamanho == 0)
    {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    fwrite(&tamanho, sizeof(int), 1, f);
    for (int i = 0; i < tamanho; i++)
    {
        tam = strlen(vetorProdutos[i]->nome) + 1;
        fwrite(&tam, sizeof(int), 1, f);
        fwrite(vetorProdutos[i]->nome, sizeof(char), tam, f);
        fwrite(&vetorProdutos[i]->preco, sizeof(float), 1, f);
        fwrite(&vetorProdutos[i]->quantidade, sizeof(int), 1, f);
        // fwrite(vetorProdutos[i], sizeof(Produto), 1, f);
    }
    fclose(f);
}

/**
 * @brief Le uma lista de produtos salva em formato binário e a retorna.
 */
Produto **lerLista(int *tamanho, int *alocado)
{
    int tam;
    FILE *f = fopen("produtos.bin", "rb");

    fread(tamanho, sizeof(int), 1, f);
    *alocado = *tamanho + 5;
    Produto **vetorProdutos = (Produto **)malloc(*alocado * sizeof(Produto *));
    for (int i = 0; i < *tamanho; i++)
    {
        Produto *p = (Produto *)malloc(sizeof(Produto));
        fread(&tam, sizeof(int), 1, f);
        fread(p->nome, sizeof(char), tam, f);
        fread(&p->preco, sizeof(float), 1, f);
        fread(&p->quantidade, sizeof(int), 1, f);
        vetorProdutos[i] = p;
    }
    fclose(f);

    return vetorProdutos;
}
