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
  char genero;
  // int dia, mes, ano;
  char status;
};

void gravar_cliente(Cliente *cli);
void listar_clientes(Cliente *cli);
void exibir_clientes(void);

typedef struct funcionario
{
  char nome[100];
  /// int dia, mes, ano;
  // char genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  char cpf[12];
  char endereco[100];
  // double salario;
  char status;
} Funcionario;

void gravar_funcionario(Funcionario *fun);
void listar_funcionarios(Funcionario *fun);
void exibir_funcionarios(void);

#endif