#include <stdbool.h>

int valida_nome(char *nome);
int valida_cpf(char cpf[]);
int validate_email(char email[]);
int valida_telefone(char *telefone);
int valida_endereco(char *endereco);
void ler_nome(char *nome);
void ler_cpf(char cpf[]);
void ler_telefone(char *telefone);
void ler_email(char email[]);
void ler_endereco(char *endereco);
bool eh_letra_acentuada(char c);
void removerCaracteresNaoNumericos(char cpf[]);
void limpar_buffer();
int has_space(char *str);
char *str_to_lower(char *str);
void letra_maiuscula(char *algo);