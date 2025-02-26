#include "gerenciadorpacotes.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("tad_gen_02\n");
    tGerenciador *g = CriaGerenciador();
    int tipo;
    Type tp;
    tPacote *p;
    int tam, idx;
    int op;
    while (1)
    {
        printf("\nEscolha uma opcao:\n");
        printf("(1) Cadastrar um novo pacote\n");
        printf("(2) Imprimir um pacote específico\n");
        printf("(3) Imprimir todos os pacotes e sair\n");

        scanf("%d\n", &op);

        if (op == 1)
        {
            printf("Digite o tipo (0-char, 1-int) e o numero de elementos do pacote/mensagem:");
            scanf("%d %d", &tipo, &tam);

            if (tipo == 1)
                tp = INT;

            else if (tipo == 0)
                tp = CHAR;
            else
                printf("\nDigite um tipo valido!\n");
            if (tipo == 1 || tipo == 0)
            {
                p = CriaPacote(tp, tam);
                if (p != NULL)
                {
                    LePacote(p);
                    AdicionaPacoteNoGerenciador(g, p);
                }
            }
        }

        else if (op == 2)
        {
            scanf("%d\n", &idx);
            ImprimirPacoteNoIndice(g, idx);
        }

        else if (op == 3)
        {
            ImprimirTodosPacotes(g);
            DestroiGerenciador(g);
            break;
        }
        else
            printf("Escolha uma opcao valida para o menu!\n");
    }
}