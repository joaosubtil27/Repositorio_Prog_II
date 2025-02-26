#include "roteiro.h"
#include "pintura.h"
#include "musica.h"
#include "livro.h"

#include <stdlib.h>
#include <stdio.h>

int main()
{
    int qnt_midias;
    char op;
    void *pont;
    Roteiro *r = roteiro_construct();
    scanf("%d\n", &qnt_midias);
    for (int i = 0; i < qnt_midias; i++)
    {
        scanf("%c ", &op);
        if (op == 'L')
        {
            pont = livro_construct();

            roteiro_inserir_midia(r, pont, livro_print, livro_destroy);
        }

        else if (op == 'M')
        {
            pont = musica_construct();

            roteiro_inserir_midia(r, pont, musica_print, musica_destroy);
        }

        else if (op == 'P')
        {
            pont = pintura_construct();

            roteiro_inserir_midia(r, pont, pintura_print, pintura_destroy);
        }
    }
    roteiro_imprimir_midias(r);
    roteiro_destroy(r);
    return 0;
}