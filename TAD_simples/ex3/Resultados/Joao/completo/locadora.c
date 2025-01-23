
#include "filme.h"
#include "locadora.h"

#define MAX_FILMES 100

typedef struct Locadora
{
    tFilme filme[MAX_FILMES];
    int numFilmes;
    int lucro;
} tLocadora;

/**
 * @brief Cria uma nova locadora.
 * @return Locadora criada.
 */
tLocadora criarLocadora()
{
    tLocadora locadora;
    locadora.lucro = 0;
    locadora.numFilmes = 0;

    return locadora;
}

/**
 * @brief Verifica se um filme está cadastrado na locadora.
 * @param locadora Locadora a ser consultada.
 * @param codigo Código do filme a ser verificado.
 * @return 1 se o filme está cadastrado, 0 caso contrário.
 */
int verificarFilmeCadastrado(tLocadora locadora, int codigo)
{

    for (int i = 0; i < locadora.numFilmes; i++)
    {
        if (locadora.filme[i].codigo == codigo)
            return 1;
    }

    return 0;
}

/**
 * @brief Cadastra um filme na locadora, desde que ele não esteja cadastrado.
 * @param locadora Locadora a ser atualizada.
 * @param filme Filme a ser cadastrado.
 * @return Locadora atualizada.
 */
tLocadora cadastrarFilmeLocadora(tLocadora locadora, tFilme filme)
{

    if (verificarFilmeCadastrado(locadora, filme.codigo) == 0)
    {
        locadora.filme[locadora.numFilmes] = filme;
        locadora.numFilmes++;
    }
    else
    printf ("Filme ja cadastrado no estoque\n");
    return locadora;
}

/**
 * @brief Lê o cadastro de um ou mais filmes a partir da entrada padrão e o cadastra na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerCadastroLocadora(tLocadora locadora)
{
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        printf("Filme cadastrado %d - %s\n", locadora.filme[i].codigo, locadora.filme[i].nome);
    }
}

/**
 * @brief Aluga um conjunto de filmes da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem alugados.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora alugarFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    int valid;
    for (int i = 0; i < quantidadeCodigos; i++)
    {   valid = 0;

        for (int j = 0; j < locadora.numFilmes; j++)
        {
            if (codigos[i] == locadora.filme[j].codigo)
            {
                if (locadora.filme[j].qtdEstoque > 0)
                {
                    locadora.filme[j] = alugarFilme(locadora.filme[j]);
                    locadora.lucro += locadora.filme[j].valor;
                }
                else
                    printf("Filme %d - %s nao disponivel no estoque. Volte mais tarde.\n", locadora.filme[j].codigo, locadora.filme[j].nome);
                valid = 1;
            }
        }
        if (valid == 0)
        printf ("Filme %d nao cadastrado.\n", codigos[i]);
    }
    return locadora;
}

/**
 * @brief Lê o aluguel de um conjunto de filmes a partir da entrada padrão e os aluga na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerAluguelLocadora(tLocadora locadora)
{
    int qntAlugados = 0;
    int valor = 0;
    for (int i = 0; i < locadora.numFilmes; i++)
    {
        qntAlugados += locadora.filme[i].qtdAlugada;
        valor += locadora.filme[i].qtdAlugada * locadora.filme[i].valor;
    }
    printf("Total de filmes alugados: %d com custo de R$%d", qntAlugados, valor);

    return locadora;
}
/**
 * @brief Devolve um conjunto de filmes alugados da locadora.
 * @param locadora Locadora a ser atualizada.
 * @param codigos Array com os códigos dos filmes a serem devolvidos.
 * @param quantidadeCodigos Quantidade de códigos no array.
 * @return Locadora atualizada.
 */
tLocadora devolverFilmesLocadora(tLocadora locadora, int *codigos, int quantidadeCodigos)
{
    for (int i = 0; i < quantidadeCodigos; i++)
    {

        for (int j = 0; j < locadora.numFilmes; j++)
        {
            if (codigos[i] == locadora.filme[j].codigo && locadora.filme[j].qtdAlugada > 0)
            {
                locadora.filme[j] = devolverFilme(locadora.filme[j]);
                printf("Filme %d - %s Devolvido!", locadora.filme[j].codigo, locadora.filme[j].nome);
            }
        }
    }
    return locadora;
}

/**
 * @brief Lê a devolução de um conjunto de filmes a partir da entrada padrão e os devolve na locadora.
 * @param locadora Locadora a ser atualizada.
 * @return Locadora atualizada.
 */
tLocadora lerDevolucaoLocadora(tLocadora locadora)
{

}

/**
 * @brief Ordena os filmes da locadora por nome.
 * @param locadora Locadora a ser ordenada.
 * @return Locadora ordenada.
 */
tLocadora ordenarFilmesLocadora(tLocadora locadora)
{
    tFilme troca;
    for (int i = 0; i < locadora.numFilmes - 1; i++)
    {
        for (int j = 0; j < locadora.numFilmes - i - 1; j++)
        {
            if (compararNomesFilmes(locadora.filme[j], locadora.filme[j + 1]) == -1)
            {
                troca = locadora.filme[j];
                locadora.filme[j] = locadora.filme[j + 1];
                locadora.filme[j + 1] = troca;
            }
        }
    }
    return locadora;
}

/**
 * @brief Imprime o estoque da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarEstoqueLocadora(tLocadora locadora)
{
    printf("~ESTOQUE~\n");
    for (int i; i < locadora.numFilmes; i++)
    {
        printf("%d - %s Fitas em estoque: %d\n", locadora.filme[i].codigo, locadora.filme[i].nome, locadora.filme[i].qtdEstoque);
    }
}

/**
 * @brief Imprime o lucro da locadora.
 * @param locadora Locadora a ser consultada.
 */
void consultarLucroLocadora(tLocadora locadora)
{
    printf("Lucro total R$ %d\n", locadora.lucro);
}
