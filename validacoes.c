#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valida_nome(char nome[])
{

  if (strlen(nome) <= 3)
  {
    return 1;
  }

  return 0;
}

int validar_numero(char telefone[])
{

  if (strlen(telefone) != 11)
  {
    return 1;
  }

  return 0;
}

int valida_email(char email[])
{
  int tam_email;
  tam_email = strlen(email);

  if (tam_email <= 5)
  {
    return 1;
  }

  // for (int i = 0; i < tam_email; i++)
  //{
  // char c = email[i];
  // if (c == '@')
  //{
  //  return 0;
  //}

  return 0;
  //}
}

int valida_cpf(char cpf[])
{
  if (strlen(cpf) == 0)
  {
    return 1;
  }

  return 0;
}
