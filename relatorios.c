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
    printf("||                  1. Relatorios Filtro              ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      relatorios_filtro();
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

void relatorios_filtro(void)
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                   Relatorios Filtro                ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Ativos                     ||\n");
    printf("||                     2. Inativos                    ||\n");
    printf("||                       0. Sair                      ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      relatorios_filtro_ativos();
      break;
    case 2:
      relatorios_filtro_inativos();
      break;
    case 3:

      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorios_filtro_ativos(void)
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                 Relatorios Filtro Ativos           ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                      3. Servicos                   ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      exibir_clientes();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 2:
      exibir_funcionarios();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 3:
      exibir_servicos();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorios_filtro_inativos(void)
{
  int op;
  do
  {
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||               Relatorios Filtro Inativos           ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                      3. Servicos                   ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 1:
      clientes_inativos();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 2:
      funcionarios_inativos();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 3:
      servicos_inativos();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}
