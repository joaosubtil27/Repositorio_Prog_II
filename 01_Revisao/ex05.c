#include <stdio.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0
#define ENCURRALADO 4

typedef struct
{

    int i, j;

} tCoord;

int mov_Baixo(tCoord jogador, int mapa[100][100]);
int mov_Cima(tCoord jogador, int mapa[100][100]);
int mov_Direita(tCoord jogador, int mapa[100][100]);
int mov_Esquerda(tCoord jogador, int mapa[100][100]);
int Movimentacao(tCoord jogador, int mapa[100][100], char mov[100]);
int Verif_encurralado(tCoord jogador, int mapa[100][100]);

int main()
{

    int i, j;
    int g = 0;
    int col, linha;
    int qnt_sec_mov = 0;
    int mapa[100][100];

    char mov[100];

    tCoord inicio, fim, jogador;

    scanf("%d %d ", &linha, &col);

    for (i = 1; i <= linha; i++)
    {
        for (j = 1; j <= col; j++)
        {
            scanf("%d", &mapa[i][j]);
        }
    }

    scanf("%d %d ", &inicio.i, &inicio.j);
    scanf("%d %d ", &fim.i, &fim.j);
    while (1)
    {
        scanf("%c", &mov[qnt_sec_mov]);
        if (mov[qnt_sec_mov] == 10)
            break;

        qnt_sec_mov++;
    }
    jogador.i = inicio.i;
    jogador.j = inicio.j;

    while (Verif_encurralado(jogador, mapa) != ENCURRALADO && (jogador.i != fim.i || jogador.j != fim.j))
    {

        if (mov[Movimentacao(jogador, mapa, mov)] == 'B')
        {
            mapa[jogador.i][jogador.j] = 2;
            printf("(%d, %d) ", jogador.i, jogador.j);
            jogador.i++;
        }

        else if (mov[Movimentacao(jogador, mapa, mov)] == 'C')
        {
            mapa[jogador.i][jogador.j] = 2;
            printf("(%d, %d) ", jogador.i, jogador.j);
            jogador.i--;
        }

        else if (mov[Movimentacao(jogador, mapa, mov)] == 'D')
        {
            mapa[jogador.i][jogador.j] = 2;
            printf("(%d, %d) ", jogador.i, jogador.j);
            jogador.j++;
        }

        else if (mov[Movimentacao(jogador, mapa, mov)] == 'E')
        {
            mapa[jogador.i][jogador.j] = 2;
            printf("(%d, %d) ", jogador.i, jogador.j);
            jogador.j--;
        }
    }
    printf("(%d, %d) ", jogador.i, jogador.j);
}

int mov_Baixo(tCoord jogador, int mapa[100][100])
{
    if (mapa[jogador.i + 1][jogador.j] == 0 && jogador.i + 1 <= 7)
        return VERDADEIRO;

    else
        return FALSO;
}

int mov_Cima(tCoord jogador, int mapa[100][100])
{
    if (mapa[jogador.i - 1][jogador.j] == 0 && jogador.i - 1 > 0)
        return VERDADEIRO;

    else
        return FALSO;
}

int mov_Direita(tCoord jogador, int mapa[100][100])
{
    if (mapa[jogador.i][jogador.j + 1] == 0 && jogador.i + 1 <= 7)
        return VERDADEIRO;

    else
        return FALSO;
}

int mov_Esquerda(tCoord jogador, int mapa[100][100])
{
    if (mapa[jogador.i][jogador.j - 1] == 0 && jogador.j - 1 > 0)
        return VERDADEIRO;

    else
        return FALSO;
}

int Movimentacao(tCoord jogador, int mapa[100][100], char mov[100]) // Verifica quais movimentaçoes sao possiveis e quem sera executado dada a prefencia
{
    int mov_preferencia = 4;
    int i;

    if (mov_Baixo(jogador, mapa) == VERDADEIRO)
    {
        for (i = 0; i < 4; i++)
        {
            if (mov[i] == 'B' && i < mov_preferencia)
                mov_preferencia = i;
        }
    }
    if (mov_Cima(jogador, mapa) == VERDADEIRO)
    {
        for (i = 0; i < 4; i++)
        {
            if (mov[i] == 'C' && i < mov_preferencia)
                mov_preferencia = i;
        }
    }
    if (mov_Direita(jogador, mapa) == VERDADEIRO)
    {
        for (i = 0; i < 4; i++)
        {
            if (mov[i] == 'D' && i < mov_preferencia)
                mov_preferencia = i;
        }
    }
    if (mov_Esquerda(jogador, mapa) == VERDADEIRO)
    {
        for (i = 0; i < 4; i++)
        {
            if (mov[i] == 'E' && i < mov_preferencia)
                mov_preferencia = i;
        }
    }
    return mov_preferencia;
}

int Verif_encurralado(tCoord jogador, int mapa[100][100])
{
    int valid = VERDADEIRO;

    if (mov_Baixo(jogador, mapa) == FALSO && mov_Cima(jogador, mapa) == FALSO && mov_Direita(jogador, mapa) == FALSO && mov_Esquerda(jogador, mapa) == FALSO)
    {
        valid = ENCURRALADO;
    }

    return valid;
}

/*printf ("\n");
for (i=0; i< linha; i++){
 for (j=0; j<col; j++){
 printf ("%d", mapa[i][j]);
 }
 printf ("\n");
}*/