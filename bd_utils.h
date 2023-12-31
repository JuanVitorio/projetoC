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
  struct cliente *prox;
};

void gravar_cliente(Cliente *cli);
void listar_clientes(Cliente *cli);
void exibir_clientes(void);
void clientes_inativos();

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
  struct funcionario *prox;
} Funcionario;

void gravar_funcionario(Funcionario *fun);
void listar_funcionarios(Funcionario *fun);
void exibir_funcionarios(void);
void funcionarios_inativos(void);
void servicos_atrelado_funcionario(char cpf[]);

typedef struct agendamento
{
  int id;
  char cpf_cliente[12];
  char cpf_funcionario[12];
  char servico[50];
  char horario[20];
  char data[20];
  char status;
} Servicos;

void gravar_servicos(Servicos *serv);
void listar_servicos(Servicos *serv);
void exibir_servicos(void);
void servicos_inativos(void);
void nome_funcionario_responsavel(char cpf[]);
void nome_cliente_relacionado(char cpf[]);
int verifica_se_funcionario_eh_cliente(char *cpf);

#endif