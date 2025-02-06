#include "matrix_utils.h"
#include <stdio.h>
void matrix_read(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_print(int rows, int cols, int matrix[rows][cols])
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (j == 0)
                printf("|%d", matrix[i][j]);

            else if (j > 0 && j < cols - 1)
                printf(" %d", matrix[i][j]);

            else
                printf(" %d|", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int possible_matrix_sum(int rows1, int cols1, int rows2, int cols2)
{
    if (rows1 == rows2 && cols1 == cols2)
        return 1;
    else
        return 0;
}

int possible_matrix_sub(int rows1, int cols1, int rows2, int cols2)
{
    if (rows1 == rows2 && cols1 == cols2)
        return 1;
    else
        return 0;
}

int possible_matrix_multiply(int cols1, int rows2)
{
    if (cols1 == rows2)
        return 1;
    else
        return 0;
}

void matrix_add(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    int i, j;

    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
        {

            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrix_sub(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols1])
{
    int i, j;

    for (i = 0; i < rows1; i++)
    {
        for (j = 0; j < cols1; j++)
        {

            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrix_multiply(int rows1, int cols1, int matrix1[rows1][cols1], int rows2, int cols2, int matrix2[rows2][cols2], int result[rows1][cols2])
{
    int i1, j1;
    int i2, j2;

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            result[i][j] = 0;
        }
    }
    for (i1 = 0; i1 < rows1; i1++)
    {
        for (j2 = 0; j2 < cols2; j2++)
        {
            for (j1 = 0; j1 < cols1; j1++)
            {
                for (i2 = 0; i2 < rows2; i2++)
                {
                    if (j1 == i2)
                    {
                        result[i1][j2] += matrix1[i1][j1] * matrix2[i2][j2];
                    }
                }
            }
        }
    }
}

void transpose_matrix(int rows, int cols, int matrix[rows][cols], int result[cols][rows])
{
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {

            result[j][i] = matrix[i][j];
        }
    }
}

void scalar_multiply(int rows, int cols, int matrix[rows][cols], int scalar)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = scalar * matrix[i][j];
        }
    }
}
