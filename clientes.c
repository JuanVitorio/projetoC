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

  char nome[100] = "", telefone[13] = "", endereco[100] = "", email[100] = "", cpf[12] = "";
  int genero;
  char status;

  // int dia, mes, ano;
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||            * Nome do(a) cliente:         ||\n");
  printf("Nome: ");
  scanf("%s", cli->nome);

  printf("\nNome digitado: %s\n", cli->nome);
  printf("||            * CPF do(a) cliente:         ||\n");
  printf("CPF do cliente: ");
  scanf("%s", cli->cpf);

  printf("\nCPF digitado: %s\n", cli->cpf);
  //  printf("||            * Data de nascimento        ||\n");
  // scanf("%d", cli->dia);
  // scanf("%d", cli->mes);
  // scanf("%d", cli->ano);
  // printf("Data digitada: %02d/%02d/%04d\n", cli->dia, cli->mes, cli->ano);

  /// printf("CPF inválido\n");

  // printf("||              * Gênero (1 - M | 2 - F):           ||\n");
  // printf("Gênero: ");
  //  scanf("%d", cli->genero);

  // printf("Gênero Masculino\n");

  // printf("Gênero Feminino\n");

  printf("||           * Telefone pra contato:        ||\n");
  printf("Telefone: ");
  scanf("%s", cli->telefone);
  printf("\nTelefone digitado: %s\n", cli->telefone);
  printf("||           * Endereço:        ||\n");
  printf("Endereco: ");
  scanf("%s", cli->endereco);
  printf("\nEndereco digitado: %s\n", cli->endereco);
  printf("||           * Email:        ||\n");
  printf("Email: ");
  scanf("%s", cli->email);
  printf("\nEmail: %s\n", cli->email);

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
  int id;
  int op;

  printf("==============================================\n");
  printf("|| Digite o ID do cliente que quer DELETAR: ||\n");
  printf("==============================================\n");
  scanf("%d", &id);

  printf("===============================================\n");
  printf("||             Cliente deletado              ||\n");
  printf("===============================================\n");

  printf("========= 0 para voltar ========= \n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    clientes();
  }
  else
  {
    clientes();
  }
}

void update_cliente(void)
{
  int op;
  int id;

  printf("================================================\n");
  printf("|| Digite o ID do cliente que quer ATUALIZAR: ||\n");
  printf("================================================\n");
  printf("||          O que deseja atualizar?           ||\n");
  printf("||      Nome(0) - Telefone(1) - Gênero(2)     ||\n");
  printf("================================================\n");
  scanf("%d", &id);

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    clientes();
  }
  else
  {
    clientes();
  }
}

void listador_clientes(void)
{
  int op;

  printf("==================================================\n");
  printf("||                  Clientes:                   ||\n");
  printf("==================================================\n");

  exibir_clientes();

  printf("\n========= 0 para voltar ========= \n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    clientes();
  }
  else
  {
    clientes();
  }
}

void pesquisar_cliente(void)
{
  int op;

  printf("================================================\n");
  printf("||           Digite o nome do cliente:        ||\n");
  printf("================================================\n");

  printf("========= 0 para voltar ========= \n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    clientes();
  }
  else
  {
    clientes();
  }
}
