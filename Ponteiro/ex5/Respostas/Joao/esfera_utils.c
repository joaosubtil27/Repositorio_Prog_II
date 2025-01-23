#ifndef _ESFERA_UTILS_H
#define _ESFERA_UTILS_H
#include <math.h>
#define PI 3.14

/**
 * @brief Calcula o volume de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param volume Um ponteiro para uma variável float para armazenar o volume calculado.
 */
void CalculaVolume(float R, float *volume)
{

    *volume = (float)4 / 3 * PI * pow(R, 3);
}

/**
 * @brief Calcula a área de uma esfera com raio R.
 * @param R O raio da esfera.
 * @param area Um ponteiro para uma variável float para armazenar a área calculada.
 */
void CalculaArea(float R, float *area)
{
    *area = (float)4 * PI * pow(R, 2);
}

#endif