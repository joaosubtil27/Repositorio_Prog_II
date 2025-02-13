#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"

int main()
{
    float xc, yc, r, xp, yp;
    tCirculo c;
    tPonto p;

    scanf("%f %f %f %f %f", &xc, &yc, &r, &xp, &yp);

    c = Circulo_Cria(xc, yc, r);
    p = Pto_Cria(xp, yp);
    printf("%d", Circulo_Interior(c, p));
    Pto_Apaga(p);
    Circulo_Apaga(c);
    return 0;
}