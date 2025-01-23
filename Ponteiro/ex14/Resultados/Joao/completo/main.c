#include <stdio.h>
#include "tela.h"
#include "botao.h"
#include <string.h>

#define BOTOES 3
#define LARGURA 200
#define ALTURA 400

void Salva(){
    printf("- Botao de SALVAR dados ativado!\n");
}

void Exclui(){
    printf("- Botao de EXCLUIR dados ativado!\n");
}

void Opcoes(){
    printf("- Botao de OPCOES ativado!\n");
}
int main()
{
    Tela tela;
    Botao b1, b2, b3;
    tela = CriarTela(ALTURA, LARGURA);
    b1 = CriarBotao("Salvar", 12, "FFF", 1, Salva);
    b2 = CriarBotao("Excluir", 18, "000", 1, Exclui);
    b3 = CriarBotao("Opcoes", 10, "FF0000", 2, Opcoes);


    RegistraBotaoTela(&tela, b1);
    RegistraBotaoTela(&tela, b2);
    RegistraBotaoTela(&tela, b3);

    DesenhaTela(tela);
    OuvidorEventosTela(tela);

    return 0;
}