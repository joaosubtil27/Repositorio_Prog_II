#define MAX_MATRIX_SIZE 10

typedef struct Matrix
{
    int rows;
    int cols;
    int data[MAX_MATRIX_SIZE][MAX_MATRIX_SIZE];
} tMatrix;

/**
 * @brief Cria uma matriz com o número de linhas e colunas especificado.
 * @param rows O número de linhas na matriz.
 * @param cols O número de colunas na matriz.
 * @return A matriz criada.
 */
tMatrix MatrixCreate(int rows, int cols)
{
    tMatrix matriz;
    matriz.rows = rows;
    matriz.cols = cols;
    for (int i = 0; i < matriz.rows; i++)
    {
        for (int j = 0; j < matriz.cols; j++)
        {
            matriz.data[i][j] = 0;
        }
    }
    return matriz;
}

/**
 * @brief Lê uma matriz da entrada padrão.
 * @param matrix A matriz a ser lida.
 * @return A matriz lida.
 */
tMatrix MatrixRead(tMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            scanf("%d", &matrix.data[i][j]);
        }
    }
    return matrix;
}

/**
 * @brief Imprime uma matriz na saída padrão.
 * @param matrix A matriz a ser impressa.
 */
void MatrixPrint(tMatrix matrix)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        printf("|");
        for (int j = 0; j < matrix.cols; j++)
        {
            printf("%d", matrix.data[i][j]);

            if (j != matrix.cols - 1)
                printf(" ");
        }
        printf("|\n");
    }
    printf("\n");
}

/**
 * @brief Verifica se é possível somar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível somar as matrizes, 0 caso contrário.
 */
int PossibleMatrixSum(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols)
        return 1;
    else
        return 0;
}

/**
 * @brief Verifica se é possível subtrair duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível subtrair as matrizes, 0 caso contrário.
 */
int PossibleMatrixSub(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.rows == matrix2.rows && matrix1.cols == matrix2.cols)
        return 1;
    else
        return 0;
}

/**
 * @brief Verifica se é possível multiplicar duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return 1 se for possível multiplicar as matrizes, 0 caso contrário.
 */
int PossibleMatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{
    if (matrix1.cols == matrix2.rows)
        return 1;
    else
        return 0;
}

/**
 * @brief Soma duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da soma.
 */
tMatrix MatrixAdd(tMatrix matrix1, tMatrix matrix2)
{

    for (int i = 0; i < matrix1.rows; i++)
    {
        for (int j = 0; j < matrix1.cols; j++)
        {
            matrix1.data[i][j] = matrix1.data[i][j] + matrix2.data[i][j];
        }
    }
    return matrix1;
}

/**
 * @brief Subtrai duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da subtração.
 */
tMatrix MatrixSub(tMatrix matrix1, tMatrix matrix2)
{

    for (int i = 0; i < matrix1.rows; i++)
    {
        for (int j = 0; j < matrix1.cols; j++)
        {
            matrix1.data[i][j] = matrix1.data[i][j] - matrix2.data[i][j];
        }
    }
    return matrix1;
}

/**
 * @brief Multiplica duas matrizes.
 * @param matrix1 A primeira matriz.
 * @param matrix2 A segunda matriz.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiply(tMatrix matrix1, tMatrix matrix2)
{
    tMatrix result;
    result = MatrixCreate(matrix1.rows, matrix2.cols);

        for (int i1 = 0; i1 < matrix1.rows; i1++)
        {
            for (int j2 = 0; j2 < matrix2.cols; j2++)
            {
                for (int j1 = 0; j1 < matrix1.cols; j1++)
                {
                    for (int i2 = 0; i2 < matrix2.rows; i2++)
                    {
                        if (j1 == i2)
                        {
                            result.data[i1][j2] += matrix1.data[i1][j1] * matrix2.data[i2][j2];
                        }
                    }
                }
            }
    }
    return result;
}

/**
 * @brief Transpõe uma matriz.
 * @param matrix A matriz a ser transposta.
 * @return A matriz transposta.
 */
tMatrix TransposeMatrix(tMatrix matrix)
{
    tMatrix mat;
    mat = MatrixCreate(matrix.cols, matrix.rows);

    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            mat.data[j][i] = matrix.data[i][j];
        }
    }
    return mat;
}

/**
 * @brief Multiplica uma matriz por um escalar.
 * @param matrix A matriz a ser multiplicada.
 * @param scalar O escalar pelo qual a matriz será multiplicada.
 * @return O resultado da multiplicação.
 */
tMatrix MatrixMultiplyByScalar(tMatrix matrix, int scalar)
{
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.cols; j++)
        {
            matrix.data[i][j] = matrix.data[i][j] * scalar;
        }
    }

    return matrix;
}
