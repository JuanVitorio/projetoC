#include <stdio.h>
#include <stdlib.h>
#include "bd_utils.h"
#include <string.h>

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

void listar_cliente(Cliente *cli)
{
  char estatos[20];
  if ((cli == NULL) || (cli->status == 'I'))
  {
    printf("cliente não cadastrado!\n");
  }
  else
  {
    printf("======================================\n");
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Email: %s\n", cli->email);
    printf("Telefone: %s\n", cli->telefone);
    printf("Endereço: %s\n", cli->endereco);

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
      listar_cliente(cli);
    }
  }
  fclose(fc);
  free(cli);
}
