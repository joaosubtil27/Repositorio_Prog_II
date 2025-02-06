
typedef struct Aluno
{
    char nome[50];  /**< Nome do aluno */
    int matricula;  /**< Matrícula do aluno */
    int n1, n2, n3; /**< Notas das avaliações */
} tAluno;

/**
 * @brief Cria um novo aluno com os dados informados.
 *
 * @param nome Nome do aluno.
 * @param matricula Matrícula do aluno.
 * @param n1 Nota da primeira avaliação.
 * @param n2 Nota da segunda avaliação.
 * @param n3 Nota da terceira avaliação.
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno criado.
 */
tAluno CriaAluno(char *nome, int matricula, int n1, int n2, int n3)
{
    int i = 0;
    tAluno aluno;
    while (nome[i] != '\0')
    {
        aluno.nome[i] = nome[i];
        i++;
    }
    aluno.nome[i]='\0';
    aluno.matricula = matricula;
    aluno.n1 = n1;
    aluno.n2 = n2;
    aluno.n3 = n3;

    return aluno;
}

/**
 * @brief Lê os dados de um aluno.
 *
 * @return tAluno Retorna uma estrutura tAluno com os dados do aluno lido.
 */
tAluno LeAluno()
{
    tAluno aluno;
    int i = 0;
    char nome[50];
    int matricula;
    int n1, n2, n3;

    while (1)
    {
        scanf("%c", &nome[i]);
        if (nome[i] == '\n')
        {
            nome[i] = '\0';
            break;
        }
        i++;
    }
    scanf("%d", &matricula);
    scanf("\n%d %d %d\n", &n1, &n2, &n3);
    aluno = CriaAluno(nome, matricula, n1, n2, n3);
    return aluno;
}

/**
 * @brief Compara as matrículas de dois alunos.
 *
 * @param aluno1 Primeiro aluno a ser comparado.
 * @param aluno2 Segundo aluno a ser comparado.
 * @return int Retorna 1 se a matrícula do aluno1 é maior que a do aluno2, -1 se a matrícula do aluno1 é menor que a do aluno2 e 0 se as matrículas são iguais.
 */
int ComparaMatricula(tAluno aluno1, tAluno aluno2)
{
    if (aluno1.matricula > aluno2.matricula)
        return 1;
    else if (aluno1.matricula == aluno2.matricula)
        return 0;
    else if (aluno1.matricula < aluno2.matricula)
        return -1;
}

/**
 * @brief Calcula a média das notas de um aluno.
 *
 * @param aluno Aluno a ter a média calculada.
 * @return int Retorna a média das notas do aluno.
 */
int CalculaMediaAluno(tAluno aluno)
{
    return (aluno.n1 + aluno.n2 + aluno.n3) / 3;
}

/**
 * @brief Verifica se um aluno foi aprovado ou reprovado.
 *
 * @param aluno Aluno a ser verificado.
 * @return int Retorna 1 se o aluno foi aprovado e 0 se foi reprovado.
 */
int VerificaAprovacao(tAluno aluno)
{
    if (CalculaMediaAluno(aluno) >= 7)
        return 1;

    else if (CalculaMediaAluno(aluno) < 7)
        return 0;
}

/**
 * @brief Imprime os dados de um aluno.
 *
 * @param aluno Aluno a ser impresso.
 */
void ImprimeAluno(tAluno aluno)
{
    int i = 0;
    while (aluno.nome[i] != '\0')
    {
        printf("%c", aluno.nome[i]);
        i++;
    }
    printf("\n");
}
