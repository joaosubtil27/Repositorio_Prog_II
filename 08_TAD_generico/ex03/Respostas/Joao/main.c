#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "vector.h"
#include "relatorio.h"

int main()
{
    int qnt_alunos;
    scanf("%d\n", &qnt_alunos);
    tAluno *a;
    Vector *v = VectorConstruct();
    for (int i = 0; i < qnt_alunos; i++)
    {
        a = CriaAluno();
        LeAluno(a);
        VectorPushBack(v, a);
    }
    ImprimeRelatorio(v);
    VectorDestroy(v, DestroiAluno);
    return 0;
}