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

// Módulos previstos:
//- Clientes
//- Funcionários
//- Horários
//- Avaliações
//- Agendamento
//- Pesquisar

void menu_principal(void);
void informacoes(void);
void infos_dev(void);
void clientes(void);

int main(void)
{
  menu_principal();
  informacoes();
  infos_dev();
  return 0;
}

void menu_principal(void)
{
  // char op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||               Manicure/Pedicure Pretty Nail        ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      1. Clientes                   ||\n");
  printf("||                      2. Funcionários               ||\n");
  printf("||                      3. Horários                   ||\n");
  printf("||                      4.Agendamentos                ||\n");
  printf("||                      5. Pesquisar                  ||\n");
  printf("||                      0. Sair                       ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                Digite o número desejado:           ||\n");
  printf("||                                                    ||\n");
  printf("========================================================\n");
  // scanf("%c", &op);
  //  getchar();
  printf("Aperte <ENTER> para continuar...\n");
  getchar();
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
  printf("Aperte <ENTER> para continuar...\n");
  getchar();
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
  printf("Aperte <ENTER> para continuar...\n");
  getchar();
}

void clientes(void)
{
  // char op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||                      Menu Clientes                 ||\n");
  printf("========================================================\n");
  printf("||                                                    ||\n");
  printf("||                      1. Cadastrar                  ||\n");
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
  // scanf("%c", &op);
  // getchar();
  printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
  getchar();
}