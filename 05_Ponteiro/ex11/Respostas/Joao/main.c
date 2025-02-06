#include <stdio.h>
#include "calculadora.h"

float soma(float a, float b)
{
    return a + b;
}
float subtracao(float a, float b)
{
    return a - b;
}
float multiplicacao(float a, float b)
{
    return a * b;
}
float divisao(float a, float b)
{
    return a / b;
}

int main()
{
    char op;
    float num1, num2;
    CalculatoraCallback operacao;
    while (1)
    {
        scanf("%c\n", &op);
        if (op == 'f')
            break;
            
        scanf("%f %f\n", &num1, &num2);
        if (op == 'a')
        {
            operacao = soma;
            printf("%.2f + %.2f = ", num1, num2);
        }
        else if (op == 's')
        {
            operacao = subtracao;
            printf("%.2f - %.2f = ", num1, num2);
        }
        else if (op == 'm')
        {
            operacao = multiplicacao;
            printf("%.2f x %.2f = ", num1, num2);
        }
        else if (op == 'd')
        {
            operacao = divisao;
            printf("%.2f / %.2f = ", num1, num2);
        }
        printf("%.2f\n", Calcular(num1, num2, operacao));
    }
}