#include "tMonitorador.h"
#include <stdio.h>
#include <stdlib.h>

#define INICIO_ELEM_ALOC 5
typedef void (*FptrProcessaElemento)(void *e);
typedef void (*FptrLiberaElemento)(void *e);

/***
O monitorador eh um TAD generico uniforme que tem o objetivo de
varrer os sensores registrados processando cada um deles continuamente.
*/
struct _tMonitorador
{
    void **elementos;
    int qnt_elementos_atual;
    int qnt_elementos_alocado;
    FptrProcessaElemento processa;
    FptrLiberaElemento free;
};

/***
Cria um monitorador valido definindo, de acordo com o tipo de elemento, suas funcoes de
Processar elemento e Liberar elemento
*/
tMonitorador *criaMonitorador(FptrProcessaElemento funcPE, FptrLiberaElemento funcLE)
{
    tMonitorador *m = (tMonitorador *)malloc(sizeof(tMonitorador));

    m->processa = funcPE;
    m->free = funcLE;
    m->qnt_elementos_alocado = INICIO_ELEM_ALOC;
    m->qnt_elementos_atual = 0;

    m->elementos = (void **)malloc(m->qnt_elementos_alocado * sizeof(void *));
    return m;
}

/***
Dado um monitorador valido, libera sua memoria incluindo a de cada um de seus elementos adicionados
*/
void liberaMonitorador(tMonitorador *m)
{
    for (int i = 0; i < m->qnt_elementos_atual; i++)
    {
        m->free(m->elementos[i]);
    }
    free(m->elementos);
    free(m);
}

/***
Dado um monitorador valido e um elemento, adiciona o elemento ao cojunto a ser monitorado
*/
void adicionaElementoMonitorador(tMonitorador *m, void *e)
{
    if (m->qnt_elementos_alocado == m->qnt_elementos_atual)
    {
        m->qnt_elementos_alocado += INICIO_ELEM_ALOC;
        m->elementos = (void **)realloc(m->elementos, m->qnt_elementos_alocado * sizeof(void *));
    }
    m->elementos[m->qnt_elementos_atual] = e;
    m->qnt_elementos_atual++;
}

/***
Dado um monitorador valido, inicia o monitoramento que durara pelo numero de ciclos informado em numeroDeCiclos
Se numeroDeCiclos for negativo, o monitoramento sera infinito.
O monitoramento consiste em, a cada ciclo, processar cada elemento registrado para monitoramento
*/
int iniciaMonitoramentotMonitorador(tMonitorador *m, int numeroDeCiclos)
{
    for (int i = 0; i < numeroDeCiclos; i++)
    {
        for (int j = 0; j < m->qnt_elementos_atual; j++)
        {
            m->processa(m->elementos[j]);
        }
    }
}