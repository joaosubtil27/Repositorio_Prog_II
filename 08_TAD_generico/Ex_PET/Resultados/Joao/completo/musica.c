#include "musica.h"
#include <stdlib.h>
#include <stdio.h>

#define MAXTAM_STRINGS 100

struct Musica
{
    int n_participantes;
    char titulo[MAXTAM_STRINGS];
    char artista[MAXTAM_STRINGS];
    char genero[MAXTAM_STRINGS];
    char album[MAXTAM_STRINGS];
    char **participantes;
};

// Aloca dinamicamente uma nova estrutura Musica e realiza a leitura dos dados
// de entrada associados à música. Pode envolver múltiplos participantes na música.
// Retorna: Ponteiro para a Musica recém-criada, com os dados carregados.
Musica *musica_construct()
{
    Musica *m = (Musica *)malloc(sizeof(Musica));
    scanf("%s ", m->titulo);
    scanf("%s ", m->artista);
    scanf("%d ", &m->n_participantes);
    m->participantes = (char **)malloc(m->n_participantes * sizeof(char *));
    for (int i = 0; i < m->n_participantes; i++)
    {
        m->participantes[i] = (char*)malloc(MAXTAM_STRINGS * sizeof(char));
        scanf("%s ", m->participantes[i]);
    }
    scanf("%s ", m->album);
    scanf("%s\n", m->genero);

    return m;
}

// Imprime os dados da música. Recebe um ponteiro genérico para a música
// e exibe suas informações relevantes, como título, artistas, etc.
// Parâmetros:
//  m - Ponteiro para a Musica a ser impressa.
void musica_print(void *m)
{
    Musica *musica = m;
    printf("MUSICA\n");
    printf("%s - %s (feat. ", musica->artista, musica->titulo);
    for (int i = 0; i < musica->n_participantes; i++)
    {
        printf("%s", musica->participantes[i]);
        if (i < musica->n_participantes - 1)
        {
            printf(", ");
        }
    }
    printf(")\n");
    printf("Album: %s\n", musica->album);
    printf("Genero: %s\n", musica->genero);
}

// Libera a memória alocada para a música, desalocando a estrutura Musica
// e seus dados associados de forma adequada.
// Parâmetros:
//  m - Ponteiro para a Musica a ser destruída.
void musica_destroy(void *m)
{
    Musica *musica = m;
    for (int i = 0; i < musica->n_participantes; i++)
    {
        free(musica->participantes[i]);
    }
    free(musica->participantes);
    free(musica);
}
