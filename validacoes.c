#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int valida_nome(char nome[])
{
  int i = 0;

  if (strlen(nome) < 3)
  {
    return 0;
  }

  // while (nome[i] != '\0')
  //{

  //}

  return 1;
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
