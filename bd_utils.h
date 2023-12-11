#ifndef BD_UTILS
#define BD_UTILS

typedef struct cliente Cliente;

struct cliente
{
  char nome[100];
  char telefone[15];
  char endereco[100];
  char email[100];
  char cpf[12];
  char genero;
  char data_nasci[15];
  char status;
};

void gravar_cliente(Cliente *cli);
void listar_clientes(Cliente *cli);
void exibir_clientes(void);

typedef struct funcionario
{
  char nome[100];
  char data_nasci[15];
  char genero;
  char email[100];
  char telefone[13];
  char funcao[30];
  char cpf[12];
  char endereco[100];
  char salario[20];
  char status;
} Funcionario;

void gravar_funcionario(Funcionario *fun);
void listar_funcionarios(Funcionario *fun);
void exibir_funcionarios(void);

typedef struct servicos
{
  int id;
  char cpf_cliente[15];
  char cpf_funcionario[15];
  char servico[50];
  char horario[20];
  char status;
} Servicos;

void gravar_servicos(Servicos *serv);
void listar_servicos(Servicos *serv);
void exibir_servicos(void);

#endif