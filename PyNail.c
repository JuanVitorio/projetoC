///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte                 ///
///                 Centro de Ensino Superior do Seridó                     ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///          Projeto Sistema de Gestão de manicure e pedicure               ///
///         Desenvolvido por @juanvitorio_ -- desde Ago, 2023.             ///
///////////////////////////////////////////////////////////////////////////////
///                                Semana 1                                 ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include "funcionarios.h"
#include "horarios.h"
#include "PyNail.h"
#include "servicos.h"

// Módulos previstos:
//- Clientes
//- Funcionários
//- Horários
//- Avaliações
//- Agendamento
//- Pesquisar
int op;

int main(void)
{
  menu_principal();

  return 0;
}

void menu_principal(void)
{
  system("clear||cls");
  printf("========================================================\n");
  printf("||               Manicure/Pedicure Pretty Nail        ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      1. Clientes                   ||\n");
  printf("||                      2. Funcionários               ||\n");
  printf("||                      3. Horários                   ||\n");
  printf("||                      4. Agendamento                ||\n");
  printf("||                      5. Serviços                   ||\n");
  printf("||                      6. Informações                ||\n");
  printf("||                      7. Infos. Dev.                ||\n");
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
    clientes();
  }
  else if (op == 2)
  {
    funcionarios();
  }
  else if (op == 3)
  {
    horarios();
  }
  else if (op == 5)
  {
    servicos();
  }
  else if (op == 6)
  {
    informacoes();
  }
  else if (op == 7)
  {
    infos_dev();
  }
  else if (op == 0)
  {
    printf("Código encerrado.");
  }
  else
  {
    printf("opção em desenvolvimento");
  }
}

void informacoes(void)
{
  printf("========================================================\n");
  printf("||                    Informações gerais              ||\n");
  printf("========================================================\n");
  printf("||                      UFRN | Caicó                  ||\n");
  printf("||           Disciplina DCT1106 -- Programação        ||\n");
  printf("||    Sistema de gestão para uma manicure e pedicure  ||\n");
  printf("||                   Dev: Juan Vitório                ||\n");
  printf("||              Professor: Flavius Gorgônio           ||\n");
  printf("========================================================\n");
  printf("|| O sistema tem o intuito de gerenciar uma manicure  ||\n");
  printf("|| /pedicure, sendo possível cadastrar clientes, ho-  ||\n");
  printf("||         rários, dentre outras necessidades.        ||\n");
  printf("========================================================\n");

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

void infos_dev(void)
{
  printf("========================================================\n");
  printf("||                     Desenvolvedor                  ||\n");
  printf("========================================================\n");
  printf("||                 Juan Vitório - BSI 2023            ||\n");
  printf("||               juanvitorioclash@gmail.com           ||\n");
  printf("||         Github: https://github.com/JuanVitorio     ||\n");
  printf("========================================================\n");

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
