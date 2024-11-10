#include "matrix_utils.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    int opcao;
    int matrix1[50][50];
    int matrix2[50][50];
    int row1, col1, row2, col2;
    int i, j;
    int scalar, qual_matrix;

    scanf("%d %d ", &row1, &col1);
    matrix_read(row1, col1, matrix1);

    scanf("%d %d ", &row2, &col2);
    matrix_read(row2, col2, matrix2);

    while (opcao != 6)
    {

        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: ");
        scanf("%d", &opcao);
        if (opcao == 1 && possible_matrix_sum(row1, col1, row2, col2) == 1)
        {
            matrix_add(row1, col1, matrix1, row2, col2, matrix2, matrix1);
            matrix_print(row1, col1, matrix1);
        }

        else if (opcao == 2 && possible_matrix_sub(row1, col1, row2, col2) == 1)
        {
            matrix_sub(row1, col1, matrix1, row2, col2, matrix2, matrix1);
            matrix_print(row1, col1, matrix1);
        }

        else if (opcao == 3 && possible_matrix_multiply(col1, row2) == 1)
        {
            matrix_multiply(row1, col1, matrix1, row2, col2, matrix2, matrix1);
            matrix_print(row1, col1, matrix1);
        }

        else if (opcao == 4)
        {
            scanf("%d %d", &scalar, &qual_matrix);
            if (qual_matrix == 1)
            {
                scalar_multiply(row1, col1, matrix1, scalar);
                matrix_print(row1, col1, matrix1);
            }
            
            else if (qual_matrix == 2)
            {
                scalar_multiply(row2, col2, matrix2, scalar);
                matrix_print(row2, col2, matrix2);
            }
        }

        else if (opcao == 5)
        {
            transpose_matrix(row1, col1, matrix1, matrix1);
            matrix_print(row1, col1, matrix1);
        }

        else if (opcao == 6)
            break;
    }
    return 0;
}