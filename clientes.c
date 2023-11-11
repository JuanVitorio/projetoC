#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clientes.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"

// Menu principal dos clientes
void clientes(void)
{
  Cliente *cli;
  int op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      Menu Clientes                 ||\n");
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
    menu_principal();
    break;
  case 1:
    cli = create_cliente();
    gravar_cliente(cli);
    break;
  case 2:
    update_cliente();
    break;
  case 3:
    delete_cliente();
    break;
  case 4:
    listador_clientes();
    break;
  case 5:
    pesquisar_cliente();

  default:
    printf("Digite algo válido");
    break;
  }
}

// função pra criar clientes
Cliente *create_cliente(void)
{
  system("clear||cls");
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));

  int gen_int = 0;

  char nome[100] = "", telefone[13] = "", endereco[100] = "", email[100] = "", cpf[12] = "";
  char status, genero;
  int dia = 0, mes = 0, ano = 0;

  // int dia, mes, ano;
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||            * Nome do(a) cliente:         ||\n");
  printf("Nome: ");
  scanf(" %99[^\n]", cli->nome);
  printf("Nome digitado: %s\n\n", cli->nome);
  printf("||            * CPF do(a) cliente:         ||\n");
  printf("CPF do cliente: ");
  scanf("%s", cli->cpf);

  printf("CPF digitado: %s\n\n", cli->cpf);

  // printf("||            * Data de nascimento        ||\n");
  // scanf(" %d%d%d", cli->dia, cli->mes, cli->ano);
  // printf("Data digitada: %02s/%02s/%04s\n\n", cli->dia, cli->mes, cli->ano);

  printf("||              * Genero (1 - M | 2 - F | 3 - O):           ||\n");
  printf("Genero: ");
  scanf("%d", &gen_int);
  if (gen_int == 1)
  {
    cli->genero = 'M';
    printf("Genero: Masculino\n\n");
  }
  else if (gen_int == 2)
  {
    cli->genero = 'F';
    printf("Genero: Feminino\n\n");
  }
  else if (gen_int == 3)
  {
    cli->genero = 'O';
    printf("Genero: Outro\n\n");
  }
  else
  {
    printf("Digite algo valido.");
    printf("Aperte ENTER para sair...");
    getchar();
    getchar();
    clientes();
  }

  printf("||           * Telefone pra contato:        ||\n");
  printf("Telefone: ");
  scanf("%s", cli->telefone);
  printf("Telefone digitado: %s\n\n", cli->telefone);
  printf("||           * Endereco:        ||\n");
  printf("Endereco: ");
  scanf(" %99[^\n]", cli->endereco);
  printf("Endereco digitado: %s\n\n", cli->endereco);
  printf("||           * Email:        ||\n");
  printf("Email: ");
  scanf(" %99[^\n]", cli->email);
  printf("Email: %s\n\n", cli->email);

  cli->status = 'A';
  printf("\n");
  gravar_cliente(cli);
  printf("==================================\n");
  printf("||                              ||\n");
  printf("||      Cliente cadastrado      ||\n");
  printf("||                              ||\n");
  printf("==================================\n");
  printf("\nAperte ENTER para continuar...");
  getchar();
  getchar();

  menu_principal();
}

void delete_cliente(void)
{
}

void update_cliente(void)
{
}

void listador_clientes(void)
{
  printf("==================================================\n");
  printf("||                  Clientes:                   ||\n");
  printf("==================================================\n");
  exibir_clientes();
  printf("\nAperte ENTER para voltar...\n");
  getchar();
  getchar();
  clientes();
}

void pesquisar_cliente(void)
{
}
