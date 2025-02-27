#include "relatorio.h"
#include "vector.h"
#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Imprime o relatorio de uma coleção de alunos.
 * O relatorio deve possuir a media das notas, porcentagem de alunos aprovados e porcentagem de cada gênero.
 *
 * @param alunos Ponteiro para o vetor de alunos.
 */
void ImprimeRelatorio(Vector *alunos)
{
    float soma = 0;
    int aprovados = 0;
    int masc = 0;
    int fem = 0;
    int outros = 0;

    for (int i = 0; i < VectorSize(alunos); i++)
    {
        soma += GetNotaAluno(VectorGet(alunos, i));

        if (GetNotaAluno(VectorGet(alunos, i)) >= 6)
            aprovados++;

        if (GetGeneroAluno(VectorGet(alunos, i)) == 'M')
            masc++;
        else if (GetGeneroAluno(VectorGet(alunos, i)) == 'F')
            fem++;
        else if (GetGeneroAluno(VectorGet(alunos, i)) == 'O')
            outros++;
    }

    printf("Media das notas: %.2f\n", soma / VectorSize(alunos));
    printf("Porcentagem de alunos aprovados: %.2f%%\n", (float) 100 * aprovados / VectorSize(alunos));
    printf("Porcentagem de cada genero:\n");
    printf("Masculino: %.2f%%\n",(float)(100 * masc / VectorSize(alunos)));
    printf("Feminino: %.2f%%\n",(float)(100 * fem / VectorSize(alunos)));
    printf("Outro: %.2f%%\n",(float)(100 * outros / VectorSize(alunos)));
}
