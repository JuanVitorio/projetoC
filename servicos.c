#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicos.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"
#include "funcionarios.h"
#include "clientes.h"

int op;

void servicos(void)
{
  int op;
  do
  {
    Servicos *serv;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      Menu Servicos                 ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                      1. Cadastrar                  ||\n");
    printf("||                      2. Editar                     ||\n");
    printf("||                      3. Excluir                    ||\n");
    printf("||                      4. Listar                     ||\n");
    printf("||                      5. Pesquisar                  ||\n");
    printf("||                      0. Sair                       ||\n");
    printf("||                                                    ||\n");
    printf("========================================================\n");

    printf("\nOpcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 0:
      break;
    case 1:
      create_servico();
      break;
    case 2:
      atualizar_cliente();
      break;
    case 3:
      excluir_cliente();
      break;
    case 4:
      listador_clientes();
      break;
    case 5:
      buscar_clientes();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

Servicos *create_servico(void)
{

  system("clear||cls");
  Servicos *serv;
  Funcionario *fun;
  serv = (Servicos *)malloc(sizeof(Servicos));

  char funcionario[100], cliente[100], servico[50], horario[20], status;
  int id;

  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar servico           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");

  ler_cpf_cliente(funcionario);
  strncpy(serv->funcionario, funcionario, sizeof(serv->funcionario));

  // bugado

  serv->status = 'A';

  gravar_servicos(serv);
}

void ler_cpf_cliente(char *funcionario)
{
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  limpar_buffer();
  FILE *fc;
  Cliente *cls;
  cls = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");

  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum cliente foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Cliente), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status != 'I'))
    {
      printf("Cliente: %s", cls->nome);
      funcionario = cls->nome;
      getchar();
      getchar();

      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
    getchar();
  }
  fclose(fc);
  free(cls);
}

void delete_servico(void)
{
  printf("==================================================\n");
  printf("|| Digite o ID do funcionário que quer DELETAR: ||\n");
  printf("==================================================\n");

  // listar funcionários

  printf("===============================================\n");
  printf("||             Funcionário deletado          ||\n");
  printf("===============================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}

void update_servico(void)
{
  printf("====================================================\n");
  printf("|| Digite o ID do funcionário que quer ATUALIZAR: ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("||        Nome(0) - Telefone(1) - Gênero(2)       ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}

void pesquisar_servico(void)
{
  printf("==================================================\n");
  printf("||         Digite o nome do funcionário:        ||\n");
  printf("==================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}
