#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "funcionarios.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"

void funcionarios(void)
{
  int op;
  do
  {
    Funcionario *fun;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                    Menu Funcionarios               ||\n");
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

    printf("Opcao: ");

    scanf("%d", &op);

    switch (op)
    {
    case 0:
      break;
    case 1:
      fun = create_funcionario();
      break;
    case 2:
      update_funcionario();
      break;
    case 3:
      excluir_funcionario();
      break;
    case 4:
      listador_funcionarios();
      break;
    case 5:
      pesquisar_funcionario();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}

Funcionario *create_funcionario(void)
{
  system("clear||cls");
  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));

  char nome[100] = "", email[100] = "", telefone[13] = "", funcao[30] = "", cpf[12] = "", endereco[100] = "", data_nasci[10] = "", salario[20] = "";
  char genero, status;
  int gen_int = 0;

  printf("==================================================\n");
  printf("||                                              ||\n");
  printf("||              Cadastrar funcionario           ||\n");
  printf("||                                              ||\n");
  printf("==================================================\n");

  ler_cpf(fun->cpf);
  if (!verifica_existe_funcionario(fun->cpf))
  {
    printf("CPF ja cadastrado!\n\n");
    printf("Aperte ENTER para voltar ao menu...\n");
    getchar();
  }
  fun->cpf;

  ler_nome(nome);
  strncpy(fun->nome, nome, sizeof(fun->nome));

  printf("Data (dd/mm/aa): ");
  scanf("%s", fun->data_nasci);
  printf("\n");

  printf("Genero (1 - M | 2 - F | 3 - O): ");
  int y;
  do
  {
    scanf("%d", &gen_int);
    if (gen_int == 1)
    {
      fun->genero = 'M';
      printf("Genero: Masculino\n\n");
      y = 1;
    }
    else if (gen_int == 2)
    {
      fun->genero = 'F';
      printf("Genero: Feminino\n\n");
      y = 1;
    }
    else if (gen_int == 3)
    {
      fun->genero = 'O';
      printf("Genero: Outro\n\n");
      y = 1;
    }
    else
    {
      printf("Digite um numero valido!\n");
    }
  } while (y != 1);

  ler_endereco(endereco);
  strncpy(fun->endereco, endereco, sizeof(fun->endereco));

  ler_telefone(telefone);
  strncpy(fun->telefone, telefone, sizeof(fun->telefone));

  ler_email(email);
  strncpy(fun->email, email, sizeof(fun->email));

  ler_cargo(funcao);
  strncpy(fun->funcao, funcao, sizeof(fun->funcao));

  ler_salario(salario);
  strncpy(fun->salario, salario, sizeof(fun->salario));

  fun->status = 'A';
  gravar_funcionario(fun);

  printf("\n\n");
  printf(">>> Funcionario cadastrado! <<<\n");

  printf("\nAperte ENTER para continuar...");
  getchar();
  funcionarios();
}

void excluir_funcionario()
{
  char cpf[15];
  printf("Digite o CPF do funcionario: ");
  scanf("%s", cpf);
  delete_funcionario(cpf);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void delete_funcionario(char cpf[])
{
  FILE *fc;
  Funcionario *cls;
  cls = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum funcionario foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Funcionario), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status == 'A'))
    {
      cont++;
      cls->status = 'I';
      fseek(fc, -1 * (long)sizeof(Funcionario), SEEK_CUR);
      fwrite(cls, sizeof(Funcionario), 1, fc);
      printf("\nFuncionario excluido!\n");
      break;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum funcionario cadastrado!\n");
  }
  fclose(fc);
  free(cls);
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

void listador_funcionarios(void)
{
  system("clear||cls");
  printf("==================================================\n");
  printf("||                Funcionarios:                 ||\n");
  printf("==================================================\n");
  exibir_funcionarios();
  printf("\nAperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void pesquisar_funcionario(void)
{

  system("clear||cls");

  int op;

  printf("==================================================\n");
  printf("||         Digite o nome do funcionario:        ||\n");
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
