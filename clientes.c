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
    printf("Digite uma opção válida");
    menu_principal();
  }
}

// função pra criar clientes
void create_cliente(void)
{
  char nome[100];
  char telefone[13];
  char genero[15];
  int gen_op;
  char data_nasci[50];
  char endereco[100];
  char email[100];
  int op;

  printf("==============================================\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("==============================================\n");
  printf("||            * Nome do(a) cliente:         ||\n");
  scanf("%s", nome);
  if (valida_nome(nome) == 0)
  {
    printf("Nome inválido");
    create_cliente();
  }
  printf("||            * Data de nascimento        ||\n");
  scanf("%s", data_nasci);

  printf("||              * Gênero (1 - M | 2 - F):           ||\n");
  scanf("%d", &gen_op);
  if (gen_op == 1)
  {
    genero == "Másculino";
  }
  else if (gen_op == 2)
  {
    genero == "Feminino";
  }
  else
  {
    printf("Digite um número válido");
    create_cliente();
  }

  printf("||           * Telefone pra contato:        ||\n");
  scanf("%d", &telefone);

  if (telefone == 0)
  {
    printf("Telefone inválido");
    create_cliente();
  }

  printf("||           * Endereço:        ||\n");
  scanf("%s", endereco);
  printf("||           * Email:        ||\n");
  scanf("%s", email);
  printf("==============================================\n");

  printf("nome: %s\n", nome);
  printf("telefone: %d\n", telefone);
  printf("genero: %s", genero);

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
