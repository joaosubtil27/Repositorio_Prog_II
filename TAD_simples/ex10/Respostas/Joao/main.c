#include "biblioteca.h"
#include <stdio.h>

int main()
{

    int qnt_comandos = 0;
    int comando = 0;
    char titulo[100];
    tBiblioteca biblioteca;
    tLivros livro;
    scanf("%d\n", &qnt_comandos);

    biblioteca = inicializarBiblioteca();

    printf("Lista de operacoes:\n");
    printf("1 - Cadastrar livros.\n");
    printf("2 - Remover livros.\n");
    printf("3 - Listar todos os livros cadastrados.\n\n");

    for (int i = 0; i < qnt_comandos; i++)
    {
        scanf("%d\n", &comando);
        if (comando == 1)
        {
            livro = lerLivro();
            biblioteca = adicionarLivroNaBiblioteca(biblioteca, livro);
        }
        else if (comando == 2)
        {
            scanf("%[^\n]\n", titulo);
            biblioteca = removerLivroDaBiblioteca(biblioteca, titulo);
        }
        else if (comando == 3)
        {
            listarLivrosDaBiblioteca(biblioteca);
        }
        else
        {
            printf("Operacao invalida!");
            break;
        }
    }
    return 0;
}