#include "horarios.h"
#include "PyNail.h"
#include <stdio.h>
#include <stdlib.h>

void horarios()
{
  int op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||                      Menu Horários                 ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      1. Criar                      ||\n");
  printf("||                      2. Editar                     ||\n");
  printf("||                      3. Excluir                    ||\n");
  printf("||                      4. Listar                     ||\n");
  printf("||                      5. Pesquisar                  ||\n");
  printf("||                      0. Sair                       ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                Digite o número desejado:           ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");

  scanf("%d", &op);

  if (op == 1)
  {
    create_horario();
  }
  else if (op == 2)
  {
    update_horario();
  }
  else if (op == 3)
  {
    delete_horario();
  }
  else if (op == 4)
  {
    listar_horarios();
  }
  else if (op == 5)
  {
    pesquisar_horario();
  }
  else
  {
    printf("Digite uma opção válida");
    menu_principal();
  }
}

struct horarios
{
  int dia, mes;
  int hora, minuto;
  char cliente[100];
  char funcionario[100];
  char servico[50]; // menicure, pedicure, ambos
  char status;      // marcado, realizado, cancelado
  char observacoes[200];
};

// pra fazer o create de horário eu preciso ter o excluir e buscar de cliente e funcionário

void create_horario(void)
{

  system("clear||cls");

  int op;
  char cpf[12];
  printf("*\nAbrimos a partir das 10:00 e fechamos às 19:00 *\n");
  // Vou listar todos os horários disponíveis no momento
  // horários das 10 até as 19 que não estão ocupados

  printf("========================================================\n");
  printf("||                    Escolha a data:                 ||\n");
  printf("========================================================\n");

  printf("\nDia: ");
  printf("\nMes: ");

  printf("========================================================\n");
  printf("||                  Escolha o horário:                ||\n");
  printf("========================================================\n");

  // aqui vai ter a função que vai listar os horários disponíveis

  printf("\nHorário: ");
  scanf("%d", &op);

  printf("========================================================\n");
  printf("||             Digite o CPF do(a) cliente:            ||\n");
  printf("========================================================\n");

  printf("\nCPF: ");
  scanf("%s", cpf);
  // aqui vai ter a função que pesquisa nos cpfs cadastrados

  printf("========================================================\n");
  printf("||            Digite o CPF do funcionário:            ||\n");
  printf("========================================================\n");

  printf("\nCPF: ");
  scanf("%s", cpf);
  // aqui vai ter a função que pesquisa nos cpfs cadastrados

  printf("========================================================\n");
  printf("||               Algumas observação?                  ||\n");
  printf("========================================================\n");

  printf("\nHorario agendado!n\n");
  printf("\nPressione ENTER para continuar...\n");
  getchar();
  getchar();

  horarios();
}

void update_horario(void)
{
  int op;
  printf("====================================================\n");
  printf("||   Digite o ID do horário que quer ATUALIZAR:   ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    horarios();
  }
  else
  {
    horarios();
  }
}

void delete_horario(void)
{
  int op;
  printf("====================================================\n");
  printf("||       Digite o horário que quer deletar:       ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    horarios();
  }
  else
  {
    horarios();
  }
}

void listar_horarios(void)
{
  int op;
  printf("====================================================\n");
  printf("||                    Horários                    ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    horarios();
  }
  else
  {
    horarios();
  }
}

void pesquisar_horario(void)
{
  int op;
  printf("==================================================\n");
  printf("||           Digite o nome do cliente:          ||\n");
  printf("==================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    horarios();
  }
  else
  {
    horarios();
  }
}
