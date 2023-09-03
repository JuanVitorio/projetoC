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

// funções clientes--------
void clientes(void);
void delete_cliente(void);
void update_cliente(void);
void create_cliente(void);
void listar_clientes(void);
void pesquisar_cliente(void);
//--------------------------

// funções funcionários-------
void funcionarios(void);
void create_funcionario(void);
void delete_funcionario(void);
void update_funcionario(void);
void listar_funcionarios(void);
void pesquisar_funcionario(void);
//----------------------------

int main(void)
{
  menu_principal();

  return 0;
}

void menu_principal(void)
{
  int op;
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

  scanf("%d", &op);

  if (op == 1)
  {
    clientes();
  }
  else if (op == 2)
  {
    funcionarios();
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

// opções CLIENTES-------------------------------------------------------

void clientes(void)
{
  int op;
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

  scanf("%d", &op);

  if (op == 1)
  {
    create_cliente();
  }
  else if (op == 2)
  {
    update_cliente();
  }
  else if (op == 3)
  {
    delete_cliente();
  }
  else if (op == 4)
  {
    listar_clientes();
  }
  else if (op == 5)
  {
    pesquisar_cliente();
  }
  else
  {
    printf("Digite uma opção válida");
    menu_principal();
  }
}

void create_cliente(void)
{
  printf("==============================================\n");
  printf("||              Cadastrar cliente           ||\n");
  printf("==============================================\n");
  printf("||            * Nome do(a) cliente:         ||\n");
  printf("||           * Telefone pra contato:        ||\n");
  printf("||              * Gênero (M | F):           ||\n");
  printf("==============================================\n");
  printf("|| ... ||\n");
}

void delete_cliente(void)
{
  printf("==============================================\n");
  printf("|| Digite o ID do cliente que quer DELETAR: ||\n");
  printf("==============================================\n");

  // listar clientes

  printf("===============================================\n");
  printf("||             Cliente deletado              ||\n");
  printf("===============================================\n");
}

void update_cliente(void)
{
  printf("================================================\n");
  printf("|| Digite o ID do cliente que quer ATUALIZAR: ||\n");
  printf("================================================\n");
  printf("||          O que deseja atualizar?           ||\n");
  printf("||      Nome(0) - Telefone(1) - Gênero(2)     ||\n");
  printf("================================================\n");
}

void listar_clientes(void)
{
  printf("==================================================\n");
  printf("||                  Clientes:                   ||\n");
  printf("==================================================\n");
  // for dos clientes
}

void pesquisar_cliente(void)
{
  printf("================================================\n");
  printf("||           Digite o nome do cliente:        ||\n");
  printf("================================================\n");
}

// opções FUNCIONARIOS

void create_funcionario(void)
{
  printf("==============================================\n");
  printf("||             Cadastrar Funcionário        ||\n");
  printf("==============================================\n");
  printf("||           * Nome do(a) funcionário:      ||\n");
  printf("||           * Telefone pra contato:        ||\n");
  printf("||              * Gênero (M | F):           ||\n");
  printf("==============================================\n");
  printf("|| ... ||\n");
}

void delete_funcionario(void)
{
  printf("==================================================\n");
  printf("|| Digite o ID do funcionário que quer DELETAR: ||\n");
  printf("==================================================\n");

  // listar funcionários

  printf("===============================================\n");
  printf("||             Funcionário deletado          ||\n");
  printf("===============================================\n");
}

void update_funcionario(void)
{
  printf("====================================================\n");
  printf("|| Digite o ID do funcionário que quer ATUALIZAR: ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("||        Nome(0) - Telefone(1) - Gênero(2)       ||\n");
  printf("====================================================\n");
}

void listar_funcionarios(void)
{
  printf("==================================================\n");
  printf("||                  Funcionários:               ||\n");
  printf("==================================================\n");
  // for dos funcionários
}

void pesquisar_funcionario(void)
{
  printf("==================================================\n");
  printf("||         Digite o nome do funcionário:        ||\n");
  printf("==================================================\n");
}

void funcionarios(void)
{
  int op;
  system("clear||cls");
  printf("========================================================\n");
  printf("||                    Menu Funcionários               ||\n");
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

  scanf("%d", &op);

  if (op == 1)
  {
    create_funcionario();
  }
  else if (op == 2)
  {
    update_funcionario();
  }
  else if (op == 3)
  {
    delete_funcionario();
  }
  else if (op == 4)
  {
    listar_funcionarios();
  }
  else if (op == 5)
  {
    pesquisar_funcionario();
  }
  else
  {
    printf("Digite uma opção válida");
    menu_principal();
  }
}