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
  int op;
  do
  {
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

    switch (op)
    {
    case 0:
      break;
    case 1:
      cli = create_cliente();
      gravar_cliente(cli);
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
    default:
      printf("Digite algo valido");
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

  char nome[100] = "", telefone[15] = "", endereco[100] = "", email[100] = "", cpf[12] = "", data_nasci[10] = "";
  char status, genero;

  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");

  do
  {
    ler_cpf(cli->cpf);
    if (!verifica_existe_cliente(cli->cpf))
    {
      printf("CPF ja cadastrado!\n\n");
      printf("Aperte ENTER para voltar ao menu...\n");
      getchar();
      getchar();
      clientes();
    }
    else
    {
      break;
    }
    // retornar um tela,no caso ao menu
  } while (1);

  printf("\n");
  // NOME OK
  ler_nome(nome);
  strncpy(cli->nome, nome, sizeof(cli->nome));

  // CPF OK
  ler_cpf(cpf);
  strncpy(cli->cpf, cpf, sizeof(cli->cpf));

  printf("Data (dd/mm/aa): ");
  scanf("%s", cli->data_nasci);
  printf("\n");

  // GÊNERO OK
  printf("Genero (1 - M | 2 - F | 3 - O): ");
  int y;
  do
  {
    scanf("%d", &gen_int);
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
      printf("Digie um numero valido!\n");
    }
  } while (y != 1);

  // TELEFONE OK
  ler_telefone(telefone);
  strncpy(cli->telefone, telefone, sizeof(cli->telefone));

  // ENDEREÇO OK
  ler_endereco(endereco);
  strncpy(cli->endereco, endereco, sizeof(cli->endereco));

  // EMAIL OK
  ler_email(email);
  strncpy(cli->email, email, sizeof(cli->email));

  cli->status = 'A';
  printf("\n");
  gravar_cliente(cli);

  printf("\n");
  printf(">>> Cliente cadastrado! <<<\n");

  printf("\nAperte ENTER para continuar...");
  getchar();
  getchar();
  clientes();
}

void listador_clientes(void)
{
  system("clear||cls");
  printf("==================================================\n");
  printf("||                  Clientes:                   ||\n");
  printf("==================================================\n");
  exibir_clientes();
  printf("\nAperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void buscar_clientes(void)
{
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  pesquisar_cliente(cpf);
  printf("\nAperte ENTER para voltar...\n");
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

  // Tem que botar essa pra funcionar que não presta ainda

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
        printf("#############################################\n");
        printf("#                                           #\n");
        printf("#           Informacoees cadastradas        #\n");
        printf("#                                           #\n");
        printf("#############################################\n\n");
        printf("Nome: \n", cls->nome);
        printf("CPF: \n", cls->cpf);
        printf("Genero: \n", cls->genero);
        printf("Email: \n", cls->email);
        printf("Telefone: \n", cls->telefone);
        printf("Endereco: \n", cls->endereco);

        printf("====================================\n");
        printf("||                                ||\n");
        printf("||    O que deseja atualizar?     ||\n");
        printf("||                                ||\n");
        printf("====================================\n\n");
        printf("Nome     - 1\n");
        printf("CPF      - 2\n");
        printf("Genero   - 3\n");
        printf("Email    - 4\n");
        printf("Telefone - 5\n");
        printf("Endereco - 6\n");
        printf("Voltar   - 0\n");

        printf("Opcao: ");
        scanf("%d", &esc);

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
        case 4:
          printf("Email: ");
          scanf("%s", cls->email);
          printf("Email atualizado");
          break;
        case 5:
          printf("Telefone: ");
          scanf("%s", cls->telefone);
          printf("Telefone atualizado");
          break;
        case 6:
          printf("Endereco: ");
          scanf("%s", cls->endereco);
          printf("Endereco atualizado");
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
