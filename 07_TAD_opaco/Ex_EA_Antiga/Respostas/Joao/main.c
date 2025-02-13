#include <stdio.h>
#include "gerenciador.h"


int main(){

Gerenciador *g = criaGerenciador();
preencheBancoPacientesGerenciador(g);
imprimeRelatorioGerenciador(g);
liberaGerenciador(g);
}