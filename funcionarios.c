#include "funcionarios.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"

void funcionarios(void)
{

  Funcionario *fun;

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

  switch (op)
  {
  case 1:
    fun = create_funcionario();
    gravar_funcionario(fun);
    break;
  case 2:
    update_funcionario();
    break;
  case 3:
    delete_funcionario();
    break;
  case 4:
    listar_funcionarios();
    break;
  case 5:
    pesquisar_funcionario();

  default:
    printf("Digite algo válido");
    break;
  }
}

Funcionario *create_funcionario(void)
{
  system("clear||cls");

  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));

  char nome[100] = "", email[100] = "", telefone[13] = "", funcao[30] = "";
  int dia, mes, ano;
  int genero;
  float salario;
  char status;

  printf("==============================================\n");
  printf("||             Cadastrar Funcionário        ||\n");
  printf("==============================================\n");

  // Tem que colocar a comparação pra saber se é válido
  printf("||           * Nome do(a) funcionario:      ||\n");
  printf("Nome completo: ");
  scanf("%s", fun->nome);

  printf("\nNome digitado: %s\n", fun->nome);
  // printf("||           * Data de nascimento:      ||\n");
  // printf("(dd/mm/aa)): ");
  // scanf("%d%d%d", &dia, &mes, &ano);

  // printf("Data digitada: %02d/%02d/%04d\n", dia, mes, ano);

  // printf("||              * Gênero (M | F):           ||\n");
  // printf("Gênero: ");
  // scanf("%d", &genero);

  printf("||           * Email:      ||\n");
  printf("Email: ");
  scanf("%s", fun->email);
  printf("\nEmail digitado: %s\n", fun->email);

  printf("||           * Telefone pra contato:        ||\n");
  printf("Telefone: ");
  scanf("%s", fun->telefone);

  printf("\nNumero digitado: %s\n", fun->telefone);

  printf("||                  * Função:               ||\n");
  printf("Cargo exercido: ");
  scanf("%s", fun->funcao);
  printf("\nCargo digitado: %s", fun->funcao);

  // printf("||                  * Salário:               ||\n");
  // printf("Salario detalhado: ");
  // scanf("%f", &salario);

  fun->status = 'A';

  printf("==============================================\n");

  printf("Funcionário cadastrado!\n");
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
