#include <stdio.h>
#include <stdlib.h>
#include "bd_utils.h"
#include <string.h>

// FUNÇÕES PARA O MODULO DE CLIENTES
void gravar_cliente(Cliente *cli)
{
  FILE *fc;

  fc = fopen("db_cliente.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }

  fwrite(cli, sizeof(Cliente), 1, fc);

  fclose(fc);
  free(cli);
}

void gravar_servicos(Servicos *serv)
{
  FILE *fc;

  fc = fopen("db_servicos.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }

  fwrite(serv, sizeof(Servicos), 1, fc);

  fclose(fc);
  free(serv);
}

void listar_servicos(Servicos *serv)
{
  char estatos[20];
  if ((serv == NULL) || (serv->status == 'I'))
  {
    printf("servente não cadastrado!\n");
  }
  else
  {
    printf("\n");
    printf("Nome: %s\n", serv->funcionario);

    printf("\n");

    if (serv->status == 'A')
    {
      strcpy(estatos, "Ativo");
    }
    else if (serv->status == 'I')
    {
      strcpy(estatos, "Inativo");
    }
  }
}

void exibir_servicos(void)
{
  FILE *fc;
  Servicos *serv;
  serv = (Servicos *)malloc(sizeof(Servicos));
  fc = fopen("db_servicos.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }
  while (fread(serv, sizeof(Servicos), 1, fc))
  {
    if (serv->status != 'I')
    {
      listar_servicos(serv);
    }
  }
  fclose(fc);
  free(serv);
}

void listar_clientes(Cliente *cli)
{
  char estatos[20];
  if ((cli == NULL) || (cli->status == 'I'))
  {
    printf("cliente não cadastrado!\n");
  }
  else
  {
    printf("\n");
    printf("Nome: %s\n", cli->nome);
    printf("CPF: %s\n", cli->cpf);
    printf("Nascimento: %s\n", cli->data_nasci);
    printf("Genero: %c\n", cli->genero);
    printf("Email: %s\n", cli->email);
    printf("Telefone: %s\n", cli->telefone);
    printf("Endereco: %s\n", cli->endereco);
    printf("\n");

    if (cli->status == 'A')
    {
      strcpy(estatos, "Ativo");
    }
    else if (cli->status == 'I')
    {
      strcpy(estatos, "Inativo");
    }
  }
}

void exibir_clientes(void)
{
  FILE *fc;
  Cliente *cli;
  cli = (Cliente *)malloc(sizeof(Cliente));
  fc = fopen("db_cliente.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }
  while (fread(cli, sizeof(Cliente), 1, fc))
  {
    if (cli->status != 'I')
    {
      listar_clientes(cli);
    }
  }
  fclose(fc);
  free(cli);
}

// FUNÇÕES PARA O MÓDULO DE FUNCIONÁRIOS

void gravar_funcionario(Funcionario *fun)
{
  FILE *fc;

  fc = fopen("db_funcionarios.dat", "ab");

  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }

  fwrite(fun, sizeof(Funcionario), 1, fc);

  fclose(fc);
  free(fun);
}

void listar_funcionarios(Funcionario *fun)
{
  char estatos[20];
  if ((fun == NULL) || (fun->status == 'I'))
  {
    printf("Funcionario não cadastrado!\n");
  }
  else
  {
    printf("\n");
    printf("Nome: %s\n", fun->nome);
    printf("CPF: %s\n", fun->cpf);
    printf("Nascimento: %s\n", fun->data_nasci);
    printf("Genero: %c\n", fun->genero);
    printf("Cargo: %s\n", fun->funcao);
    printf("Salario: %s\n", fun->salario);
    printf("Email: %s\n", fun->email);
    printf("Telefone: %s\n", fun->telefone);
    printf("Endereco: %s\n", fun->endereco);
    printf("\n");

    if (fun->status == 'A')
    {
      strcpy(estatos, "Ativo");
    }
    else if (fun->status == 'I')
    {
      strcpy(estatos, "Inativo");
    }
  }
}

void exibir_funcionarios(void)
{
  FILE *fc;
  Funcionario *fun;
  fun = (Funcionario *)malloc(sizeof(Funcionario));
  fc = fopen("db_funcionarios.dat", "rb");
  if (fc == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return;
  }
  while (fread(fun, sizeof(Funcionario), 1, fc))
  {
    if (fun->status != 'I')
    {
      listar_funcionarios(fun);
    }
  }
  fclose(fc);
  free(fun);
}

// void removerCaracteresNaoNumericos(char cpf[]) {
//     //feita pelo chat gpt
//     int len = strlen(cpf);
//     int k = 0;
//     for (int i = 0; i < len; i++) {
//         if (cpf[i] >= '0' && cpf[i] <= '9') {
//             cpf[k] = cpf[i];
//             k++;
//         }
//     }
//     cpf[k] = '\0'; // Adicione o terminador nulo ao final
// }

// int validarCPF(char cpf[])
//{
//  validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
//  Remova os caracteres de pontuação (.) e hífen (-) do CPF
// removerCaracteresNaoNumericos(cpf);

// int i, j, digito1 = 0, digito2 = 0;

// if (strlen(cpf) != 11)
// return 0;
// else if (
//  (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
//       (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
//       (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
//       (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
//     return 0;
//   else
//   {
//     // Digito 1
//     for (i = 0, j = 10; i < 9; i++, j--)
//     {
//       digito1 += (cpf[i] - '0') * j;
//     }
//     digito1 %= 11;
//     if (digito1 < 2)
//       digito1 = 0;
//     else
//       digito1 = 11 - digito1;
//     if ((cpf[9] - '0') != digito1)
//       return 0;

//     // Digito 2
//     for (i = 0, j = 11; i < 10; i++, j--)
//     {
//       digito2 += (cpf[i] - '0') * j;
//     }
//     digito2 %= 11;
//     if (digito2 < 2)
//       digito2 = 0;
//     else
//       digito2 = 11 - digito2;
//     if ((cpf[10] - '0') != digito2)
//       return 0;
//   }

//   return 1;
// }

// // //função para a leitura e validação do cpf
// void ler_cpf(char cpf[])
// {
//   // função reutilizável para realizar a leitura do cpf
//   int c;
//   do
//   {
//     printf("Digite o CPF: ");
//     scanf("%s", cpf);
//     // função utilizada para limpar o buffer
//     limpar_buffer();
//     c = validarCPF(cpf);
//     if (c == 0)
//     {
//       printf("CPF inválido!\n");
//     }
//   } while (c != 1);
// }

// //feito com a ajuda do chat gpt
// void limpar_buffer() {
//     int c;
//     while ((c = getchar()) != '\n' && c != EOF) {
//         // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
//     }
// }