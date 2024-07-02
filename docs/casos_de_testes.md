# Planejamento dos Casos de Teste

## 1. Cadastrar Cliente
**Entrada:**
- Nome: "Joao"
- Endereço: "Rua A"
- Telefone: "123456789"

**Procedimento:**
- Chamar a função `cadastrarCliente(clientes, &numClientes);`

**Saída Esperada:**
- Cliente cadastrado com sucesso e exibido no array de clientes.

## 2. Cadastrar Funcionário
**Entrada:**
- Nome: "Maria"
- Telefone: "987654321"
- Cargo: "Recepcionista"
- Salário: 1500.00

**Procedimento:**
- Chamar a função `cadastrarFuncionario(funcionarios, &numFuncionarios);`

**Saída Esperada:**
- Funcionário cadastrado com sucesso e exibido no array de funcionários.

## 3. Cadastrar Estadia
**Entrada:**
- Código do Cliente: 1
- Quantidade de Hóspedes: 2
- Data de Entrada: "01/01/2024"
- Data de Saída: "05/01/2024"

**Procedimento:**
- Chamar a função `cadastrarEstadia(estadias, &numEstadias, clientes, numClientes, quartos, numQuartos);`

**Saída Esperada:**
- Estadia cadastrada com sucesso e exibida no array de estadias.

## 4. Baixar Estadia
**Entrada:**
- Código da Estadia: 1

**Procedimento:**
- Chamar a função `baixarEstadia(estadias, &numEstadias, quartos, numQuartos);`

**Saída Esperada:**
- Estadia baixada com sucesso, valor total exibido, status do quarto alterado para desocupado.

## 5. Pesquisar Cliente
**Entrada:**
- Código do Cliente: 1

**Procedimento:**
- Chamar a função `pesquisarCliente(clientes, numClientes);`

**Saída Esperada:**
- Informações detalhadas do cliente exibidas.

## 6. Pesquisar Funcionário
**Entrada:**
- Código do Funcionário: 1

**Procedimento:**
- Chamar a função `pesquisarFuncionario(funcionarios, numFuncionarios);`

**Saída Esperada:**
- Informações detalhadas do funcionário exibidas.

## 7. Mostrar Estadias de um Cliente
**Entrada:**
- Código do Cliente: 1

**Procedimento:**
- Chamar a função `mostrarEstadiasCliente(estadias, numEstadias, codigoCliente);`

**Saída Esperada:**
- Lista de estadias do cliente exibida.
