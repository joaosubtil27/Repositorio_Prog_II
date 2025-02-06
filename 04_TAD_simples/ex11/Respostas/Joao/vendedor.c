
typedef struct Vendedor
{
    char nome[50];       /**< Nome do vendedor */
    float valor_vendido; /**< Valor total vendido pelo vendedor */
    float salario;       /**< Salário base do vendedor */
    float prct_comissao; /**< Porcentagem de comissão do vendedor */
} tVendedor;

tVendedor RegistraVendedor(char nome[50], float salario, float prct_comissao)
{
    tVendedor vendedor;
    int i = 0;

    while (nome[i] != '\0')
    {
        vendedor.nome[i] = nome[i];
        i++;
    }
    vendedor.nome[i] = '\0';
    vendedor.salario = salario;
    vendedor.prct_comissao = prct_comissao;
    vendedor.valor_vendido = 0;

    return vendedor;
}

int VerificaNomeVendedor(tVendedor vendedor, char nome[50])
{
    int i = 0;
    int valid = 1;

    while (vendedor.nome[i] != '\0')
    {
        if (vendedor.nome[i] != nome[i])
        {
            valid = 0;
        }

        i++;
    }
    return valid;
}


tVendedor ContabilizaVenda(tVendedor vendedor, float valor)
{
    vendedor.valor_vendido += valor;
    return vendedor;
}


float GetSalario(tVendedor vendedor)
{
    return vendedor.salario;
}


float GetComissao(tVendedor vendedor)
{
    return vendedor.valor_vendido * vendedor.prct_comissao;
}


float GetTotalVendido(tVendedor vendedor)
{
    return vendedor.valor_vendido;
}


float GetTotalRecebido(tVendedor vendedor)
{
    return GetComissao(vendedor) + GetSalario(vendedor);
}

void ImprimeRelatorioVendedor(tVendedor vendedor)
{
    printf("    ");
    int i = 0;
    while (vendedor.nome[i] != '\0')
    {
        printf("%c", vendedor.nome[i]);
        i++;
    }
    printf(" > Total vendido: R$%.2f\n", GetTotalVendido(vendedor));
    printf("        Total recebido: R$%.2f\n", GetTotalRecebido(vendedor));
}
