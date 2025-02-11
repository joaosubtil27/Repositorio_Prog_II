#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lesao.h"
#include "paciente.h"
#include "pad.h"

#define DIA_PAD 15   /**< Dia de preenchimento do PAD. */
#define MES_PAD 10   /**< Mês de preenchimento do PAD. */
#define ANO_PAD 2023 /**< Ano de preenchimento do PAD. */

/**
 * @brief Uma estrutura que representa um PAD.
 */

/**
 * @brief Cria um novo PAD.
 *
 * @return Retorna um ponteiro para a estrutura de dados tPad contendo o novo PAD criado.
 */
tPad *CriaPad()
{
    tPad *pad = (tPad *)malloc(sizeof(tPad));
    pad->qtdpacientes = 0;

    return pad;
}

/**
 * @brief Roda o PAD, permitindo que o usuário adicione pacientes e lesões.
 *
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser rodado.
 */
void RodaPad(tPad *p)
{
    char opcao;
    int valid;
    while (1)
    {
        valid = 0;
        scanf("%c\n", &opcao);

        if (opcao == 'P')
        {
            p->qtdpacientes[p->listapacientes] = CriaPaciente();
            LePaciente(p->qtdpacientes[p->listapacientes]);
            p->qtdpacientes++;
        }
        else if (opcao == 'L')
        {
            char verifica_sus[TAM_CSUS];
            scanf("%[^\n]\n", verifica_sus);
            tLesao *l = CriaLesao();
            LeLesao(l);
            for (int i = 0; i < p->qtdpacientes; i++)
            {
                if (strcmp(verifica_sus, p->listapacientes[i]->cartaoSus) == 0)
                {
                    AdicionaLesaoPaciente(p->listapacientes[i], l);
                    valid = 1;
                }
            }
            if (valid == 0)
                LiberaLesao(l);
        }
        if (opcao == 'F')
            break;
    }
}

/**
 * @brief Imprime um relatório com as informações dos pacientes e lesões do PAD.
 *
 * @param p Ponteiro para a estrutura de dados tPad contendo o PAD a ser impresso.
 */
void ImprimeRelatorioPad(tPad *p)
{
    int qnt_cirurgias = 0;
    int soma_idades = 0;
    int qnt_lesoes = 0;
    int media = 0;
    tData *d = CriaData(DIA_PAD, MES_PAD, ANO_PAD);
    for (int i = 0; i < p->qtdpacientes; i++)
    {
        qnt_cirurgias += GetQtdCirurgiasPaciente(p->listapacientes[i]);
        soma_idades += CalculaIdadeData(p->listapacientes[i]->nascimento, d);
        qnt_lesoes += p->listapacientes[i]->qtdLesoes;
    }
    if (p->qtdpacientes > 0)
        media = soma_idades / p->qtdpacientes;

    printf("TOTAL PACIENTES: %d\n", p->qtdpacientes);
    printf("MEDIA IDADE (ANOS): %d\n", media);
    printf("TOTAL LESOES: %d\n", qnt_lesoes);
    printf("TOTAL CIRURGIAS: %d\n", qnt_cirurgias);
    printf("LISTA DE PACIENTES:\n");
    for (int i = 0; i < p->qtdpacientes; i++)
    {
        ImprimePaciente(p->listapacientes[i]);
    }

    LiberaData(d);
}

/**
 * @brief Libera a memória alocada para uma estrutura de dados tPad.
 *
 * @param p Ponteiro para a estrutura de dados tPad a ser liberada.
 */
void LiberaPad(tPad *p)
{

    for (int i = 0; i < p->qtdpacientes; i++)
        LiberaPaciente(p->listapacientes[i]);

    free(p);
}
