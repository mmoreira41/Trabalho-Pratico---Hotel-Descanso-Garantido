# Funcionalidades do Sistema de Gerenciamento de Hotel

## 1. Cadastrar Cliente
**Descrição:** Permite cadastrar novos clientes no sistema.

**Função:** `void cadastrarCliente(Cliente *clientes, int *numClientes)`

**Parâmetros:**
- `Cliente *clientes`: Array de clientes.
- `int *numClientes`: Ponteiro para o número de clientes cadastrados.

**Exemplo de Uso:**
```c
Cliente clientes[100];
int numClientes = 0;
cadastrarCliente(clientes, &numClientes);
```

## 2. Cadastrar Funcionário
**Descrição:** Permite cadastrar novos funcionários no sistema.

**Função:** `void cadastrarFuncionario(Funcionario *funcionarios, int *numFuncionarios)`

**Parâmetros:**
- `Funcionario *funcionarios`: Array de funcionários.
- `int *numFuncionarios`: Ponteiro para o número de funcionários cadastrados.

**Exemplo de Uso:**
```c
Funcionario funcionarios[100];
int numFuncionarios = 0;
cadastrarFuncionario(funcionarios, &numFuncionarios);
