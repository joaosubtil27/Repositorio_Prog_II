#include "tSensorTemperatura.h"
#include <stdio.h>
#include <stdlib.h>
#define DESLIGADO 0
#define LIGADO 1
/***
O sensor servira para controlar um ar condicionado (que inicialmente esta desligado)
baseado em uma temperatura ambiente.
*/
struct _tSensorTemperatura
{
    int tMax;
    int tMin;
    int onoff;
    int id;
};

/***
Le as configuracoes de um sensor de temperatura da entrada padrao e retorna um sensor valido com
o id recebido como parametro. O sensor servira para controlar um ar que inicialmente esta desligado.
Configuracoes serao dadas em uma linha seguindo "#MIN #MAX"
#MIN sendo a temperatura limite minima para desligar o AR ao ficar abaixo dela
#MAX sendo a temperatura limite maxima para ligar o AR ao ficar acima dela
*/
tSensorTemperatura *leSensorTemperatura(int id)
{

    tSensorTemperatura *s = (tSensorTemperatura *)malloc(sizeof(tSensorTemperatura));
    s->id = id;
    scanf("%d %d\n", &s->tMin, &s->tMax);
    s->onoff = DESLIGADO;
    return s;
}

/***
Dado um sensor de temperatura valido, libera sua memoria
*/
void liberaSensorTemperatura(void *s)
{
    free(s);
}

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
void processaSensorTemperatura(void *s)
{
    tSensorTemperatura *sensor = s;
    int temp;
    if (scanf("%d\n", &temp) != EOF)
    {

        printf("SENSOR(%d)[%d-%d] processando TEMP:%d", sensor->id, sensor->tMin, sensor->tMax, temp);
        if (temp > sensor->tMax)
        {
            if (sensor->onoff == DESLIGADO)
            {
                sensor->onoff = LIGADO;
                printf("(LIGANDO AR)\n");
            }
            else
                printf("(MANTEM AR)\n");
        }
        else if (temp < sensor->tMin)
        {
            if (sensor->onoff == LIGADO)
            {
                sensor->onoff = DESLIGADO;
                printf("(DESLIGANDO AR)\n");
            }
            else
                printf("(MANTEM AR)\n");
        }
        else
            printf("(MANTEM AR)\n");
    }
}