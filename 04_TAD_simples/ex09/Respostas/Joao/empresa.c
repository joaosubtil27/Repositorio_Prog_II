
#include "funcionario.h"
#include <stdio.h>


typedef struct empresa
{
    int id;
    tFuncionario funcionarios[20];
    int qtdFuncionarios;
} tEmpresa;

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario);

/**
 * @brief Cria uma empresa a partir de um id.
 *
 * @param id Id do empresa a ser criada.
 * @return TEmpresa empresa criada a partir do Id fornecido.
 */
tEmpresa criaEmpresa(int id)
{
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

/**
 * @brief Le os dados de uma empresa da entrada padrao.
 *
 * @return TEmpresa empresa criada a partir dos dados lidos.
 */
tEmpresa leEmpresa()
{
    int id_emp;
    int qnt_func;
    int valid;

    tEmpresa empresa;
    tFuncionario funcionario;
    scanf("\n\n%d %d\n", &id_emp, &qnt_func);
    empresa = criaEmpresa(id_emp);

    for (int i = 0; i < qnt_func; i++)
    {
        valid = 1;
        funcionario = leFuncionario();

        for (int j = 0; j < empresa.qtdFuncionarios; j++)
        {
            if (getIdFuncionario(funcionario) == getIdFuncionario(empresa.funcionarios[j]))
            {
                valid = 0;
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, funcionario.id);
                break;
            }
        }
        if (valid == 1)
        {
            empresa = contrataFuncionarioEmpresa(empresa, funcionario);
        }
    }
    return empresa;
}

/**
 * @brief Adiciona um funcionario a uma empresa caso o id do funcionario ainda nao esteja registrado na empresa.
 *
 * @param empresa Empresa em que o funcionario deve ser adicionado.
 * @param funcionario Funcionario que deve ser adicionado a empresa.
 * @return TEmpresa empresa atualizada com a nova lista de funcionarios.
 */
tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    empresa.funcionarios[empresa.qtdFuncionarios] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

/**
 * @brief Imprime todos os dados de um empresa.
 *
 * @param empresa Empresa a ser impressa no terminal.
 */
void imprimeEmpresa(tEmpresa empresa)
{

    printf("Empresa %d:\n", empresa.id);
    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
}
