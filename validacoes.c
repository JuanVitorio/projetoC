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

  // Verifica se o tamanho vai ser 11, porque é o padrão de tamanho para números
  if (strlen(telefone) == 11)
  {
    return 0;
  }

  // O terceiro número tem que ser 9
  if (telefone[2] == 9)
  {
    return 0;
  }

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