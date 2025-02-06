#include <stdio.h>
#include "aluno.h"

int main()
{
    int qnt_alunos;
    scanf("%d\n", &qnt_alunos);

    tAluno alunos[qnt_alunos], troca;

    for (int i = 0; i < qnt_alunos; i++)
    {
        alunos[i] = LeAluno();
    }

    for (int i = 0; i < qnt_alunos; i++)
    {
        for (int j = 0; j < qnt_alunos; j++)
        {
            if (ComparaMatricula(alunos[j], alunos[i]) == 1)
            {
                troca = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = troca;
            }
        }
    }
    
    for (int i = 0; i < qnt_alunos; i++)
    {
        if (VerificaAprovacao(alunos[i]) == 1)
        {
            ImprimeAluno(alunos[i]);
        }
    }
}