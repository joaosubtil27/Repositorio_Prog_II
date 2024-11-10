#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1

void imprimeTexto();
void primeiraOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);
void segundaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1]);
void terceiraOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);
void quartaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);
void quintaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2]);

int main()
{

    int opcao=0;
    int matrix1[50][50];
    int matrix2[50][50];
    int result[50][50];
    int rows1, cols1, rows2, cols2;

    scanf("%d %d ", &rows1, &cols1);
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d ", &rows2, &cols2);
    matrix_read(rows2, cols2, matrix2);

    while (opcao != 6)
    {
        imprimeTexto();
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            primeiraOpcao(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        }

        else if (opcao == 2)
        {
            segundaOpcao(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        }

        else if (opcao == 3)
        {
            terceiraOpcao(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        }

        else if (opcao == 4)
        {
            quartaOpcao(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        }

        else if (opcao == 5)
        {
            quintaOpcao(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        }

        else if (opcao == 6)
            break;
    }
    return 0;
}

void imprimeTexto()
{
    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida: \n");
}

void primeiraOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    if (possible_matrix_sum(rows1, cols1, rows2, cols2) == VERDADEIRO)
    {
        matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        matrix_print(rows1, cols1, result);
    }
    else
        printf("Erro: as dimensoes da matriz nao correspondem\n\n");
}

void segundaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    if (possible_matrix_sub(rows1, cols1, rows2, cols2) == VERDADEIRO)
    {
        matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        matrix_print(rows1, cols1, result);
    }
    else
        printf("Erro: as dimensoes da matriz nao correspondem\n\n");
}

void terceiraOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    if (possible_matrix_multiply(cols1, rows2) == VERDADEIRO)
    {
        matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
        matrix_print(rows1, cols2, result);
    }
    else
        printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
}

void quartaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    int scalar, qual_matrix;

    scanf("%d %d", &scalar, &qual_matrix);
    if (qual_matrix == VERDADEIRO)
    {
        scalar_multiply(rows1, cols1, matrix1, scalar);
        matrix_print(rows1, cols1, matrix1);
    }

    else if (qual_matrix == 2)
    {
        scalar_multiply(rows2, cols2, matrix2, scalar);
        matrix_print(rows2, cols2, matrix2);
    }
}

void quintaOpcao(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    transpose_matrix(rows1, cols1, matrix1, result);
    matrix_print(cols1, rows1, result);
    transpose_matrix(rows2, cols2, matrix2, result);
    matrix_print(cols2, rows2, result);
}