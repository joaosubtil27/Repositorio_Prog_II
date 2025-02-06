
typedef struct
{
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    int votos;
} tCandidato;

/**
 * @brief Cria um candidato com os dados informados.
 * @param nome Nome do candidato.
 * @param partido Partido do candidato.
 * @param cargo Cargo do candidato.
 * @param id Identificador do candidato.
 * @return Candidato criado.
 */
tCandidato CriaCandidato(char *nome, char *partido, char cargo, int id)
{
    tCandidato candidato;
    int i = 0;
    while (nome[i] != '\0')
    {
        candidato.nome[i] = nome[i];
        i++;
    }
    candidato.nome[i] = '\0';
    i = 0;
    while (partido[i] != '\0')
    {
        candidato.partido[i] = partido[i];
        i++;
    }
    candidato.partido[i] = '\0';
    candidato.cargo = cargo;
    candidato.id = id;
    candidato.votos = 0;

    return candidato;
}

/**
 * @brief Lê um candidato.
 * @return Candidato lido.
 */
tCandidato LeCandidato()
{
    tCandidato candidato;
    int i = 0;
    char nome[50];
    char partido[50];
    char cargo;
    int id;
    scanf("%*c");
    while (1)
    {
        scanf("%c", &nome[i]);
        if (nome[i] == ',')
            break;

        i++;
    }
    nome[i] = '\0';
    scanf("%*c");
    i = 0;
    while (1)
    {
        scanf("%c", &partido[i]);
        if (partido[i] == ',')
            break;

        i++;
    }
    partido[i] = '\0';
    scanf("%*c");
    scanf("%c, %d", &cargo, &id);

    candidato = CriaCandidato(nome, partido, cargo, id);

    return candidato;
}

/**
 * @brief Verifica se o identificador do candidato é igual ao informado.
 * @param candidato Candidato a ser verificado.
 * @param id Identificador a ser comparado.
 * @return 1 se o identificador é igual, 0 caso contrário.
 */
int VerificaIdCandidato(tCandidato candidato, int id)
{
    if (candidato.id == id)
        return 1;
    else
        return 0;
}

/**
 * @brief Verifica se dois candidatos são iguais (dica: utilize para verificar se houve empate).
 * @param candidato1 Primeiro candidato a ser comparado.
 * @param candidato2 Segundo candidato a ser comparado.
 * @return 1 se os candidatos são iguais, 0 caso contrário.
 */
int EhMesmoCandidato(tCandidato candidato1, tCandidato candidato2)
{
    if (candidato1.votos == candidato2.votos)
    {
        return 1;
    }
    else
        return 0;
}

/**
 * @brief Obtém o cargo do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Cargo do candidato.
 */
char ObtemCargo(tCandidato candidato)
{
    return candidato.cargo;
}

/**
 * @brief Incrementa 1 voto ao candidato.
 * @param candidato Candidato a ter os votos incrementados.
 * @return Candidato com a quantidade de votos incrementada.
 */
tCandidato IncrementaVotoCandidato(tCandidato candidato)
{
    candidato.votos++;
    return candidato;
}

/**
 * @brief Obtém a quantidade de votos do candidato.
 * @param candidato Candidato a ser verificado.
 * @return Quantidade de votos do candidato.
 */
int ObtemVotos(tCandidato candidato)
{
    return candidato.votos;
}

/**
 * @brief Calcula o percentual de votos do candidato em relação ao total de votos (do mesmo cargo).
 * @param candidato Candidato a ser verificado.
 * @param totalVotos Total de votos da eleição.
 * @return Percentual de votos do candidato.
 */
float CalculaPercentualVotos(tCandidato candidato, int totalVotos)
{
    return (float)100 * candidato.votos / totalVotos;
}
/**
 * @brief Imprime os dados do candidato na tela.
 * @param candidato Candidato a ser impresso.
 * @param percentualVotos Percentual de votos do candidato.
 */
void ImprimeCandidato(tCandidato candidato, float percentualVotos)
{
    int i = 0;
    while (1)
    {
        printf("%c", candidato.nome[i]);
        i++;
        if (candidato.nome[i] == '\0')
            break;
    }
    printf(" (");
    i = 0;
    while (candidato.partido[i] != '\0')
    {
        printf("%c", candidato.partido[i]);
        i++;
    }
    printf("), %d voto(s), %.2f%%\n", candidato.votos, percentualVotos);
}