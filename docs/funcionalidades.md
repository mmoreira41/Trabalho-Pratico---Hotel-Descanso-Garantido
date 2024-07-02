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
````
## 3. Cadastrar Estadia
**Descrição:** Permite cadastrar novas estadias no sistema.

**Função:** `void cadastrarEstadia(Estadia *estadias, int *numEstadias, Cliente *clientes, int numClientes, Quarto *quartos, int numQuartos)`

**Parâmetros:**
- `Estadia *estadias`: Array de estadias.
- `int *numEstadias`: Ponteiro para o número de estadias cadastradas.
- `Cliente *clientes`: Array de clientes cadastrados.
- `int numClientes`: Número de clientes cadastrados.
- `Quarto *quartos`: Array de quartos disponíveis.
- `int numQuartos`: Número de quartos cadastrados.

**Exemplo de Uso:**
```c
Estadia estadias[100];
int numEstadias = 0;
Cliente clientes[100];
int numClientes = 5;
Quarto quartos[100] = { {101, 2, 150.0, "desocupado"}, {102, 2, 150.0, "desocupado"} };
int numQuartos = 2;

cadastrarEstadia(estadias, &numEstadias, clientes, numClientes, quartos, numQuartos);
````
## 4. Baixar Estadia
**Descrição:** Permite finalizar uma estadia, calcular o valor total e liberar o quarto.

**Função:** `void baixarEstadia(Estadia *estadias, int *numEstadias, Quarto *quartos, int numQuartos)`

**Parâmetros:**
- `Estadia *estadias`: Array de estadias.
- `int *numEstadias`: Ponteiro para o número de estadias cadastradas.
- `Quarto *quartos`: Array de quartos disponíveis.
- `int numQuartos`: Número de quartos cadastrados.

**Exemplo de Uso:**
```c
Estadia estadias[100];
int numEstadias = 5;
Quarto quartos[100] = { {101, 2, 150.0, "ocupado"}, {102, 2, 150.0, "ocupado"} };
int numQuartos = 2;

baixarEstadia(estadias, &numEstadias, quartos, numQuartos);
````
## 5. Pesquisar Cliente
**Descrição:** Permite buscar e exibir informações de um cliente pelo código.

**Função:** `void pesquisarCliente(Cliente *clientes, int numClientes)`

**Parâmetros:**
- `Cliente *clientes`: Array de clientes cadastrados.
- `int numClientes`: Número de clientes cadastrados.

**Exemplo de Uso:**
```c
Cliente clientes[100];
int numClientes = 5;

pesquisarCliente(clientes, numClientes);
````
## 6. Pesquisar Funcionário
**Descrição:** Permite buscar e exibir informações de um funcionário pelo código.

**Função:** `void pesquisarFuncionario(Funcionario *funcionarios, int numFuncionarios)`

**Parâmetros:**
- `Funcionario *funcionarios`: Array de funcionários cadastrados.
- `int numFuncionarios`: Número de funcionários cadastrados.

**Exemplo de Uso:**
```c
Funcionario funcionarios[100];
int numFuncionarios = 5;

pesquisarFuncionario(funcionarios, numFuncionarios);
````
