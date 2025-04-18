#include <string.h>

#define MAX_TAM_NOME 100
#define MAX_TAM_ID 5

typedef struct
{
    char nome[MAX_TAM_NOME];
    char id[MAX_TAM_ID];
    int capacidade;
} Area;

/**
 * Função que lê uma área comum de acordo com o formato de entrada descrito na
 * especificação e retorna a Area lida.
 */
Area lerArea()
{
    Area a;
    int i = 0;
    while (1)
    {
        scanf("%c", &a.nome[i]);
        if (a.nome[i] == '\n')
            break;

        i++;
    }
    a.nome[i] = '\0';

    i = 0;
    while (1)
    {
        scanf("%c", &a.id[i]);
        if (a.id[i] == '\n')
            break;

        i++;
    }
    a.id[i] = '\0';

    scanf("\n%d\n", &a.capacidade);

    return a;
}

/**
 * Função que imprime todas as informações de uma Area conforme o formato
 * descrito na especificação. Dica: veja o arquivo de saída nos casos de teste.
 *
 */
void imprimeArea(Area a)
{
    printf("Nome: ");
    int i = 0;
    while (a.nome[i] != '\0')
    {
        printf("%c", a.nome[i]);
        i++;
    }
    printf("\n");
    i = 0;
    printf ("Id: ");
    while (a.id[i] != '\0')
    {
        printf("%c", a.id[i]);
        i++;
    }
    printf("\nCapacidade: %d convidado(s)\n", a.capacidade);
}

/*
 * Função que compara se duas áreas são iguais através do
 * id delas.
 * Retorna 1 se forem iguais e 0 caso contrário
 */
int comparaArea(Area a1, Area a2)
{
    if (strcmp(a1.id, a2.id) == 0)
        return 1;
    else
        return 0;
}

/*
 * Função que verifica se o id passado é igual ao id da área passada
 * Retorna 1 se for igual e 0 caso contrário
 */
int verificaIdArea(Area a, char *id)
{
    if (strcmp(a.id, id) == 0)
        return 1;
    else
        return 0;
}

/**
 * Função que retorna a capacidade de uma área comum.
 */
int getCapacidadeArea(Area a)
{
    return a.capacidade;
}
