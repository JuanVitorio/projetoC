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
  int op = -1;
  do
  {
    op = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      Menu Relatorios               ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                  1. Relatorios Filtro              ||\n");
    printf("||                  2. Relatorios Tabela              ||\n");
    printf("||                 3. Relatorios Ordenados             ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &op);
    limpar_buffer();
    switch (op)
    {
    case 1:
      relatorios_filtro();
      break;
    case 2:
      relatorio_tabela();
      break;
    case 3:
      relatorios_ordenados();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorios_filtro(void)
{
  int op = -1;
  do
  {
    char cpf[15] = "";
    op = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                   Relatorios Filtro                ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Ativos                     ||\n");
    printf("||                     2. Inativos                    ||\n");
    printf("||             3. Servicos atrelados a Funciona.      ||\n");
    printf("||              4. Servicos atrelados a Client.       ||\n");
    printf("||                       0. Sair                      ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);
    limpar_buffer();
    switch (op)
    {
    case 1:
      relatorios_filtro_ativos();
      break;
    case 2:
      relatorios_filtro_inativos();
      break;
    case 3:
      ler_cpf(cpf);
      servicos_atrelado_funcionario(cpf);
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 4:
      ler_cpf(cpf);
      servicos_atrelado_cliente(cpf);
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorios_filtro_ativos(void)
{
  int op = -1;
  do
  {
    op = -1;
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
    limpar_buffer();
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
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorios_filtro_inativos(void)
{
  int op = -1;
  do
  {
    op = -1;
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
    limpar_buffer();
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
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void servicos_atrelado_funcionario(char cpf[])
{
  FILE *fc;
  Servicos *serv;
  serv = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(serv, sizeof(Servicos), 1, fc))
  {
    if (serv->status != 'I' && strcmp(cpf, serv->cpf_funcionario) == 0)
    {
      listar_servicos(serv);
    }
    else
    {
      printf("Nao ha servicos atrelados a esse funcionario\n");
    }
  }
  fclose(fc);
  free(serv);
}

void servicos_atrelado_cliente(char cpf[])
{
  FILE *fc;
  Servicos *serv;
  serv = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(serv, sizeof(Servicos), 1, fc))
  {
    if (serv->status != 'I' && strcmp(cpf, serv->cpf_cliente) == 0)
    {
      listar_servicos(serv);
    }
    else
    {
      printf("Nao ha servicos atrelados a esse cliente\n");
    }
  }
  fclose(fc);
  free(serv);
}

void relatorios_ordenados(void)
{
  int op = -1;
  do
  {
    op = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||               Relatorios Ordenados Alfabe.         ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Clientes                   ||\n");
    printf("||                     2. Funcionarios                ||\n");
    printf("||                        0. Sair                     ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("\nOpcao: ");
    scanf("%d", &op);
    limpar_buffer();
    switch (op)
    {
    case 1:
      list_alf_cliente();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 2:
      list_alf_funcionarios();
      printf("Aperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorio_tabela(void)
{
  int op = -1;
  do
  {
    op = -1;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                   Relatorios de tabelas            ||\n");
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
    limpar_buffer();
    switch (op)
    {
    case 1:
      relatorio_tabela_clientes();
      printf("\nAperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 2:
      relatorio_tabela_funcionarios();
      printf("\nAperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 3:
      relatorio_tabela_servicos();
      printf("\nAperte ENTER para voltar...");
      getchar();
      getchar();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

void relatorio_tabela_clientes(void)
{
  FILE *fa;
  Cliente *std;
  std = (Cliente *)malloc(sizeof(Cliente));
  fa = fopen("db_cliente.dat", "rb");
  if ((fa == NULL) || (std == NULL))
  {
    printf("Nenhum cliente cadastrado!\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    return;
  }
  printf("|%-30s", "Nome:");
  printf("|%-15s", "CPF:");
  printf("|%-10s", "Genero:");
  printf("|%-15s", "Data de nasci.:");
  printf("|%-30s", "Email:");
  printf("|%-30s", "Endereco:");
  printf("|%-15s", "Telefone:");
  printf("|%-5s", "Status:");
  printf("\n");
  while (fread(std, sizeof(Cliente), 1, fa))
  {
    printf("|%-30s|%-15s|%-10c|%-15s|%-30s|%-30s|%-15s|%-5c\n", std->nome, std->cpf, std->genero, std->data_nasci, std->email, std->endereco, std->telefone, std->status);
  }
  fclose(fa);
  free(std);
}

void relatorio_tabela_funcionarios(void)
{
  FILE *fa;
  Funcionario *std;
  std = (Funcionario *)malloc(sizeof(Funcionario));
  fa = fopen("db_funcionarios.dat", "rb");
  if ((fa == NULL) || (std == NULL))
  {
    printf("Nenhum funcionario cadastrado!\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    return;
  }
  printf("|%-30s", "Nome:");
  printf("|%-15s", "CPF:");
  printf("|%-10s", "Genero:");
  printf("|%-15s", "Data de nasci.:");
  printf("|%-30s", "Email:");
  printf("|%-30s", "Endereco:");
  printf("|%-15s", "Telefone:");
  printf("|%-5s", "Status:");
  printf("\n");
  while (fread(std, sizeof(Funcionario), 1, fa))
  {
    printf("|%-30s|%-15s|%-10c|%-15s|%-30s|%-30s|%-15s|%-5c\n", std->nome, std->cpf, std->genero, std->data_nasci, std->email, std->endereco, std->telefone, std->status);
  }
  fclose(fa);
  free(std);
}

void relatorio_tabela_servicos(void)
{
  FILE *fa;
  Servicos *std;
  std = (Servicos *)malloc(sizeof(Servicos));
  fa = fopen("db_servicos.dat", "rb");
  if ((fa == NULL) || (std == NULL))
  {
    printf("Nenhum servico cadastrado!\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    return;
  }
  printf("|%-5s", "ID:");
  printf("|%-15s", "CPF Cliente:");
  printf("|%-15s", "CPF Funcionario:");
  printf("|%-15s", "Data:");
  printf("|%-15s", "Horario:");
  printf("|%-30s", "Servico:");
  printf("|%-5s", "Status:");
  printf("\n");
  while (fread(std, sizeof(Servicos), 1, fa))
  {
    printf("|%-5c|%-15s|%-15s|%-15s|%-15s|%-30s|%-5c\n", std->id, std->cpf_cliente, std->cpf_funcionario, std->data, std->horario, std->servico, std->status);
  }
  fclose(fa);
  free(std);
}

void list_alf_cliente(void)
{
  Cliente *list;
  list = NULL;
  gerar_lista_cliente(&list);
  exibir_lista_cliente(list);
  apagar_lista_cliente(&list);
}

void apagar_lista_cliente(Cliente **list)
{
  Cliente *al;
  while (*list != NULL)
  {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }
}

void exibir_lista_cliente(Cliente *aux)
{
  while (aux != NULL)
  {
    printf("| %-39s - %-36s        -%-11s      |   \n", aux->nome, aux->email, aux->telefone);
    aux = aux->prox;
  }
}

void gerar_lista_cliente(Cliente **list)
{
  FILE *fa;
  Cliente *std;
  apagar_lista_cliente(&(*list));
  *list = NULL;
  fa = fopen("db_cliente.dat", "rb");
  if (fa == NULL)
  {
    printf("Erro na abertura do arquivo... \n");
    return;
  }
  else
  {
    std = (Cliente *)malloc(sizeof(Cliente));
    while (fread(std, sizeof(Cliente), 1, fa))
    {
      if ((*list == NULL) || (strcmp(std->nome, (*list)->nome) < 0))
      {
        std->prox = *list;
        *list = std;
      }
      else
      {
        Cliente *ant = *list;
        Cliente *at = (*list)->prox;
        while ((at != NULL) && (strcmp(at->nome, std->nome) < 0))
        {
          ant = at;
          at = at->prox;
        }
        ant->prox = std;
        std->prox = at;
      }
      std = (Cliente *)malloc(sizeof(Cliente));
    }
    free(std);
    fclose(fa);
  }
}

// sla

void list_alf_funcionarios(void)
{
  Funcionario *list;
  list = NULL;
  gerar_lista_funcionario(&list);
  exibir_lista_funcionario(list);
  apagar_lista_funcionarios(&list);
}

void apagar_lista_funcionarios(Funcionario **list)
{
  Funcionario *al;
  while (*list != NULL)
  {
    al = *list;
    *list = (*list)->prox;
    free(al);
  }
}

void exibir_lista_funcionario(Funcionario *aux)
{
  while (aux != NULL)
  {
    printf("| %-39s - %-36s        -%-11s      |   \n", aux->nome, aux->email, aux->telefone);
    aux = aux->prox;
  }
}

void gerar_lista_funcionario(Funcionario **list)
{
  FILE *fa;
  Funcionario *std;
  apagar_lista_funcionarios(&(*list));
  *list = NULL;
  fa = fopen("db_funcionarios.dat", "rb");
  if (fa == NULL)
  {
    printf("Erro na abertura do arquivo... \n");
    return;
  }
  else
  {
    std = (Funcionario *)malloc(sizeof(Funcionario));
    while (fread(std, sizeof(Funcionario), 1, fa))
    {
      if ((*list == NULL) || (strcmp(std->nome, (*list)->nome) < 0))
      {
        std->prox = *list;
        *list = std;
      }
      else
      {
        Funcionario *ant = *list;
        Funcionario *at = (*list)->prox;
        while ((at != NULL) && (strcmp(at->nome, std->nome) < 0))
        {
          ant = at;
          at = at->prox;
        }
        ant->prox = std;
        std->prox = at;
      }
      std = (Funcionario *)malloc(sizeof(Funcionario));
    }
    free(std);
    fclose(fa);
  }
}