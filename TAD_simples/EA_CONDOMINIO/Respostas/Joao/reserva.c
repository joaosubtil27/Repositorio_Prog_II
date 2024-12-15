#include "data.h"
#include "morador.h"
#include "area.h"

typedef struct
{
    Morador morador;
    Area area;
    Data data;
    int qtdConvidados;
} Reserva;

/**
 * Função que recebe os dados necessários para criar uma reserva
 * e retorna a reserva criada.
 * morRes: Morador que está fazendo a reserva
 * aRes: Área que está sendo reservada
 * dRes: Data da reserva
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna uma Reserva com os dados informados
 */
Reserva criaReserva(Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    Reserva res;
    res.morador = morRes;
    res.area = aRes;
    res.data = dRes;
    res.qtdConvidados = qtdConvidados;
    return res;
}

/**
 * Função que verifica se é possível realizar uma reserva solicitada com os dados informados.
 * Essa verificação é baseada em todas as regras de reserva de áreas comuns descritas na especificação.
 *
 * agendaReservas: array que armazena todas as reservas de áreas comuns já realizadas
 * nRes: quantidade de reservas contidas no array agendaReservas
 * morRes: Morador que está solicitando a reserva
 * aRes: Área que está sendo solicitada
 * dRes: Data da reserva solicitada
 * qtdConvidados: Quantidade de convidados que o morador irá levar
 *
 * Retorna 1 se a reserva pode ser realizada e 0 caso contrário
 */
int verificaSolicitacaoReserva(Reserva *agendaReservas, int nRes, Morador morRes, Area aRes, Data dRes, int qtdConvidados){
    int valid = 1;
    if (calcularDiffAnosData(morRes.dataNasc, dRes) >= 18 && qtdConvidados<= aRes.capacidade){
        
        for (int i = 0; i<nRes; i++){
            if ((verificaCPFMorador(agendaReservas[i].morador, morRes.cpf) == 1 || comparaArea(agendaReservas[i].area, aRes) == 1) && comparaData(agendaReservas[i].data, dRes) == 1){
             valid = 0;
            }
        
        }
    }
    else
    valid=0;

   return valid;
}

/**
 * Função que imprime todas as informações de uma Reserva conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeReserva(Reserva r){

    printf ("--------- RESERVA -----------\n");
    printf("Morador:\n");
    imprimeMorador(r.morador);
    printf ("\nArea reservada:\n");
    imprimeArea(r.area);
    printf ("Data da reserva: ");
    imprimeData(r.data);
    printf("\nQuantidade de convidados: %d\n", r.qtdConvidados);
    printf ("Taxa de ocupação: %d%%\n", 100*r.qtdConvidados/r.area.capacidade);
    printf ("------------------------------\n");

}
