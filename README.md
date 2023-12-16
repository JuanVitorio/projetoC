# CNail 
## Sistema de gerenciamento para uma manicure/pedicure
### Explicação breve do código:

O CNail é um projeto de avaliação para a matéria de programação ministrada pelo professor Flavius Gorgônio, professor da UFRN - Campus Caicó.

O projeto conta com 3 (três) módulos de cadastro e um para relatórios.

---

### **Como executar o programa:** 

* Recomendo que execute o código em um Linux ou na plataforma online [Replit](https://replit.com/~).
  

No terminal de comandos, digite:
```
gcc *.c -o programa
```
Isso irá gerar um arquivo .exe que irá servir para executar o código.

Para executar o código, ainda  no terminal digite:
```
./programa
```

Perceba que o executável terá o nome que você definiu quando gerou ele, nesse caso, "programa".

---
### **Como usar o programa:**

A tela inicial irá te exibir os módulos disponíveis e duas telas com informações sobre o código e o desenvolvedor.

### Opções:
- Módulo de Clientes;
- Módulo de Funcionários;
- Módulo de Agendamentos;
- Módulo de Relatórios;
- Informações do programa;
- Informações do desenvolvedor;

#### Módulo de clientes:
Neste módulo você tem a dispor todas as funções de um [CRUD](https://coodesh.com/blog/dicionario/o-que-e-crud/), além da Busca no qual você pode pesquisar pelo CPF um cliente cadastrado.

Para cadastrar um cliente, você irá precisar de:
- CPF;
- Nome;
- Data de nascimento;
- Telefone para contato;
- Endereço;
- Email;
- Gênero.
  
Todos os campos possuem validações para que não seja possível cadastrar clientes com informações incorretas ou CPF's repetidos e, em alguns campos, será especificado a maneira como deve ser preenchido o campo, por exemplo: data(dd/mm/aaaa).

#### Módulo de funcionários:
Este módulo é praticamente igual ao anterior, com a diferença de que possui alguns campos extras requisitados. Novamente, alguns campos terão exemplos de como devem ser digitados.

Para cadastrar um funcionário, você irá precisar de:
- CPF;
- Nome;
- Data de nascimento;
- Gênero;
- Telefone para contato;
- Endereço;
- Email;
- Cargo;
- Salário.

---


