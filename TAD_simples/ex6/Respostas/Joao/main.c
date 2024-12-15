#include <stdio.h>
#include "matrix_utils.h"

void printaComando();

int main()
{
    tMatrix matrix1, matrix2;

    int rows1, cols1;
    int rows2, cols2;
    int comando = 1;
    int scalar, num_matrix;
    scanf("%d %d\n", &rows1, &cols1);

    matrix1 = MatrixCreate(rows1, cols1);
    matrix1 = MatrixRead(matrix1);

    scanf("%d %d\n", &rows2, &cols2);

    matrix2 = MatrixCreate(rows2, cols2);
    matrix2 = MatrixRead(matrix2);

    while (1)
    {
        printaComando();
        scanf("%d\n", &comando);
        if (comando == 1)
        {
            if (PossibleMatrixSum(matrix1, matrix2) == 1)
            {
                MatrixPrint(MatrixAdd(matrix1, matrix2));
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
        if (comando == 2)
        {
            if (PossibleMatrixSub(matrix1, matrix2) == 1)
            {
                MatrixPrint(MatrixSub(matrix1, matrix2));
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
        if (comando == 3)
        {
            if (PossibleMatrixMultiply(matrix1, matrix2) == 1)
            {
                MatrixPrint(MatrixMultiply(matrix1, matrix2));
            }
            else
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        }
        if (comando == 4)
        {
            scanf("%d %d\n", &scalar, &num_matrix);

            if (num_matrix == 1)
            {
                matrix1 = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(matrix1);
            }

            else if (num_matrix == 2)
            {
                matrix2 = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(matrix2);
            }
        }
        if (comando == 5)
        {
            MatrixPrint(TransposeMatrix(matrix1));

            MatrixPrint(TransposeMatrix(matrix2));
        }
        if (comando == 6)
        {
            break;
        }
    }
    return 0;
}

void printaComando()
{

    printf("1 - Somar matrizes\n");
    printf("2 - Subtrair matrizes\n");
    printf("3 - Multiplicar matrizes\n");
    printf("4 - Multiplicacao de uma matriz por escalar\n");
    printf("5 - Transposta de uma matriz\n");
    printf("6 - Encerrar o programa\n");
    printf("Opcao escolhida:\n");
}