#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "relatorios.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"

void relatorios()
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      Menu Relatorios               ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                  1. Relatorios Tabela              ||\n");
    printf("||                  2. Relatorios Filtro              ||\n");
    printf("||                  3. Relatorios Ordenados           ||\n");
    printf("||                  0. Sair                           ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 0:
      break;
    case 1:

      break;
    case 2:

      break;
    case 3:

      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorio_filtro(void)
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                     Relatorio Filtro               ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                  1. Relatorio de Ativos            ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      relatorio_ativos();
      break;

    default:
      break;
    }

  } while (op != 0)
}

void relatorio_ativos()
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                     Relatorio Filtro               ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                  1. Clientes ativos                ||\n");
    printf("||                  2. Funcionarios ativos            ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      exibir_clientes();
      break;

    default:
      break;
    }

  } while (op != 0);
}