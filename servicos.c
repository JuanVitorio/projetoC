#include "servicos.h"
#include <stdio.h>
#include <stdlib.h>

int op;

void servicos(void)
{
  system("clear||cls");
  printf("========================================================\n");
  printf("||                      Menu Serviços                 ||\n");
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
    create_servico();
  }
  else if (op == 2)
  {
    update_servico();
  }
  else if (op == 3)
  {
    delete_servico();
  }
  else if (op == 4)
  {
    listar_servicos();
  }
  else if (op == 5)
  {
    pesquisar_servico();
  }
  else
  {
    printf("Digite uma opção válida");
    servicos();
  }
}

void create_servico(void)
{
  printf("o id do serviço que vai ser automático\n");
  printf("o que é o serviço (manicure, pedicure, cabelo)\n");
  printf("preço do serviço\n");
  printf("observações\n");
  printf("tempo médio de demora do serviço\n");
}

void delete_servico(void)
{
  printf("==================================================\n");
  printf("|| Digite o ID do funcionário que quer DELETAR: ||\n");
  printf("==================================================\n");

  // listar funcionários

  printf("===============================================\n");
  printf("||             Funcionário deletado          ||\n");
  printf("===============================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}

void update_servico(void)
{
  printf("====================================================\n");
  printf("|| Digite o ID do funcionário que quer ATUALIZAR: ||\n");
  printf("====================================================\n");
  printf("||             O que deseja atualizar?            ||\n");
  printf("||        Nome(0) - Telefone(1) - Gênero(2)       ||\n");
  printf("====================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}

void listar_servicos(void)
{
  printf("==================================================\n");
  printf("||                  Funcionários:               ||\n");
  printf("==================================================\n");
  // for dos funcionários

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}

void pesquisar_servico(void)
{
  printf("==================================================\n");
  printf("||         Digite o nome do funcionário:        ||\n");
  printf("==================================================\n");

  printf("0 para voltar \n");
  scanf("%d", &op);
  if (op == 0)
  {
    servicos();
  }
  else
  {
    servicos();
  }
}
