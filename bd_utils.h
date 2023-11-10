#ifndef BD_UTILS
#define BD_UTILS

typedef struct cliente Cliente;

struct cliente
{
  char nome[100];
  char telefone[13];
  char endereco[100];
  char email[100];
  char cpf[12];
  int genero;
  // int dia, mes, ano;
  char status;
};

void gravar_cliente(Cliente *cli);
void listar_cliente(Cliente *cli);
void exibir_clientes(void);

typedef struct funcionario Funcionario;

struct funcionario
{
  char nome[100];
  /// int dia, mes, ano;
  // char genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  // double salario;
  char status;
};

#endif