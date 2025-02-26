#include "gerenciadorpacotes.h"

#define NUM_PAC_INICIAL 10
struct gerenciadorpacotes
{
    tPacote **pacotes;
    int qnt_pacotes_alocado;
    int qnt_pacotes;
};

/**
 * @brief Cria uma TAD que gerencia pacotes. O pacote é um TAD genérico.
 *
 *
 * @return O gerenciador de pacotes
 */
tGerenciador *CriaGerenciador()
{
    tGerenciador *g = (tGerenciador *)malloc(sizeof(tGerenciador));
    g->pacotes = (tPacote **)malloc(NUM_PAC_INICIAL * sizeof(tPacote *));
    g->qnt_pacotes = 0;
    g->qnt_pacotes_alocado = NUM_PAC_INICIAL;

    return g;
}

/**
 * @brief Adiciona um pacote ao gerenciador de pacotes.
 *
 * @param geren O gerenciador de pacotes que armazenará o pacote
 * @param pac O pacote que queremos adicionar no gerenciador.
 *
 */
void AdicionaPacoteNoGerenciador(tGerenciador *geren, tPacote *pac)
{
    if (geren->qnt_pacotes == geren->qnt_pacotes_alocado)
    {
        geren->qnt_pacotes_alocado += NUM_PAC_INICIAL;
        geren->pacotes = realloc(geren->pacotes, (geren->qnt_pacotes_alocado) * sizeof(tPacote *));
    }
    geren->pacotes[geren->qnt_pacotes] = pac;
    geren->qnt_pacotes++;
}

/**
 * @brief Destrói um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que será destruído (memória liberada)
 *
 */
void DestroiGerenciador(tGerenciador *geren)
{
    for (int i = 0; i < geren->qnt_pacotes; i++)
    {
        DestroiPacote(geren->pacotes[i]);
    }
    free(geren->pacotes);
    free(geren);
}

/**
 * @brief Imprime um pacote específico do gerenciador de pacotes.
 *
 * @param geren - O gerenciador de pacotes que terá um pacote impresso
 * @param idx - O índice do pacote a ser impresso (começa em zero!)
 *
 */
void ImprimirPacoteNoIndice(tGerenciador *geren, int idx)
{
    ImprimePacote(geren->pacotes[idx]);
}

/**
 * @brief Imprime todos os pacotes de um gerenciador de pacotes
 *
 * @param geren O gerenciador de pacotes que terá seus pacotes impressos
 *
 */
void ImprimirTodosPacotes(tGerenciador *geren)
{
    for (int i = 0; i < geren->qnt_pacotes; i++)
    {
        ImprimePacote(geren->pacotes[i]);
    }
}
