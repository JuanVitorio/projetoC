#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

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
