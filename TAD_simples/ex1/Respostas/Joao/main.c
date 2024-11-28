#include <stdio.h>
#include "jogada.h"
#include "jogador.h"
#include "tabuleiro.h"
#include "jogo.h"

int main()
{

    tJogo jogo;
    tJogada jogada;
    jogo = CriaJogo();
    int quem_joga;
    quem_joga = 1;
    while (AcabouJogo(jogo) == 0 && ContinuaJogo() != 1)
    {
        printf("Jogador %d\n", quem_joga);
        printf("Digite uma posicao (x e y):");

        jogada = LeJogada();
        if (jogada.sucesso == 1){
        if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
        {
            if (EstaLivrePosicaoTabuleiro(jogo.tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
            {
                printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                
            }
            else
                printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
        }
        else
            printf("Posicao invalida (FORA DO TABULEIRO- [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
    }
    }


    return 0;
}