
#include <stdio.h>
#include "servidor.h"
#include "registro.h"
#include "jogador.h"

int main()
{
    Servidor servidor;

    servidor = leRegistrosServidor();
    criaRelatorioServidor(servidor);
}
