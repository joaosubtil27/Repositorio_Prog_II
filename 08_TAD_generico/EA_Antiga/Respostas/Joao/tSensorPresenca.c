#include "tSensorPresenca.h"
#include <stdio.h>
#include <stdlib.h>
/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
struct _tSensorPresenca
{
    int ultima_leitura;
    int id;
    int delay;
};

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorPresenca *leSensorPresenca(int id)
{
    tSensorPresenca *sp = (tSensorPresenca *)malloc(sizeof(tSensorPresenca));
    scanf("%d\n", &sp->delay);
    sp->id = id;
    sp->ultima_leitura = 0;
    return sp;
};

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorPresenca(void *s)
{
    free(s);
};

/***
Dado um sensor de temperatura valido, faz a leitura da temperatura ambiente do sensor fisico e
controla o estado do ar condicionado
A leitura do sensor de temperatura sera simulada aqui por uma leitura de um inteiro da entrada padrao
O controle do estado do ar condicionado sera simulado aqui com uma impressao em uma linha da saida padrao sendo
    "SENSOR(#ID)[#MIN-#MAX] processando TEMP:#T\n" em que #ID eh o id do sensor,
    #MIN e #MAX sao conforme definidos acima e #T eh a temperatura lida do sensor fisico, seguida de
    "(DESLIGANDO AR)" para representar que o ar deve desligar ao ficar abaixo da temperatura minima e estava ligado
    "(LIGANDO AR)" para representar que o ar deve ligar ao ficar acima da temperatura maxima e estiver desligado
    "(MANTEM AR)" caso contrario
*/
void processaSensorPresenca(void *s)
{
    tSensorPresenca *presenca = s;
    int leitura_atual;
    int cod;
    scanf("%d %d\n", &cod, &leitura_atual);
    printf("SENSOR(%d)[%d] processando PRESENCA:%d e %d", presenca->id, presenca->delay, cod, leitura_atual);
    if (cod == 0)
        printf("(AGUARDA)\n");
    else if (cod == 1)
    {
        if (presenca->ultima_leitura == 0)
        {
            printf("(NOTIFICA)\n");
            presenca->ultima_leitura = leitura_atual;
        }
        else if (leitura_atual - presenca->ultima_leitura > presenca->delay)
        {
            printf("(NOTIFICA)\n");
            presenca->ultima_leitura = leitura_atual;
        }
        else if ((leitura_atual - presenca->ultima_leitura <= presenca->delay))
            printf("(AGUARDA)\n");
    }
}
