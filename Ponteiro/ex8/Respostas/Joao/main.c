#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

int main()
{

    int qnt_depts;
    int m1, m2, m3;
    int i=0;
    char nome[STRING_MAX], diretor[STRING_MAX];
    char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX];

    scanf("%d\n", &qnt_depts);
    tDepartamento depts[qnt_depts];

    while (i < qnt_depts)
    {
        scanf("%s\n", nome);
        scanf("%s\n", diretor);
        scanf("%s\n", curso1);
        scanf("%s\n", curso2);
        scanf("%s\n", curso3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        if (0 <= m1 && m1 <= 10 && 0 <= m2 && m2 <= 10 && 0 <= m3 && m3 <= 10)
        {
            depts[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
            i++;
        }
        else
            printf("\nDigite um departamento com médias válidas");
    }

    OrdenaDepartamentosPorMedia(depts, qnt_depts);
    for (int i = 0; i < qnt_depts; i++)
    {
        ImprimeAtributosDepartamento(depts[i]);
    }
}