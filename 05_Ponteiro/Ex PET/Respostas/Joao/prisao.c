#include "prisao.h"

#define MAXTAM_NOME 100

/**
 * @brief Construtor do tipo prisão
 * @param nome Nome da prisão
 * @param nCelas Número de celas ocupadas
 * @param capacidadeCelas Número total de celas
 */

tPrisao criaPrisao(char *nome, int nCelas, int capacidadeCelas)
{
    tPrisao prisao;
    strcpy(prisao.nome, nome);
    prisao.nCelas = nCelas;
    prisao.capacidadeCelas = capacidadeCelas;
    prisao.dia = 0;
    for (int i = 0; i < prisao.nCelas; i++)
    {
        prisao.celas[i] = criaCela(capacidadeCelas);
    }
    return prisao;
}

/**
 * @brief Contém o loop do programa que deve imprimir o menu e selecionar opção
 */

void executaPrisao(tPrisao *prisao)
{
    char comando;
    while (1)
    {
        imprimeDiaEMenuPrisao(prisao);
        scanf("%c\n", &comando);
        if (comando == 'I')
        {   
            printf("Informe a pena e o nome do prisioneiro:\n");
            inserePrisioneiroPrisao(prisao);
        }
        else if (comando == 'P')
        {
            passaDiaPrisao(prisao);
        }
        else if (comando == 'F')
        {
            printf("Informe a cela em qual ocorreu a fuga:\n");
            registraFugaCelaPrisao(prisao);
        }
        else if (comando == 'E')
        {
            finalizaPrograma(prisao);
            break;
        }
        if (obtemNumeroPrisioneirosPrisao(prisao) == prisao->capacidadeCelas * prisao->nCelas)
        {
            rebeliaoGeralPrisao(prisao);
        }
    }
}

/**
 * @brief Imprime o menu
 */

void imprimeDiaEMenuPrisao(tPrisao *prisao)
{
    printf("Dia %d na prisao de %s\n", prisao->dia, prisao->nome);
    printf("Menu:\n");
    printf("I - Inserir detento\n");
    printf("P - Passar o dia\n");
    printf("F - Registrar fuga de cela\n");
    printf("E - Encerrar programa\n");
}

/**
 * @brief Faz a leitura e adiciona o prisioneiro na prisão
 */

void inserePrisioneiroPrisao(tPrisao *prisao)
{
    int tempo_sentenca;
    char nome[MAXTAM_NOME];
    int i = 0;
    tPrisioneiro prisioneiro;
    scanf("%d %[^\n]\n", &tempo_sentenca, nome);
    if (tempo_sentenca <= 0)
        printf("Valor invalido\n");
    else
    {
        prisioneiro = criaPrisioneiro(nome, tempo_sentenca);
        while (1)
        {
            if (i == prisao->nCelas)
                break;

            else if (possuiVagaCela(&prisao->celas[i]) == 1)
            {
                inserePrisioneiroCela(&prisao->celas[i], prisioneiro);
                printf("Detento %s foi inserido na cela %d\n", prisioneiro.nome, i);
                
                break;
            }
            i++;
        }
    }
}
/**
 * @brief Passa o dia em cada uma das celas da prisão
 */
void passaDiaPrisao(tPrisao *prisao)
{
    for (int i = 0; i < prisao->nCelas; i++)
    {
        passaDiaCela(&prisao->celas[i]);
    }
    prisao->dia++;
}
/**
 * @brief Le da entrada padrão o índice da cela no qual ocorreu a fuga
 */
void registraFugaCelaPrisao(tPrisao *prisao)
{
    int num_cela;
    scanf("%d\n", &num_cela);
    if (num_cela < 0)
        printf("Valor invalido\n");
    else
        fogePrisioneirosCela(&prisao->celas[num_cela]);
}

/**
 * @brief Finaliza o programa, havendo diferença na finalização caso tenha ou nao prisioneiros na prisao
 */

void finalizaPrograma(tPrisao *prisao)
{
    if (obtemNumeroPrisioneirosPrisao(prisao) > 0)
    {
        printf("Prisioneiros liberados para a finalizacao do programa!!!\n");
    }
    else if (obtemNumeroPrisioneirosPrisao(prisao) == 0)
    {
        printf("Fim do programa.\n");
    }
}

/**
 * @brief Obtém o total de prisioneiros
 */

int obtemNumeroPrisioneirosPrisao(tPrisao *prisao)
{
    int soma = 0;
    for (int i = 0; i < prisao->nCelas; i++)
    {
        soma += prisao->celas[i].nPresidiarios;
    }
    return soma;
}

/**
 * @brief Imprime mensagem de rebelião e realiza fuga de todos os prisioneiros
 */

void rebeliaoGeralPrisao(tPrisao *prisao)
{
    printf("REBELIAO GERAL\n");
    for (int i = 0; i < prisao->nCelas; i++)
    {
        fogePrisioneirosCela(&prisao->celas[i]);
    }
    finalizaPrograma(prisao);
    exit(1);
}
