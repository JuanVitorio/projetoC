#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "clientes.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"

// MENU PRINCIPAL DE NAVEGAÇÃO DE CLIENTES
void clientes(void)
{
  int op = -1;
  do
  {
    op = -1;
    Cliente *cli;
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
    limpar_buffer();
    switch (op)
    {
    case 1:
      cli = create_cliente();
      break;
    case 2:
      atualizar_cliente();
      break;
    case 3:
      excluir_cliente();
      break;
    case 4:
      listador_clientes();
      break;
    case 5:
      buscar_clientes();
      break;
    case 0:
      break;
    default:
      printf("Digite algo valido\n");
      break;
    }
  } while (op != 0);
}

// FUNÇÃO PARA CRIAR CLIENTES
Cliente *create_cliente(void)
{
  system("clear||cls");
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));
  int gen_int = 0;
  char cpf[15] = "";
  char status, genero;
  int dia, mes, ano;
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");
  ler_cpf(cli->cpf);
  if (!verifica_existe_cliente(cli->cpf))
  {
    printf("CPF ja cadastrado!\n\n");
    printf("Aperte ENTER para voltar ao menu...\n");
    getchar();
    getchar();
  }
  else
  {
    ler_nome(cli->nome);
    ler_data(cli->data_nasci);
    printf("\nGenero (1 - M | 2 - F | 3 - O): ");
    int y;
    do
    {
      fflush(stdin);
      scanf("%d", &gen_int);
      limpar_buffer();
      if (gen_int == 1)
      {
        cli->genero = 'M';
        printf("Genero: Masculino\n\n");
        y = 1;
      }
      else if (gen_int == 2)
      {
        cli->genero = 'F';
        printf("Genero: Feminino\n\n");
        y = 1;
      }
      else if (gen_int == 3)
      {
        cli->genero = 'O';
        printf("Genero: Outro\n\n");
        y = 1;
      }
      else
      {
        printf("Digite um numero valido!\n");
      }
    } while (y != 1);

    ler_telefone(cli->telefone);
    ler_endereco(cli->endereco);
    ler_email(cli->email);
    cli->status = 'A';
    printf("\n");
    gravar_cliente(cli);
    printf(">>> Cliente cadastrado! <<<");
    printf("\nAperte ENTER para continuar...");
    getchar();
    getchar();
  }
}

void listador_clientes(void)
{
  system("clear||cls");
  printf("      Clientes:     \n\n");
  exibir_clientes();
  printf("Aperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void buscar_clientes(void)
{
  system("clear||cls");
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  pesquisar_cliente(cpf);
  printf("Aperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void pesquisar_cliente(char cpf[])
{
  system("clear||cls");
  FILE *fc;
  Cliente *cls;
  cls = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum cliente foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Cliente), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status != 'I'))
    {
      listar_clientes(cls);
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void excluir_cliente()
{
  char cpf[15];
  printf("Digite o cpf do cliente: ");
  scanf("%s", cpf);
  delete_cliente(cpf);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void delete_cliente(char cpf[])
{
  FILE *fc;
  Cliente *cls;
  cls = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum cliente foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Cliente), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status == 'A'))
    {
      cont++;
      cls->status = 'I';
      fseek(fc, -1 * (long)sizeof(Cliente), SEEK_CUR);
      fwrite(cls, sizeof(Cliente), 1, fc);
      printf("\nCliente excluido!\n");
      break;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void atualizar_cliente(void)
{
  system("clear||cls");
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  update_cliente(cpf);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void update_cliente(char cpf[])
{
  system("clear||cls");
  int gen;
  FILE *fc;
  Cliente *cls;
  int esc = -1;
  cls = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum cliente foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Cliente), 1, fc))
  {
    if ((strcmp(cls->cpf, cpf) == 0) && (cls->status == 'A'))
    {
      cont++;
      do
      {
        system("clear||cls");
        printf("Informacoees cadastradas: \n");

        printf("Nome: %s\n", cls->nome);
        printf("CPF: %s\n", cls->cpf);
        printf("Genero: %c\n", cls->genero);
        printf("Email: %s\n", cls->email);
        printf("Telefone: %s\n", cls->telefone);
        printf("Endereco: %s\n\n", cls->endereco);

        printf("O que deseja atualizar?\n");

        printf("Nome       - 1\n");
        printf("CPF        - 2\n");
        printf("Nascimento - 3\n");
        printf("Genero     - 4\n");
        printf("Email      - 5\n");
        printf("Telefone   - 6\n");
        printf("Endereco   - 7\n");
        printf("Voltar     - 0\n");

        printf("Opcao: ");
        fflush(stdin);
        scanf("%d", &esc);
        limpar_buffer();
        switch (esc)
        {
        case 1:
          ler_nome(cls->nome);
          printf("Nome atualizado\n");
          break;
        case 2:
          ler_cpf(cls->cpf);
          printf("CPF atualizado\n");
          break;
        case 3:
          ler_data(cls->data_nasci);
          printf("Nascimento atualizado\n");
          break;
        case 4:
          printf("\nGenero (1 - M | 2 - F | 3 - O): ");
          scanf("%d", &gen);
          if (gen == 1)
          {
            cls->genero = 'M';
            printf("Genero atualizado\n");
            break;
          }
          else if (gen == 2)
          {
            cls->genero = 'F';
            printf("Genero atualizado\n");
            break;
          }
          else if (gen == 3)
          {
            cls->genero = 'O';
            printf("Genero atualizado\n");
            break;
          }
          else
          {
            printf("Digite um numero valido\n");
            printf("Aperte ENTER para voltar...\n");
            getchar();
          }
        case 5:
          ler_email(cls->email);
          printf("Email atualizado\n");
          break;
        case 6:
          ler_telefone(cls->telefone);
          printf("Telefone atualizado\n");
          break;
        case 7:
          ler_endereco(cls->endereco);
          printf("Endereco atualizado\n");
          break;
        case 0:
          break;
        default:
          break;
        }
        fseek(fc, -1 * (long)sizeof(Cliente), SEEK_CUR);
        fwrite(cls, sizeof(Cliente), 1, fc);
        fclose(fc);
      } while (esc != 0);
    }
  }
  if (!cont)
  {
    printf("Cliente não encontrado\n");
  }
  fclose(fc);
  free(cls);
}
