#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "PyNail.h"
#include "validacoes.h"

int op;

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

void create_funcionario(void)
{
  char nome[100];
  int dia, mes, ano;
  char genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  double salario;

  printf("==============================================\n");
  printf("||             Cadastrar Funcionário        ||\n");
  printf("==============================================\n");

  // Nome completo
  printf("||           * Nome do(a) funcionário:      ||\n");
  scanf("%s", nome);
  if (valida_nome(nome) == 0)
  {
    printf("Nome inválido");
    create_funcionario();
  }

  // dia, mês e ano de nascimento
  printf("||           * Data de nascimento:      ||\n");
  scanf("%d%*c%d%*c%d", &dia, &mes, &ano);

  // gênero do funcionário
  printf("||              * Gênero (M | F):           ||\n");
  genero = getchar();

  printf("||           * Email:      ||\n");
  scanf("%s", email);
  // -- validador de email --

  // telefone do funcionário
  printf("||           * Telefone pra contato:        ||\n");
  scanf("%s", telefone);
  if (validar_numero(telefone) == 0)
  {
    printf("Telefone inválido");
    create_funcionario();
  }

  // cargo/função que exerce
  printf("||                  * Função:               ||\n");
  scanf("%s", funcao);

  // salário do funcionário (double)
  printf("||                  * Salário:               ||\n");
  scanf("%lf", &salario);
  printf("==============================================\n");

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

  int id;

  printf("==================================================\n");
  printf("|| Digite o ID do funcionário que quer DELETAR: ||\n");
  printf("==================================================\n");

  // listar funcionários

  scanf("%d", &id);

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
