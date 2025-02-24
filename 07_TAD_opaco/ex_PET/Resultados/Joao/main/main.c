#include "brasileirao.h"
#include <stdlib.h>
int main()
//{
    BRA *br;
    br = CriaCamp();
    RealizaRodada(br);
    DesalocaCamp(br);
    return 0;
}