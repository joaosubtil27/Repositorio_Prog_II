#include "filme.h"
#include <stdlib.h>
#include <string.h>

struct Filme
{
    int codigo;
    int qtd_estoque;
    int qtd_alugado;
    int valor;

    char nome[MAX_CARACTERES];
};

/**
 * @brief Cria um novo filme e define a quantidade alugada como 0.
 *
 * @return Ponteiro para o filme criado ou encerra caso não seja possível alocar memória.
 */
tFilme *CriarFilme()
{
    tFilme *f = (tFilme *)malloc(sizeof(tFilme));
    f->qtd_estoque = 0;
    f->qtd_alugado = 0;
    f->valor = 0;
    return f;
}

/**
 * @brief Lê um filme do arquivo de entrada e define o código do filme.
 *
 * @param filme Ponteiro para o filme a ser lido.
 */
void LeFilme(tFilme *filme, int codigo)
{

    filme->codigo = codigo;
    scanf("%d,", filme->codigo);
    scanf("%[^,],", filme->nome);
    scanf("%d,%d\n", &filme->valor, &filme->qtd_estoque);
}

/**
 * @brief Libera a memória alocada para o filme.
 *
 * @param filme Ponteiro para o filme a ser destruído.
 */
void DestruirFilme(tFilme *filme)
{
    free(filme);
}

/**
 * @brief Retorna o código do filme.
 *
 * @param filme Ponteiro para o filme.
 * @return Código do filme.
 */
int ObterCodigoFilme(tFilme *filme)
{
    return filme->codigo;
}

/**
 * @brief Imprime o nome do filme.
 *
 * @param filme Ponteiro para o filme.
 */
void ImprimirNomeFilme(tFilme *filme)
{
    printf("%s", filme->nome);
}

/**
 * @brief Retorna o valor do filme.
 *
 * @param filme Ponteiro para o filme.
 * @return Valor do filme.
 */
int ObterValorFilme(tFilme *filme)
{
    return filme->valor;
}

/**
 * @brief Retorna a quantidade em estoque do filme.
 *
 * @param filme Ponteiro para o filme.
 * @return Quantidade em estoque do filme.
 */
int ObterQtdEstoqueFilme(tFilme *filme)
{
    return filme->qtd_estoque;
}

/**
 * @brief Retorna a quantidade alugada do filme.
 *
 * @param filme Ponteiro para o filme.
 * @return Quantidade alugada do filme.
 */
int ObterQtdAlugadaFilme(tFilme *filme)
{
    return filme->qtd_alugado;
}

/**
 * @brief Verifica se o filme possui o código passado como parâmetro.
 *
 * @param filme Ponteiro para o filme.
 * @param codigo Código a ser comparado.
 * @return 1 se o filme possui o código passado como parâmetro, 0 caso contrário.
 */
int EhMesmoCodigoFilme(tFilme *filme, int codigo)
{
    if (filme->codigo == codigo)
        return 1;
    else
        return 0;
}

/**
 * @brief Incrementa a quantidade alugada e decrementa a quantidade em estoque do filme.
 *
 * @param filme Ponteiro para o filme.
 */
void AlugarFilme(tFilme *filme)
{
    filme->qtd_alugado++;
    filme->qtd_estoque--;
}

/**
 * @brief Decrementa a quantidade alugada e incrementa a quantidade em estoque do filme.
 *
 * @param filme Ponteiro para o filme.
 */
void DevolverFilme(tFilme *filme)
{
    if (filme->qtd_alugado > 0)
    {
        filme->qtd_alugado--;
        filme->qtd_estoque++;
    }
}

/**
 * @brief Compara dois filmes pelo nome.
 *
 * @param filme1 Ponteiro para o primeiro filme.
 * @param filme2 Ponteiro para o segundo filme.
 * @return 1 se o nome do primeiro filme for maior que o nome do segundo filme, -1 se o nome do primeiro filme for menor que o nome do segundo filme, 0 se os nomes forem iguais.
 */
int CompararNomesFilmes(tFilme *filme1, tFilme *filme2)
{
    if (strcmp(filme1->nome, filme2->nome) == 0)
        return 1;
    else
        return 0;
}
