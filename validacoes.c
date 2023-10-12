#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valida_nome(char nome[])
{

  if (strlen(nome) >= 3)
  {
    return 1;
  }

  return 0;
}

int validar_numero(char telefone[])
{

  if (telefone == " ")
  {
    return 0;
  }

  if (strlen(telefone) >= 11)
  {
    return 1;
  }

  return 0;
}