#include "horarios.h"
#include <stdio.h>
#include <stdlib.h>

void create_horario(void)
{
  int op;
  printf("* Abrimos a partir das 10:00 e fechamos às 19:00 *\n");
  printf("Horários disponíveis: \n");
  // Vou listar todos os horários disponíveis no momento
  // horários das 10 até as 19 que não estão ocupados

  printf("========================================================\n");
  printf("||                  Escolha o horário:                ||\n");
  printf("========================================================\n");

  // se o horários estiver vago:

  printf("========================================================\n");
  printf("||          Pesquise o nome do(a) cliente:            ||\n");
  printf("========================================================\n");

  printf("========================================================\n");
  printf("||               Algumas observação?                  ||\n");
  printf("========================================================\n");

  printf("Agendar? (1 - sim | 2 - não)");
  scanf("%d", &op);
  if (op == 1)
  {
    printf("Agendado");
  }
  else
  {
    printf("Agendamento cancelado");
  }
}

void update_horario(void)
{
  printf("====================================================\n");
  printf("||   Digite o ID do horário que quer ATUALIZAR:   ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("====================================================\n");
}

void delete_horario(void)
{
  printf("====================================================\n");
  printf("||       Digite o horário que quer deletar:       ||\n");
  printf("====================================================\n");
}

void listar_horarios(void)
{
  printf("====================================================\n");
  printf("||                    Horários                    ||\n");
  printf("====================================================\n");
}

void pesquisar_horario(void)
{
  printf("==================================================\n");
  printf("||           Digite o nome do cliente:          ||\n");
  printf("==================================================\n");
}

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