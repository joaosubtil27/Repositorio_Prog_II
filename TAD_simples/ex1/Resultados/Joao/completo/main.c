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
    while (1)
    {
        while (1)
        {
            printf("Jogador 1\n");

            jogada = LeJogada();
            if (jogada.sucesso == 1)
            {
                if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
                {
                    if (EstaLivrePosicaoTabuleiro(jogo.tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
                    {
                        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        jogo.tabuleiro = MarcaPosicaoTabuleiro(jogo.tabuleiro, jogo.jogador1.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        if (EstaMarcadaPosicaoPecaTabuleiro(jogo.tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), jogo.jogador1.id) == 1)
                        {
                            ImprimeTabuleiro(jogo.tabuleiro);
                            break;
                        }
                    }

                    else
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
                else
                    printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }

        while (VenceuJogador(jogo.jogador1, jogo.tabuleiro) == 0 && AcabouJogo(jogo) == 0)
        {
            printf("Jogador 2\n");

            jogada = LeJogada();
            if (jogada.sucesso == 1)
            {
                if (EhPosicaoValidaTabuleiro(ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
                {
                    if (EstaLivrePosicaoTabuleiro(jogo.tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada)) == 1)
                    {
                        printf("Jogada [%d,%d]!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        jogo.tabuleiro = MarcaPosicaoTabuleiro(jogo.tabuleiro, jogo.jogador2.id, ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                        if (EstaMarcadaPosicaoPecaTabuleiro(jogo.tabuleiro, ObtemJogadaX(jogada), ObtemJogadaY(jogada), jogo.jogador2.id) == 1)
                        {
                            ImprimeTabuleiro(jogo.tabuleiro);
                            break;
                        }
                    }

                    else
                        printf("Posicao invalida (OCUPADA - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
                }
                else
                    printf("Posicao invalida (FORA DO TABULEIRO - [%d,%d] )!\n", ObtemJogadaX(jogada), ObtemJogadaY(jogada));
            }
        }
        if (AcabouJogo(jogo) == 1 || VenceuJogador(jogo.jogador2, jogo.tabuleiro) == 1 || VenceuJogador(jogo.jogador1, jogo.tabuleiro) == 1)
        {
            if (VenceuJogador(jogo.jogador2, jogo.tabuleiro) == 1)
                printf("JOGADOR 2 Venceu!\n");

            else if (VenceuJogador(jogo.jogador1, jogo.tabuleiro) == 1)
                printf("JOGADOR 1 Venceu!\n");
            else
                printf("Sem vencedor!\n");

            if (ContinuaJogo() == 1)
            {
                jogo = CriaJogo();
            }
            else
                exit(0);
        }
    }
    return 0;
}