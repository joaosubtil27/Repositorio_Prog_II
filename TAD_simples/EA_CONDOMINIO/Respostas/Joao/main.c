#include <stdio.h>
#include "reserva.h"

int main()
{
    int nAreas, nMoradores, nReservas;

    scanf("%d\n", &nAreas);
    Area areas[nAreas];
    for (int i = 0; i < nAreas; i++)
    {
        areas[i] = lerArea();
    }

    scanf("%d\n", &nMoradores);
    Morador moradores[nMoradores];
    for (int i = 0; i < nMoradores; i++)
    {
        moradores[i] = lerMorador();
    }

    scanf("%d\n", &nReservas);

    Reserva solicitacao_reservas[nReservas];
    Reserva calendario_reservas[nReservas];
    int valid;
    for (int i = 0; i < nReservas; i++)
    {
        valid = 0;
        scanf("%s\n", &solicitacao_reservas[i].area.id);
        scanf("%s\n", &solicitacao_reservas[i].morador.cpf);
        solicitacao_reservas[i].data = lerData();
        scanf("%d\n", &solicitacao_reservas[i].qtdConvidados);

        for (int j = 0; j < nMoradores; j++)
        {
            if (verificaCPFMorador(moradores[j], solicitacao_reservas[i].morador.cpf) == 1)
            {
                solicitacao_reservas[i].morador = moradores[j];
                valid++;
            }
        }
        for (int g = 0; g < nAreas; g++)
        {
            if (verificaIdArea(areas[g], solicitacao_reservas[i].area.id) == 1)
            {
                solicitacao_reservas[i].area = areas[g];
                valid++;
            }
        }
        
        if (valid == 2 && verificaSolicitacaoReserva(calendario_reservas, nReservas, solicitacao_reservas[i].morador, solicitacao_reservas[i].area, solicitacao_reservas[i].data, solicitacao_reservas[i].qtdConvidados) == 1)
        {   calendario_reservas[i] = solicitacao_reservas[i];
            imprimeReserva(solicitacao_reservas[i]);
        }
        
    }
    return 0;
}