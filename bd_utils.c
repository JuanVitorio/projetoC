#include <stdio.h>
#include <stdlib.h>

typedef struct cliente Cliente;

struct clientes_struct
{
  char nome[100];
  char telefone[13];
  char endereco[100];
  char email[100];
  char cpf[12];
  int genero;
  int dia, mes, ano;
};

// int salva_cliente(Cliente *cl)
//{

// FILE *p_file;

// p_file = fopen("db_clientes.dat", "ab");

//  if (p_file == NULL)
// {
//  printf("Erro na abertura do arquivo");
// return 1;
//}

// fclose(p_file);
// }