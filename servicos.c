#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "servicos.h"
#include "PyNail.h"
#include "validacoes.h"
#include "bd_utils.h"
#include "funcionarios.h"
#include "clientes.h"

void servicos(void)
{
  int op = 0;

  do
  {
    op = 0;
    Servicos *serv;
    system("clear||cls");
    printf("========================================================\n");
    printf("||                                                    ||\n");
    printf("||                    Menu Agendamentos               ||\n");
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
    case 0:
      break;
    case 1:
      create_servico();
      getchar();
      break;
    case 2:
      atualizar_servico();
      break;
    case 3:
      excluir_servico();
      break;
    case 4:
      listador_servicos();
      break;
    case 5:
      buscar_servico();
      break;
    default:
      printf("Digite algo valido");
      break;
    }
  } while (op != 0);
}
// FUNÇÃO PRA CRIAR UM AGENDAMENTO
void create_servico(void)
{
  system("clear||cls");
  Servicos *serv;
  serv = (Servicos *)malloc(sizeof(Servicos));
  printf("==============================================\n");
  printf("||                                          ||\n");
  printf("||              Cadastrar servico           ||\n");
  printf("||                                          ||\n");
  printf("==============================================\n");

  printf("* CPF do cliente *\n ");
  ler_cpf(serv->cpf_cliente);
  if (cpf_cliente_valido(serv->cpf_cliente))
  {
    nome_cliente_relacionado(serv->cpf_cliente);
  }
  else
  {
    printf("Nao ha funcinarios com esse cpf.\n\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    servicos();
  }

  printf("* CPF do funcionario *\n ");
  ler_cpf(serv->cpf_funcionario);
  if (cpf_funcionnario_valido(serv->cpf_funcionario))
  {
    nome_funcionario_responsavel(serv->cpf_funcionario);
  }
  else
  {
    printf("Nao ha funcinarios com esse cpf.\n\n");
    printf("Aperte ENTER para voltar...");
    getchar();
    getchar();
    servicos();
  }

  printf("Digite o nome do servico: ");
  fgets(serv->servico, 50, stdin);
  printf("\n");

  ler_data(serv->data);

  printf("Digite o horario (00:00): ");
  fgets(serv->horario, 20, stdin);
  serv->status = 'A';
  serv->id = criar_id_d();
  printf("Servico agendado!\n");
  gravar_servicos(serv);
  printf("Aperte ENTER para voltar...");
  getchar();
}
// ESSA FUNÇÃO SERVE PRA LER O CPF DO CLIENTE E VERIFICAR SE ELE EXISTE NO SISTEMA
void ler_cpf_cliente(char *funcionario)
{
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  fflush(stdin);
  scanf("%s", cpf);
  limpar_buffer();
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
      printf("Cliente: %s", cls->nome);
      funcionario = cls->nome;
      getchar();
      cont++;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum cliente cadastrado!\n");
    getchar();
  }
  fclose(fc);
  free(cls);
}
// ESSA FUNÇÃO SERVE DE ATALHO PRA EXIBIR OS AGENDAMENTOS JÁ REGISTRADOS
void listador_servicos(void)
{
  system("clear||cls");
  printf("==================================================\n");
  printf("||                  Agendamentos:               ||\n");
  printf("==================================================\n");
  exibir_servicos();
  printf("\nAperte ENTER para voltar...\n");
  getchar();
}

void excluir_servico()
{
  int id;
  printf("Digite o ID do agendamento: ");
  scanf("%d", &id);
  delete_servico(id);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void delete_servico(int id)
{
  FILE *fc;
  Servicos *cls;
  cls = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum agendamento foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Servicos), 1, fc))
  {
    if (cls->status == 'A')
    {
      cont++;
      cls->status = 'I';
      fseek(fc, -1 * (long)sizeof(Servicos), SEEK_CUR);
      fwrite(cls, sizeof(Servicos), 1, fc);
      printf("\nAgendamento excluido!\n");
      break;
    }
  }
  if (!cont)
  {
    printf("Esse cpf nao esta relacionado a nenhum agendamento cadastrado!\n");
  }
  fclose(fc);
  free(cls);
}

void pesquisar_servico(char cpf_cliente[])
{
  system("clear||cls");
  FILE *fc;
  Servicos *cls;
  cls = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "rb");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum agendamento foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Servicos), 1, fc))
  {
    if ((strcmp(cls->cpf_cliente, cpf_cliente) == 0) && (cls->status != 'I'))
    {
      listar_servicos(cls);
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

void buscar_servico(void)
{
  system("clear||cls");
  char cpf[12];
  printf("Digite o CPF do cliente: ");
  scanf("%s", cpf);
  pesquisar_servico(cpf);
  printf("Aperte ENTER para voltar...\n");
  getchar();
  getchar();
}

void atualizar_servico(void)
{
  system("clear||cls");
  int id;
  printf("Digite o ID do servico: ");
  scanf("%d", &id);
  update_servico(id);
  printf("Aperte ENTER para voltar...");
  getchar();
  getchar();
}

void update_servico(int id)
{
  system("clear||cls");
  int gen;
  FILE *fc;
  Servicos *cls;
  int esc = -1;
  cls = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "r+b");
  int cont = 0;
  if (fc == NULL)
  {
    printf("Nenhum agendamento foi cadastrado no sistema!\n");
    return;
  }
  while (fread(cls, sizeof(Servicos), 1, fc))
  {
    if (cls->status == 'A')
    {
      cont++;
      do
      {
        printf("Informacoees cadastradas: \n");
        printf("CPF do funcionario: %s\n", cls->cpf_funcionario);
        printf("Data do agendamento: %s\n", cls->data);
        printf("Horario do agendamento: %s\n", cls->horario);
        printf("Servico agendado: %s\n\n", cls->servico);
        printf("O que deseja atualizar?\n");
        printf("CPF do funcionario        - 1\n");
        printf("Data do agendamento       - 2\n");
        printf("Horario do agendamento    - 3\n");
        printf("Servico agendado          - 4\n");
        printf("Opcao: ");
        fflush(stdin);
        scanf("%d", &esc);
        limpar_buffer();
        switch (esc)
        {
        case 1:
          printf("* CPF do cliente *\n ");
          ler_cpf(cls->cpf_cliente);
          printf("CPF atualizado\n ");
          break;
        case 2:
          ler_data(cls->data);
          printf("Data atualizada\n ");
          break;
        case 3:
          printf("Digite o horario (00:00): ");
          fgets(cls->horario, 20, stdin);
          printf("Horario atualizado\n");
          break;
        case 4:
          printf("Digite o nome do servico: ");
          fgets(cls->servico, 50, stdin);
          printf("Servico atualizado\n");
          break;
        default:
          break;
        }
        fseek(fc, -1 * (long)sizeof(Servicos), SEEK_CUR);
        fwrite(cls, sizeof(Servicos), 1, fc);
        fclose(fc);
      } while (esc != 0);
    }
  }
  if (!cont)
  {
    printf("Agendamento não encontrado\n");
  }
  fclose(fc);
  free(cls);
}

// função pra verificar se existe o cpf daquele funcionario e cliente que o usuario digitou

int cpf_funcionnario_valido(char cpf[])
{
  FILE *fa;
  Funcionario *std;
  std = (Funcionario *)malloc(sizeof(Funcionario));
  fa = fopen("db_funcionarios.dat", "rb");
  if (fa == NULL)
  {
    return 1;
  }
  while (fread(std, sizeof(Funcionario), 1, fa))
  {
    if ((std->status != 'I') && (strcmp(std->cpf, cpf) == 0))
    {
      return 1;
    }
  }
  fclose(fa);
  free(std);
  return 0;
}

int cpf_cliente_valido(char cpf[])
{
  FILE *fa;
  Cliente *std;
  std = (Cliente *)malloc(sizeof(Cliente));
  fa = fopen("db_cliente.dat", "rb");
  if (fa == NULL)
  {
    return 1;
  }
  while (fread(std, sizeof(Cliente), 1, fa))
  {
    if ((std->status != 'I') && (strcmp(std->cpf, cpf) == 0))
    {
      return 1;
    }
  }
  fclose(fa);
  free(std);
  return 0;
}

// Função tirada do código de Matheus Diniz

int criar_id_d(void)
{
  // Abrir o arquivo
  FILE *arquivo = fopen("db_servicos.dat", "rb");
  if (arquivo == NULL)
  {
    // caso o arquivo não exista começe com 1
    return 1;
    // Percorre o arquivo inteiro
    fseek(arquivo, 0, SEEK_END);
    // Para verificiar o tamanho do arquivo
    if ((long)ftell(arquivo) == 0)
    {
      // caso o arquivo esteja vázio
      fclose(arquivo);
      return 1;
    }
  }
  else
  {
    // Posicione o ponteiro no início do último registro
    // Ver a última estrutura Adicionada

    // long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
    fseek(arquivo, -((long)sizeof(Servicos)), SEEK_END);
    // Agora você pode ler o último registro usando fread

    Servicos ultstruct;
    fread(&ultstruct, sizeof(Servicos), 1, arquivo);

    // Obtenha o ID do último registro e incremente
    int id = ultstruct.id + 1;

    fclose(arquivo); // Feche o arquivo aqui
    return id;
  }
}