#include <stdio.h>
#include <stdlib.h>

typedef struct cliente Cliente;

struct cliente
{
  char nome[100];
  char telefone[13];
  char endereco[100];
  char email[100];
  char cpf[12];
  int genero;
  int dia, mes, ano;
};

int add_cliente(char nome[], char telefone[], char endereco[], char email[], char cpf[], int genero, int dia, int mes, int ano)
{
  FILE *fp;

  fp = fopen("db_cliente.dat", "ab");

  if (fp == NULL)
  {
    printf("Erro na criação do arquivo\n");
    return (1);
  }

  fwrite(nome, sizeof(Cliente), 1, fp);

  fclose(fp);

  printf("Dados gravados\n");

  return (0);
}