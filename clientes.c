#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "PyNail.h"
#include "validacoes.h"

// Menu principal dos clientes
void clientes(void)
{
  int op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||                      Menu Clientes                 ||\n");
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
  printf("||                                                    ||\n");
  printf("||                Digite o número desejado:           ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");

  scanf("%d", &op);

  if (op == 1)
  {
    create_cliente();
  }
  else if (op == 2)
  {
    update_cliente();
  }
  else if (op == 3)
  {
    delete_cliente();
  }
  else if (op == 4)
  {
    listar_clientes();
  }
  else if (op == 5)
  {
    pesquisar_cliente();
  }
  else
  {
    printf("Digite uma opção válida \n");
    menu_principal();
  }
}

struct clientes_struct
{
  char nome[100];
  char telefone[13];
  char genero[15];
  char data_nasci[50];
  char endereco[100];
  char email[100];
};

// função pra criar clientes
void create_cliente(void)
{

  system("clear||cls");

  char nome[100];
  char telefone[13];
  int genero;
  char data_nasci[50];
  char endereco[100];
  char email[100];

  printf("==============================================\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("==============================================\n");

  // Nome do cliente
  printf("||            * Nome do(a) cliente:         ||\n");
  printf("Nome: ");
  scanf("%s", nome);

  // Tem que mudar a maneira que recebe a data
  printf("||            * Data de nascimento        ||\n");
  printf("Data de nascimento: ");
  scanf("%s", data_nasci);

  // Na hora de por no banco tem que comparar se é 1 ou 2 e adicionar Mas ou Fem
  printf("||              * Gênero (1 - M | 2 - F):           ||\n");
  printf("Gênero: ");
  scanf("%d", &genero);

  printf("||           * Telefone pra contato:        ||\n");
  printf("Telefone: ");
  scanf("%s", telefone);

  // Teste de validação do número
  //  tem que melhorar a validação ainda
  if (validar_numero(telefone) == 0)
  {
    printf("Telefone inválido");
    create_cliente();
  }

  printf("||           * Endereço:        ||\n");
  printf("Endereço: ");
  scanf("%s", endereco);

  // Tem que melhorar a validação do Email
  printf("||           * Email:        ||\n");
  printf("Email: ");
  scanf("%s", email);
  printf("==============================================\n");

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

void listar_clientes(void)
{
  int op;

  printf("==================================================\n");
  printf("||                  Clientes:                   ||\n");
  printf("==================================================\n");
  // for dos clientes

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
