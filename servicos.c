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

// FALTA:
// ATUALIZAR AGENDAMENTO
// PESQUISAR AGENDAMENTO

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
    printf("||                    Menu Agendamentos               ||\n");
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
      break;
    case 3:
      excluir_servico();
      break;
    case 4:
      listador_servicos();
      break;
    case 5:
      buscar_servico();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}
// FUNÇÃO PRA CRIAR UM AGENDAMENTO
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

  printf("* CPF do cliente *\n ");
  ler_cpf(serv->cpf_cliente);

  printf("* CPF do funcionario *\n ");
  ler_cpf(serv->cpf_funcionario);

  printf("Digite o nome do servico: ");
  fgets(serv->servico, 50, stdin);
  printf("\n");

  ler_data(serv->data);

  printf("Digite o horario (00:00): ");
  fgets(serv->horario, 20, stdin);
  getchar();
  serv->status = 'A';
  serv->id = 1;
  printf("Servico agendado!\n");
  gravar_servicos(serv);
  printf("Aperte ENTER para voltar...");
  getchar();
}
// ESSA FUNÇÃO SERVE PRA LER O CPF DO CLIENTE E VERIFICAR SE ELE EXISTE NO SISTEMA
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
// ESSA FUNÇÃO SERVE DE ATALHO PRA EXIBIR OS AGENDAMENTOS JÁ REGISTRADOS
void listador_servicos(void)
{
  system("clear||cls");
  printf("==================================================\n");
  printf("||                  Agendamentos:               ||\n");
  printf("==================================================\n");
  exibir_servicos();
  printf("\nAperte ENTER para voltar...\n");
  getchar();
}

void excluir_servico()
{
  int id;
  printf("Digite o ID do agendamento: ");
  scanf("%d", &id);
  delete_servico(id);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void delete_servico(int id)
{
  FILE *fc;
  Servicos *cls;
  cls = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum agendamento foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Servicos), 1, fc))
  {
    if (cls->status == 'A')
    {
      cont++;
      cls->status = 'I';
      fseek(fc, -1 * (long)sizeof(Servicos), SEEK_CUR);
      fwrite(cls, sizeof(Servicos), 1, fc);
      printf("\nAgendamento excluido!\n");
      break;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum agendamento cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void pesquisar_servico(char cpf_cliente[])
{
  system("clear||cls");
  FILE *fc;
  Servicos *cls;
  cls = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum agendamento foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Servicos), 1, fc))
  {
    if ((strcmp(cls->cpf_cliente, cpf_cliente) == 0) && (cls->status != 'I'))
    {
      listar_servicos(cls);
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void buscar_servico(void)
{
  system("clear||cls");
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  pesquisar_servico(cpf);
  printf("Aperte ENTER para voltar...\n");
  getchar();
  getchar();
}