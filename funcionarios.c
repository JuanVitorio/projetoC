#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "PyNail.h"

int op;

void create_funcionario(void)
{
  printf("==============================================\n");
  printf("||             Cadastrar Funcionário        ||\n");
  printf("==============================================\n");
  printf("||           * Nome do(a) funcionário:      ||\n");
  printf("||           * Telefone pra contato:        ||\n");
  printf("||              * Gênero (M | F):           ||\n");
  printf("||                  * Função:               ||\n");
  printf("==============================================\n");
  printf("|| ... ||\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    funcionarios();
  }
  else
  {
    funcionarios();
  }
}

void delete_funcionario(void)
{
  printf("==================================================\n");
  printf("|| Digite o ID do funcionário que quer DELETAR: ||\n");
  printf("==================================================\n");

  // listar funcionários

  printf("===============================================\n");
  printf("||             Funcionário deletado          ||\n");
  printf("===============================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    funcionarios();
  }
  else
  {
    funcionarios();
  }
}

void update_funcionario(void)
{
  printf("====================================================\n");
  printf("|| Digite o ID do funcionário que quer ATUALIZAR: ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("||        Nome(0) - Telefone(1) - Gênero(2)       ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    funcionarios();
  }
  else
  {
    funcionarios();
  }
}

void listar_funcionarios(void)
{
  printf("==================================================\n");
  printf("||                  Funcionários:               ||\n");
  printf("==================================================\n");
  // for dos funcionários

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    funcionarios();
  }
  else
  {
    funcionarios();
  }
}

void pesquisar_funcionario(void)
{
  printf("==================================================\n");
  printf("||         Digite o nome do funcionário:        ||\n");
  printf("==================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    funcionarios();
  }
  else
  {
    funcionarios();
  }
}

void funcionarios(void)
{
  system("clear||cls");
  printf("========================================================\n");
  printf("||                    Menu Funcionários               ||\n");
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
    create_funcionario();
  }
  else if (op == 2)
  {
    update_funcionario();
  }
  else if (op == 3)
  {
    delete_funcionario();
  }
  else if (op == 4)
  {
    listar_funcionarios();
  }
  else if (op == 5)
  {
    pesquisar_funcionario();
  }
  else
  {
    printf("Digite uma opção válida");
    menu_principal();
  }
}
