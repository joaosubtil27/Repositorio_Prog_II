
#include "livro.h"
#include "string.h"

#define MAX_LIVROS 10

// Estrutura que representa uma biblioteca de livros
typedef struct
{
    tLivros livros[MAX_LIVROS]; // Array de livros
    int tamanho;                // Número atual de livros na biblioteca
} tBiblioteca;

/**
 * Inicializa uma biblioteca vazia.
 *
 * @return A biblioteca inicializada.
 */
tBiblioteca inicializarBiblioteca()
{
    tBiblioteca biblioteca;
    biblioteca.tamanho = 0;
    return biblioteca;
}

/**
 * Adiciona um livro à biblioteca.
 * Se estiver dentro do tamanho máximo de livros, imprime "Livro adicionado com sucesso!"
 * Senão, imprime "A biblioteca está cheia. Não é possível adicionar mais livros."
 *
 * @param biblioteca A biblioteca onde o livro será adicionado.
 * @param livro O livro a ser adicionado.
 * @return A biblioteca atualizada com o livro adicionado.
 */
tBiblioteca adicionarLivroNaBiblioteca(tBiblioteca biblioteca, tLivros livro)
{

    if (biblioteca.tamanho < MAX_LIVROS)
    {
        printf("Livro adicionado com sucesso!\n");
        biblioteca.livros[biblioteca.tamanho] = livro;
        biblioteca.tamanho++;
    }

    else
        printf("A biblioteca esta cheia. Nao eh possivel adicionar mais livros.\n");
    return biblioteca;
}
/**
 * Remove um livro da biblioteca pelo título.
 * Se o título for encontrado, imprime "Livro removido com sucesso!",
 * Senão, imprime "Livro não encontrado na biblioteca."
 *
 * @param biblioteca A biblioteca da qual o livro será removido.
 * @param titulo O título do livro a ser removido.
 * @return A biblioteca atualizada após a remoção do livro.
 */
tBiblioteca removerLivroDaBiblioteca(tBiblioteca biblioteca, char *titulo)
{
    int valid = 0;

    for (int i = 0; i < biblioteca.tamanho; i++)
    {
        if (valid == 1)
        {
            biblioteca.livros[i - 1] = biblioteca.livros[i];
        }
        if (verificaTituloDoLivroNaBiblioteca(biblioteca.livros[i], titulo) == 0)
        {
            printf("Livro removido com sucesso!\n");
            valid = 1;
        }
    }
    if (valid == 0)
    {
        printf("Livro nao encontrado na biblioteca.\n");
    }
    else
        biblioteca.tamanho -= 1;

    return biblioteca;
}

/**
 * Verifica se o título digitado é igual ao título do livro.
 *
 * @param livro O livro cujo título será verificado.
 * @param titulo O título digitado pelo usuário.
 * @return se o título for igual, retorna 0.
 */
int verificaTituloDoLivroNaBiblioteca(tLivros livro, char *titulo)
{
    if (strcmp(livro.titulo, titulo) == 0)
        return 0;
}

/**
 * Lista todos os livros presentes na biblioteca.
 * Se não houver livros na biblioteca, imprime "A biblioteca esta vazia!"
 *
 * @param biblioteca A biblioteca cujos livros serão listados.
 */
void listarLivrosDaBiblioteca(tBiblioteca biblioteca)
{

    if (biblioteca.tamanho == 0)
        printf("A biblioteca esta vazia!\n");
    else
    {
        printf("\nLista de Livros na Biblioteca:\n");
        for (int i = 0; i < biblioteca.tamanho; i++)
        {
            imprimeLivro(biblioteca.livros[i]);
        }
    }
}
