#include <stdio.h>
#include <stdlib.h>
#include "bd_utils.h"
#include <string.h>

// FUNÇÕES PARA O MODULO DE CLIENTES
void gravar_cliente(Cliente *cli)
{
  FILE *fc;

  fc = fopen("db_cliente.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }

  fwrite(cli, sizeof(Cliente), 1, fc);

  fclose(fc);
  free(cli);
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
    printf("\n");
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Genero: %c\n", cli->genero);
    printf("Email: %s\n", cli->email);
    printf("Telefone: %s\n", cli->telefone);
    printf("Endereco: %s\n", cli->endereco);
    printf("\n");

    if (cli->status == 'A')
    {
      strcpy(estatos, "Ativo");
    }
    else if (cli->status == 'I')
    {
      strcpy(estatos, "Inativo");
    }
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
    printf("Erro na criação do arquivo\n");
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
    printf("Erro na criação do arquivo\n");
    return;
  }

  fwrite(fun, sizeof(Funcionario), 1, fc);

  fclose(fc);
  free(fun);
}

void listar_funcionarios(Funcionario *fun)
{
  char estatos[20];
  if ((fun == NULL) || (fun->status == 'I'))
  {
    printf("Funcionário não cadastrado!\n");
  }
  else
  {
    printf("\n======================================\n");
    printf("\n");
    printf("Nome: %s\n", fun->nome);
    printf("CPF: %s\n", fun->cpf);
    // printf("Genero: %s", fun->genero);
    printf("Email: %s\n", fun->email);
    printf("Telefone: %s\n", fun->telefone);
    printf("Endereço: %s\n", fun->endereco);
    printf("\n");

    if (fun->status == 'A')
    {
      strcpy(estatos, "Ativo");
    }
    else if (fun->status == 'I')
    {
      strcpy(estatos, "Inativo");
    }
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
    printf("Erro na criação do arquivo\n");
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
