#include <stdio.h>
#include <stdlib.h>

#include "tMonitorador.h"
#include "tSensorPresenca.h"
#include "tSensorTemperatura.h"

int main()
{
    char op;
    int qntsensor, qnt_ciclos;
    void *s;

    scanf("%c\n", &op);
    scanf("%d\n", &qntsensor);

    if (op == 'T')
    {
        tMonitorador *m = criaMonitorador(processaSensorTemperatura, liberaSensorTemperatura);
        for (int i = 0; i < qntsensor; i++)
        {
            s = leSensorTemperatura(i+1);
            adicionaElementoMonitorador(m, s);
        }
        scanf("%d\n", &qnt_ciclos);
        iniciaMonitoramentotMonitorador(m, qnt_ciclos/qntsensor);

        liberaMonitorador(m);
    }

    else if (op == 'P')
    {
        tMonitorador *m = criaMonitorador(processaSensorPresenca, liberaSensorPresenca);

        for (int i = 0; i < qntsensor; i++)
        {
            s = leSensorPresenca(i+1);
            adicionaElementoMonitorador(m, s);
        }
        scanf("%d\n", &qnt_ciclos);
        iniciaMonitoramentotMonitorador(m, qnt_ciclos/qntsensor);

        liberaMonitorador(m);
    }

    return 0;
}