#include <stdio.h>
#include "departamento.h"

int main()
{

    int qnt_dept;
    char nome[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];
    int m1, m2, m3;
    char diretor[STRING_MAX];

    scanf("%d\n", &qnt_dept);

    tDepartamento depts[qnt_dept];

    for (int i = 0; i < qnt_dept; i++)
    {
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", c1);
        scanf("%[^\n]\n", c2);
        scanf("%[^\n]\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);
        depts[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }
    ordenaPorMediaDepartamentos(depts, qnt_dept);
    
    for (int i = 0; i < qnt_dept; i++)
    {
        imprimeAtributosDepartamento(depts[i]);
    }
}