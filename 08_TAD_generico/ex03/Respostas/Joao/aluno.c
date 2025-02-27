
#include "vector.h"
#include "aluno.h"
#include <stdio.h>
#include <stdio.h>

#define MAX_STR 50
struct Aluno
{
    char nome[MAX_STR];
    char genero;
    float nota;
};

/**
 * @brief Aloca memoria para um aluno
 *
 * @return A estrutura tAluno inicializada. Caso não seja possível alocar memória, o programa é encerrado.
 */
tAluno *CriaAluno()
{
    tAluno *t = (tAluno *)malloc(sizeof(tAluno));

    t->nota = 0;
    return t;
}

/**
 * @brief Libera a memoria alocada para um aluno
 *
 * @param aluno Ponteiro para o aluno
 * Dica: Foi usado data_type para generalizar a funcao e usar na estrutura Vector. Por isso, é necessário fazer um cast para tAluno* dentro da função.
 */
void DestroiAluno(data_type aluno)
{
    free(aluno);
}

/**
 * @brief Le os dados de um aluno
 *
 * @param aluno Ponteiro para o aluno
 */
void LeAluno(tAluno *aluno)
{
    scanf("%[^;];", aluno->nome);
    scanf("%c;%f\n", &aluno->genero, &aluno->nota);
}

/**
 * @brief Retorna o genero de um aluno
 *
 * @param aluno Ponteiro para o aluno
 * @return char Genero do aluno
 */
char GetGeneroAluno(tAluno *aluno){
    return aluno->genero;
}

/**
 * @brief Retorna a nota de um aluno
 *
 * @param aluno Ponteiro para o aluno
 * @return float Nota do aluno
 */
float GetNotaAluno(tAluno *aluno)
{
    return aluno->nota;
}
