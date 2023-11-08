typedef struct cliente
{
  char nome[100];
  char telefone[13];
  char endereco[100];
  char email[100];
  char cpf[12];
  int genero;
  //int dia, mes, ano;
  char status;
} Cliente;

void clientes(void);
Cliente *create_cliente(void);
void delete_cliente(void);
void update_cliente(void);
void listador_clientes(void);
void pesquisar_cliente(void);
void gravar_cliente(Cliente *cli);
void listar_cliente(Cliente *cli);
void exbir_clientes(void);