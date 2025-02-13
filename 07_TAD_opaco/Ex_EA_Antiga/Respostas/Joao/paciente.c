
#include "paciente.h"
#include "data.h"
#include "lesao.h"

#include <stdio.h>
#include <stdlib.h>

#define TAM_NOME 100
#define TAM_SUS 19

struct Paciente
{
    char *nome;            // salva o nome do paciente
    Data *dataNasc;        // salva a data de nascimento do paciente
    char *cartaoSus;       // salva o cartão do SUS do paciente
    char genero;           // salva o gênero do paciente
    Lesao **lesoes;        // salva as lesões do paciente
    int qtdLesoes;         // salva a quantidade de lesões do paciente
    int qtdLesoesAlocadas; // controla a quantidade de lesões alocadas
};


Paciente *lePaciente()
{
    Paciente *p = (Paciente *)malloc(sizeof(Paciente));
    p->nome = (char *)malloc(TAM_NOME * sizeof(char));
    p->cartaoSus = (char *)malloc(TAM_SUS * sizeof(char));
    p->lesoes = NULL;

    p->qtdLesoes = 0;
    p->qtdLesoesAlocadas = 0;

    scanf("%[^\n]\n", p->nome);
    p->dataNasc = leData();
    scanf("%[^\n]\n", p->cartaoSus);
    scanf("%c", &p->genero);

    return p;
}


void liberaPaciente(Paciente *p)
{
    for (int i = 0; i < p->qtdLesoes; i++)
    {
        liberaLesao(p->lesoes[i]);
    }
    free(p->lesoes);
    free(p->nome);
    free(p->cartaoSus);
    liberaData(p->dataNasc);
    free(p);
}


void adicionaLesaoPaciente(Paciente *p, Lesao *l)
{
    p->lesoes = realloc(p->lesoes, (p->qtdLesoesAlocadas + 1) * sizeof(Lesao *));

    p->lesoes[p->qtdLesoesAlocadas] = l;
    p->qtdLesoes++;
    p->qtdLesoesAlocadas++;
}


int calculaIdadePaciente(Paciente *p, Data *ref)
{
    return calculaDiffAnosData(p->dataNasc, ref);
}


int getQtdCirurgiasPaciente(Paciente *p)
{
    int soma = 0;
    for (int i = 0; i < p->qtdLesoesAlocadas; i++)
    {
        if (precisaCirurgiaLesao(p->lesoes[i]) == 1)
            soma++;
    }
    return soma;
}

char *getCartaoSusPaciente(Paciente *p)
{
    return p->cartaoSus;
}


Data *getDataNascPaciente(Paciente *p)
{
    return p->dataNasc;
}


int getQtdLesoesPaciente(Paciente *p)
{
    return p->qtdLesoes;
}

void imprimeIdLesoesPaciente(Paciente *p)
{

    if (p->qtdLesoesAlocadas > 0)
    {
        printf("- %s ", p->nome);
        for (int i = 0; i < p->qtdLesoesAlocadas; i++)
        {
            printf("- %s", getIdLesao(p->lesoes[i]));
        }
        printf("\n");
    }
}