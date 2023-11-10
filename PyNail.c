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
#include "servicos.h"
#include "PyNail.h"

// Módulos previstos:
//- Clientes
//- Funcionários
//- Horários
//- Avaliações
//- Agendamento
//- Pesquisar

int main(void)
{
  menu_principal();
  return 0;
}

// menu principal pra navegação
void menu_principal(void)
{
  int op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||               Manicure/Pedicure Pretty Nail        ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      1. Clientes                   ||\n");
  printf("||                      2. Funcionarios               ||\n");
  printf("||                      3. Horarios                   ||\n");
  printf("||                      4. Agendamento                ||\n");
  printf("||                      5. Servicos                   ||\n");
  printf("||                      6. Informacoes                ||\n");
  printf("||                      7. Infos. Dev.                ||\n");
  printf("||                      0. Sair                       ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");
  printf("Opcao:");
  scanf("%d", &op);

  switch (op)
  {
  case 0:
    printf("Código encerrado.");
    break;
  case 1:
    clientes();
    break;
  case 2:
    funcionarios();
    break;
  case 3:
    horarios();
    break;
  case 4:
    servicos();
    break;
  case 5:
    informacoes();
    break;
  case 6:
    infos_dev();
    break;
  default:
    printf("Digite algo válido");
    break;
  }
}

void informacoes(void)
{
  int op;
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
  int op;
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