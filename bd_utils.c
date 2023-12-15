#include <stdio.h>
#include <stdlib.h>
#include "bd_utils.h"
#include "servicos.h"
#include "relatorios.h"
#include <string.h>

// FUNÇÕES PARA O MODULO DE CLIENTES
void gravar_cliente(Cliente *cli)
{
  FILE *fc;

  fc = fopen("db_cliente.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }

  fwrite(cli, sizeof(Cliente), 1, fc);

  free(cli);
  fclose(fc);
}

void listar_clientes(Cliente *cli)
{
  char estatos[20];
  if ((cli == NULL) || (cli->status == 'I'))
  {
    printf("cliente não cadastrado!\n");
  }
  else
  {
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Nascimento: %s\n", cli->data_nasci);
    printf("Genero: %c\n", cli->genero);
    printf("Email: %s\n", cli->email);
    printf("Telefone: %s\n", cli->telefone);
    printf("Endereco: %s\n", cli->endereco);
    printf("\n");
  }
}

void exibir_clientes(void)
{
  FILE *fc;
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(cli, sizeof(Cliente), 1, fc))
  {
    if (cli->status != 'I')
    {
      listar_clientes(cli);
    }
  }
  fclose(fc);
  free(cli);
}

// FUNÇÕES PARA O MÓDULO DE FUNCIONÁRIOS

void gravar_funcionario(Funcionario *fun)
{
  FILE *fc;

  fc = fopen("db_funcionarios.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }

  fwrite(fun, sizeof(Funcionario), 1, fc);

  free(fun);
  fclose(fc);
}

void listar_funcionarios(Funcionario *fun)
{
  char estatos[20];
  if ((fun == NULL) || (fun->status == 'I'))
  {
    printf("Funcionario não cadastrado!\n");
  }
  else
  {
    printf("\n");
    printf("Nome: %s\n", fun->nome);
    printf("CPF: %s\n", fun->cpf);
    printf("Nascimento: %s\n", fun->data_nasci);
    printf("Genero: %c\n", fun->genero);
    printf("Cargo: %s\n", fun->funcao);
    printf("Salario: R$ %s\n", fun->salario);
    printf("Email: %s\n", fun->email);
    printf("Telefone: %s\n", fun->telefone);
    printf("Endereco: %s\n", fun->endereco);
    printf("\n");
  }
}

void exibir_funcionarios(void)
{
  FILE *fc;
  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(fun, sizeof(Funcionario), 1, fc))
  {
    if (fun->status != 'I')
    {
      listar_funcionarios(fun);
    }
  }
  fclose(fc);
  free(fun);
}

// FUNÇÕES PARA O MÓDULO DE SERVIÇOS

void gravar_servicos(Servicos *serv)
{
  FILE *fc;

  fc = fopen("db_servicos.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }

  fwrite(serv, sizeof(Servicos), 1, fc);

  free(serv);
  fclose(fc);
}

void listar_servicos(Servicos *serv)
{
  char estatos[20];
  if ((serv == NULL) || (serv->status == 'I'))
  {
    printf("Agendamento não cadastrado!\n");
  }
  else
  {
    printf("\n");
    printf("ID: %d\n", serv->id);
    nome_cliente_relacionado(serv->cpf_cliente);
    printf("CPF do cliente: %s\n", serv->cpf_cliente);
    nome_funcionario_responsavel(serv->cpf_funcionario);
    printf("CPF do funcionario:%s\n", serv->cpf_funcionario);
    printf("Servico: %s\n", serv->servico);
    printf("Horario: %s\n", serv->horario);
    printf("Data: %s\n", serv->data);
  }
}

void exibir_servicos(void)
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
    if (serv->status != 'I')
    {
      listar_servicos(serv);
    }
  }
  fclose(fc);
  free(serv);
}

void nome_funcionario_responsavel(char cpf[])
{
  // essa função serve pra mostar o nome do funcionario responsável de acordo com o cpf
  FILE *fc;
  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum funcionario foi cadastrado no sistema!\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    servicos();
  }
  while (fread(fun, sizeof(Funcionario), 1, fc))
  {
    if ((strcmp(fun->cpf, cpf) == 0) && (fun->status != 'I'))
    {
      printf("Nome do funcionario: %s\n", fun->nome);
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum funcionario cadastrado!\n");
  }
  fclose(fc);
  free(fun);
}

void nome_cliente_relacionado(char cpf[])
{
  // essa função serve pra mostar o nome do funcionario responsável de acordo com o cpf
  FILE *fc;
  Cliente *fun;
  fun = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum cliente foi cadastrado no sistema!\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    servicos();
  }
  while (fread(fun, sizeof(Cliente), 1, fc))
  {
    if ((strcmp(fun->cpf, cpf) == 0) && (fun->status != 'I'))
    {
      printf("Nome do cliente: %s\n", fun->nome);
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
  }
  fclose(fc);
  free(fun);
}

void clientes_inativos(void)
{
  FILE *fc;
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(cli, sizeof(Cliente), 1, fc))
  {
    if (cli->status != 'A')
    {
      printf("Nome: %s\n", cli->nome);
      printf("CPF: %s\n", cli->cpf);
      printf("Nascimento: %s\n", cli->data_nasci);
      printf("Genero: %c\n", cli->genero);
      printf("Email: %s\n", cli->email);
      printf("Telefone: %s\n", cli->telefone);
      printf("Endereco: %s\n", cli->endereco);
      printf("Status: %c\n", cli->status);
      printf("\n");
    }
    else
    {
      printf("Nao ha clientes inativos\n.");
    }
  }
  fclose(fc);
  free(cli);
}

void funcionarios_inativos(void)
{
  FILE *fc;
  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criacao do arquivo\n");
    return;
  }
  while (fread(fun, sizeof(Funcionario), 1, fc))
  {
    if (fun->status != 'A')
    {
      printf("\n");
      printf("Nome: %s\n", fun->nome);
      printf("CPF: %s\n", fun->cpf);
      printf("Nascimento: %s\n", fun->data_nasci);
      printf("Genero: %c\n", fun->genero);
      printf("Cargo: %s\n", fun->funcao);
      printf("Salario: %s\n", fun->salario);
      printf("Email: %s\n", fun->email);
      printf("Telefone: %s\n", fun->telefone);
      printf("Endereco: %s\n", fun->endereco);
      printf("Status: %c\n", fun->status);
      printf("\n");
      printf("\n");
    }
    else
    {
      printf("Nao ha funcionarios inativos\n");
    }
  }
  fclose(fc);
  free(fun);
}

void servicos_inativos(void)
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
    if (serv->status != 'A')
    {
      printf("\n");
      printf("ID: %d\n", serv->id);
      nome_cliente_relacionado(serv->cpf_cliente);
      printf("CPF do cliente: %s\n", serv->cpf_cliente);
      nome_funcionario_responsavel(serv->cpf_funcionario);
      printf("CPF do funcionario:%s\n", serv->cpf_funcionario);
      printf("Servico: %s", serv->servico);
      printf("Horario: %s", serv->horario);
      printf("Data: %s\n", serv->data);
      printf("Status: %c\n", serv->status);
      printf("\n");
    }
    else
    {
      printf("Nao ha servicos inativos\n.");
    }
  }
  fclose(fc);
  free(serv);
}
