#include "funcionarios.h"
#include <stdio.h>
#include <stdlib.h>
#include "PyNail.h"
#include "validacoes.h"

void funcionarios(void)
{

  int op;

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
  else if (op == 0)
  {
    menu_principal();
  }
  else
  {
    printf("Digite uma opção válida\n");
    menu_principal();
  }
}

struct funcionarios_struct
{
  char nome[100];
  int dia, mes, ano;
  char genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  double salario;
};

void create_funcionario(void)
{

  system("clear||cls");

  char nome[100];
  char data_nasci[50];
  int genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  double salario;

  printf("==============================================\n");
  printf("||             Cadastrar Funcionário        ||\n");
  printf("==============================================\n");

  // Tem que colocar a comparação pra saber se é válido
  printf("||           * Nome do(a) funcionário:      ||\n");
  printf("Nome completo: ");
  scanf("%s", nome);

  // Tem que melhorar o recebimento das datas
  printf("||           * Data de nascimento:      ||\n");
  printf("Data de nascimento: ");
  scanf("%s", data_nasci);

  // Tem que colocar a comparação par ir pro BD
  printf("||              * Gênero (M | F):           ||\n");
  printf("Gênero: ");
  scanf("%d", &genero);

  // Melhorar a validação do Email
  printf("||           * Email:      ||\n");
  printf("Email: ");
  scanf("%s", email);

  printf("||           * Telefone pra contato:        ||\n");
  printf("Telefone: ");
  scanf("%s", telefone);
  // Validador
  if (validar_numero(telefone) == 0)
  {
    printf("Telefone inválido\n");
    create_funcionario();
  }

  // cargo/função que exerce
  printf("||                  * Função:               ||\n");
  printf("Cargo exercido: ");
  scanf("%s", funcao);

  // salário do funcionário (double)
  printf("||                  * Salário:               ||\n");
  printf("Salário detalhado: ");
  scanf("%lf", &salario);
  printf("==============================================\n");

  printf("Funcionário cadastrado!");

  menu_principal();
}

void delete_funcionario(void)
{

  system("clear||cls");

  int id;
  int op;

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

  system("clear||cls");

  int op;

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

  system("clear||cls");

  int op;

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

  system("clear||cls");

  int op;

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
