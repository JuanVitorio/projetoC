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
      atualizar_funcionario();
      break;
    case 3:
      excluir_funcionario();
      break;
    case 4:
      listador_funcionarios();
      break;
    case 5:
      buscar_funcionario();
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

  char nome[100] = "", email[100] = "", telefone[13] = "", funcao[30] = "", cpf[12] = "", endereco[100] = "", data_nasci[15] = "", salario[20] = "";
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

  ler_data(data_nasci);
  // scanf("%d/%d/%d", &dia, &mes, &ano);
  // sprintf(data_nasci, "%d/%d/%d", dia, mes, ano);
  // printf(data_nasci);

  strncpy(fun->data_nasci, data_nasci, sizeof(fun->data_nasci));

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

void buscar_funcionario(void)
{
  char cpf[12];
  printf("Digite o CPF do funcionario: ");
  scanf("%s", cpf);
  pesquisar_funcionario(cpf);
  printf("\nAperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void pesquisar_funcionario(char cpf[])
{

  system("clear||cls");

  FILE *fc;
  Funcionario *cls;
  cls = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum funcionario foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Funcionario), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status != 'I'))
    {
      listar_funcionarios(cls);
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum funcionario cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void atualizar_funcionario(void)
{
  char cpf[12];
  printf("Digite o CPF do funcionario: ");
  scanf("%s", cpf);
  update_funcionario(cpf);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void update_funcionario(char cpf[])
{

  system("clear||cls");

  int gen;

  FILE *fc;
  Funcionario *cls;
  int esc = -1;
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
      do
      {
        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#           Informacoees cadastradas        #\n");
        printf("#                                           #\n");
        printf("#############################################\n\n");
        printf("Nome: %s\n", cls->nome);
        printf("CPF: %s\n", cls->cpf);
        printf("Nascimento: %s\n", cls->data_nasci);
        printf("Genero: %c\n", cls->genero);
        printf("Cargo: %s\n", cls->funcao);
        printf("Email: %s\n", cls->email);
        printf("Telefone: %s\n", cls->telefone);
        printf("Endereco: %s\n", cls->endereco);

        printf("====================================\n");
        printf("||                                ||\n");
        printf("||    O que deseja atualizar?     ||\n");
        printf("||                                ||\n");
        printf("====================================\n\n");
        printf("Nome       - 1\n");
        printf("CPF        - 2\n");
        printf("Nascimento - 3\n");
        printf("Genero     - 4\n");
        printf("Cargo      - 5\n");
        printf("Email      - 6\n");
        printf("Telefone   - 7\n");
        printf("Endereco   - 8\n");
        printf("Voltar     - 0\n");

        printf("Opcao: ");
        fflush(stdin);
        scanf("%d", &esc);
        limpar_buffer();
        switch (esc)
        {
        case 1:
          printf("Nome: ");
          scanf("%[^\n]", cls->nome);
          printf("Nome atualizado\n");
          break;
        case 2:
          printf("CPF: ");
          scanf("%s", cls->cpf);
          printf("CPF atualizado\n");
          break;
        case 3:
          printf("Nascimento: ");
          scanf("%s", cls->data_nasci);
          printf("Data atualizada\n");
          break;
        case 4:
          printf("Genero (1 - M | 2 - F): ");
          scanf("%d", gen);
          if (gen == 1)
          {
            cls->genero = 'M';
            printf("Genero atualizado\n");
            break;
          }
          else if (gen == 2)
          {
            cls->genero = 'F';
            printf("Genero atualizado");
            break;
          }
          else if (gen == 3)
          {
            cls->genero = 'O';
            printf("Genero atualizado");
            break;
          }
          else
          {
            printf("Digite um numero valido\n");
            printf("Aperte ENTER para voltar...\n");
            getchar();
          }
        case 5:
          printf("Cargo: ");
          scanf("%s", cls->funcao);
          printf("Cargo atualizado\n");
          break;
        case 6:
          printf("Email: ");
          scanf("%s", cls->email);
          printf("Email atualizado");
          break;
        case 7:
          printf("Telefone: ");
          scanf("%s", cls->telefone);
          printf("Telefone atualizado");
          break;
        case 8:
          printf("Endereco: ");
          scanf("%s", cls->endereco);
          printf("Endereco atualizado");
          break;
        default:
          break;
        }
        fseek(fc, -1 * (long)sizeof(Funcionario), SEEK_CUR);
        fwrite(cls, sizeof(Funcionario), 1, fc);
        fclose(fc);
      } while (esc != 0);
    }
  }
  if (!cont)
  {
    printf("Funcionario não encontrado\n");
  }
  fclose(fc);
  free(cls);
}
