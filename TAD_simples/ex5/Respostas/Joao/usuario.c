/**
 * @struct tUsuario
 * @brief Estrutura que representa um usuário do sistema bancário.
 */
typedef struct Usuario
{
    char nome[50]; /**< Nome do usuário. */
    char cpf[15];  /**< CPF do usuário. */
} tUsuario;

/**
 * @brief Cria um novo usuário.
 * @param nome Nome do usuário.
 * @param cpf CPF do usuário.
 * @return O novo usuário criado.
 */
tUsuario CriaUsuario(char nome[20], char cpf[15])
{
    tUsuario user;
    int i = 0;
    while (1)
    {
        user.nome[i] = nome[i];
        i++;
        if (nome[i] == '\0')
            break;
    }
    user.nome[i] = '\0';
    i = 0;
    while (1)
    {
        user.cpf[i] = cpf[i];
        i++;

        if (cpf[i] == '\0')
            break;
    }
    user.cpf[i] = '\0';
    return user;
}

/**
 * @brief Imprime os dados de um usuário.
 * @param user Usuário a ser impresso.
 */
void ImprimeUsuario(tUsuario user)
{
    int i = 0;
    printf("Nome: ");

    while (1)
    {
        printf("%c", user.nome[i]);
        i++;
        if (user.nome[i] == '\0')
            break;
    }
    printf("\nCPF: ");
    i = 0;
    while (1)
    {
        printf("%c", user.cpf[i]);
        i++;
        if (user.cpf[i] == '\0')
            break;
    }
    printf("\n");
}
