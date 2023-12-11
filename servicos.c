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

void servicos(void)
{
  int op = -1;

  do
  {
    op = -1;
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
    limpar_buffer();
    switch (op)
    {
    case 0:
      break;
    case 1:
      create_servico();
      getchar();
      break;
    case 2:
      atualizar_cliente();
      break;
    case 3:
      excluir_cliente();
      break;
    case 4:
      exibir_servicos();
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

void create_servico(void)
{
  system("clear||cls");
  Servicos *serv;
  serv = (Servicos *)malloc(sizeof(Servicos));
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar servico           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");

  printf("CPF do cliente\n ");
  ler_cpf(serv->cpf_cliente);

  printf("CPF do funcionario\n ");
  ler_cpf(serv->cpf_funcionario);

  printf("Digite o servico: ");
  fgets(serv->servico, 50, stdin);

  printf("Digite o horario: ");
  fgets(serv->horario, 20, stdin);
  getchar();
  getchar();

  serv->status = 'A';
  serv->id = 1;
  printf("Serviço agendado!");
  getchar();
  getchar();
  gravar_servicos(serv);
  getchar();
}

void ler_cpf_cliente(char *funcionario)
{
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  fflush(stdin);
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
