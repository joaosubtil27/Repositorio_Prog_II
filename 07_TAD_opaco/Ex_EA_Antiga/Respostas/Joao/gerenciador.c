
// Dados de referência para cálculo de idade
#define DIA_BASE 1
#define MES_BASE 8
#define ANO_BASE 2024

#include "paciente.h"
#include "gerenciador.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Gerenciador
{
    Paciente **bancoPacientes;
    int tamBanco;
    int tamBancoAlocado;
};

/*
Função que cria uma estrutura Gerenciador (alocando toda memória necessária), inicializa o que for necessário
e retorna o ponteiro para a estrutura criada.
*/
Gerenciador *criaGerenciador()
{
    Gerenciador *g = (Gerenciador *)malloc(sizeof(Gerenciador));
    g->tamBanco = 0;
    g->tamBancoAlocado = 0;
    g->bancoPacientes = NULL;
    return g;
}

/*
Função que adiciona um paciente ao banco de pacientes do gerenciador.
Se for necessário mais memória para alocar um novo paciente, essa função deve realocar a memória necessária.
*/
void adicionaPacienteBancoGerenciador(Gerenciador *g, Paciente *p)
{
    g->bancoPacientes = realloc(g->bancoPacientes, (g->tamBancoAlocado + 1) * sizeof(Paciente *));

    g->bancoPacientes[g->tamBancoAlocado] = p;
    g->tamBancoAlocado++;
    g->tamBanco++;
}

/*
Função que busca e retorna um paciente (se existir) no banco de pacientes do gerenciador a partir do cartão do SUS.
Se não encontrar o paciente, retorna NULL.
*/
Paciente *getPacientePeloSUSBancoGerenciador(Gerenciador *g, char *sus)
{
    for (int i = 0; i < g->tamBancoAlocado; i++)
    {
        if (strcmp(sus, getCartaoSusPaciente(g->bancoPacientes[i])) == 0)
            return g->bancoPacientes[i];
    }
    return NULL;
}

/*
Função que le os dados de pacientes e lesões a partir da entrada padrão e preenche o banco de
pacientes do gerenciador. Essa leitura seguem as regras descritas na descrição.
Perceba que o banco salva apenas os pacientes, as lesões são salvas nos pacientes.
*/
void preencheBancoPacientesGerenciador(Gerenciador *g)
{
    char op;
    char c_sus[TAM_SUS];

    while (1)
    {
        scanf("%c\n", &op);

        if (op == 'F')
        {
            break;
        }
        else if (op == 'P')
        {
            adicionaPacienteBancoGerenciador(g, lePaciente());
        }
        else if (op == 'L')
        {
            scanf("%[^\n]\n", c_sus);
            Lesao *l = leLesao();
            if (getPacientePeloSUSBancoGerenciador(g, c_sus) != NULL)
            {
                adicionaLesaoPaciente(getPacientePeloSUSBancoGerenciador(g, c_sus), l);
            }
            else
                liberaLesao(l);
        }
    }
}

/*
Função que libera a memória alocada para a estrutura Gerenciador.
Ela verifica se o ponteiro passado é nulo antes de tentar liberar a memória.
*/
void liberaGerenciador(Gerenciador *g)
{
    for (int i = 0; i < g->tamBancoAlocado; i++)
    {
        liberaPaciente(g->bancoPacientes[i]);
    }
    free(g->bancoPacientes);
    free(g);
}

/*
Função que calcula a média de idade dos pacientes do banco de pacientes do gerenciador.
Para isso, é necessário calcular a idade de cada paciente em relação a data de referência.
*/
int calculaMediaIdadePacientesBancoGerenciador(Gerenciador *g)
{
    int soma = 0;
    Data *d = criaData(DIA_BASE, MES_BASE, ANO_BASE);
    if (g->tamBancoAlocado > 0)
    {
        for (int i = 0; i < g->tamBancoAlocado; i++)
        {
            soma += calculaIdadePaciente(g->bancoPacientes[i], d);
        }
        free(d);
        return soma / g->tamBancoAlocado;
    }

    free(d);
    return 0;
}

/*
Função que imprime os pacientes do banco de pacientes do gerenciador de acordo com a descrição.
*/
void imprimePacientesBancoGerenciador(Gerenciador *g)
{
    for (int i = 0; i < g->tamBancoAlocado; i++)
    {
        imprimeIdLesoesPaciente(g->bancoPacientes[i]);
    }
}

/*
Função que calcula a quantidade total de lesões dos pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões associadas, retorna 0.
*/
int calculaQtdLesoesPacientesBancoGerenciador(Gerenciador *g)
{
    int soma = 0;
    for (int i = 0; i < g->tamBancoAlocado; i++)
    {
        soma += getQtdLesoesPaciente(g->bancoPacientes[i]);
    }
    return soma;
}

/*
Função que calcula a quantidade total de cirurgias necessárias para os pacientes do banco de pacientes do gerenciador.
Se não houver pacientes ou lesões que necessitam de cirurgia, retorna 0.
*/
int calculaQtdCirurgiaPacientesBancoGerenciador(Gerenciador *g)
{
    int soma = 0;
    for (int i = 0; i < g->tamBancoAlocado; i++)
    {
        soma += getQtdCirurgiasPaciente(g->bancoPacientes[i]);
    }
    return soma;
}

/*
Função que imprime o relatório do gerenciador de acordo com a descrição da atividade.
*/
void imprimeRelatorioGerenciador(Gerenciador *g)
{
    printf("TOTAL PACIENTES: %d\n", g->tamBancoAlocado);
    printf("MEDIA IDADE (ANOS): %d\n", calculaMediaIdadePacientesBancoGerenciador(g));
    printf("TOTAL LESOES: %d\n", calculaQtdLesoesPacientesBancoGerenciador(g));
    printf("TOTAL CIRURGIAS: %d\n", calculaQtdCirurgiaPacientesBancoGerenciador(g));
    printf("LISTA DE PACIENTES:\n");
    if (calculaQtdCirurgiaPacientesBancoGerenciador(g) > 0)
    {

        imprimePacientesBancoGerenciador(g);
    }
}