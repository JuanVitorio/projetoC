#include "clientes.h"
#include "servicos.h"
#include <stdio.h>
#include <stdlib.h>
#include "PyNail.h"
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int op;

void clientes(void)
{
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

void validar_nome(nome)
{
  if (nome == " ")
  {
    return (0);
  }
}

void create_cliente(void)
{
  char nome[100];
  int numero[11];
  char cpf[11];
  char genero;

  printf("==============================================\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("==============================================\n");
  printf("||            * Nome do(a) cliente:         ||\n");
  fgets(nome, sizeof(nome), stdin);
  if (validaNomeCompleto(nome) == 0)
  {
    printf("Nome inválido");
  }
  nome[strcspn(nome, "\n")] = '\0';
  printf("||           * Telefone pra contato:        ||\n");
  scanf("%d", numero);
  printf("||              * Gênero (M | F):           ||\n");
  scanf("%c", &genero);
  printf("==============================================\n");
  scanf("%s");
  printf("|| ... ||\n");

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
  printf("==============================================\n");
  printf("|| Digite o ID do cliente que quer DELETAR: ||\n");
  printf("==============================================\n");

  // listar clientes

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
  printf("================================================\n");
  printf("|| Digite o ID do cliente que quer ATUALIZAR: ||\n");
  printf("================================================\n");
  printf("||          O que deseja atualizar?           ||\n");
  printf("||      Nome(0) - Telefone(1) - Gênero(2)     ||\n");
  printf("================================================\n");

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
