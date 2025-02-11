#include <stdio.h>
#include <stdlib.h>

#include "pad.h"

int main()
{
    tPad *p = CriaPad();
    RodaPad(p);
    ImprimeRelatorioPad(p);
    LiberaPad(p);
}