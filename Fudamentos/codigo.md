# Código do Sistema de Gerenciamento de Hotel

Este documento descreve a estrutura e as funcionalidades do código do sistema de gerenciamento de hotel.

## Estrutura do Código

O código está organizado no arquivo `main.c`, que contém todas as funções principais do sistema, incluindo:

- Cadastro de clientes
- Cadastro de funcionários
- Registro de estadias
- Finalização de estadias
- Pesquisa de clientes
- Pesquisa de funcionários
- Exibição de estadias de um cliente

## Arquivo `main.c`

O arquivo `main.c` pode ser encontrado no diretório `codigo`. Ele inclui a implementação das seguintes funções:

1. `void cadastrarCliente(Cliente *clientes, int *numClientes)`
   - Descrição: Permite cadastrar novos clientes no sistema.
   - Parâmetros: Array de clientes e ponteiro para o número de clientes cadastrados.

2. `void cadastrarFuncionario(Funcionario *funcionarios, int *numFuncionarios)`
   - Descrição: Permite cadastrar novos funcionários no sistema.
   - Parâmetros: Array de funcionários e ponteiro para o número de funcionários cadastrados.

3. `void cadastrarEstadia(Estadia *estadias, int *numEstadias, Cliente *clientes, int numClientes, Quarto *quartos, int numQuartos)`
   - Descrição: Permite cadastrar novas estadias no sistema.
   - Parâmetros: Array de estadias, ponteiro para o número de estadias cadastradas, array de clientes cadastrados, número de clientes cadastrados, array de quartos disponíveis e número de quartos cadastrados.

4. `void baixarEstadia(Estadia *estadias, int *numEstadias, Quarto *quartos, int numQuartos)`
   - Descrição: Permite finalizar uma estadia, calcular o valor total e liberar o quarto.
   - Parâmetros: Array de estadias, ponteiro para o número de estadias cadastradas, array de quartos disponíveis e número de quartos cadastrados.

5. `void pesquisarCliente(Cliente *clientes, int numClientes)`
   - Descrição: Permite buscar e exibir informações de um cliente pelo código.
   - Parâmetros: Array de clientes cadastrados e número de clientes cadastrados.

6. `void pesquisarFuncionario(Funcionario *funcionarios, int numFuncionarios)`
   - Descrição: Permite buscar e exibir informações de um funcionário pelo código.
   - Parâmetros: Array de funcionários cadastrados e número de funcionários cadastrados.

7. `void mostrarEstadiasCliente(Estadia *estadias, int numEstadias, int codigoCliente)`
   - Descrição: Permite listar todas as estadias de um cliente pelo código do cliente.
   - Parâmetros: Array de estadias cadastradas, número de estadias cadastradas e código do cliente.

## Acessando o Código

Para visualizar e executar o código completo, acesse o arquivo `main.c` no diretório `codigo`.

### Exemplo de Estrutura do Código

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int codigo;
    char nome[100];
    char endereco[200];
    char telefone[15];
} Cliente;

typedef struct {
    int codigo;
    char nome[100];
    char telefone[15];
    char cargo[50];
    float salario;
} Funcionario;

typedef struct {
    int codigoEstadia;
    int codigoCliente;
    int numeroQuarto;
    char dataEntrada[20];
    char dataSaida[20];
    int quantidadeDiarias;
} Estadia;

typedef struct {
    int numeroQuarto;
    int quantidadeHospedes;
    float valorDiaria;
    char status[10]; // "ocupado" ou "desocupado"
} Quarto;

void cadastrarCliente(Cliente *clientes, int *numClientes) {
    Cliente novoCliente;
    novoCliente.codigo = *numClientes + 1;

    printf("Digite o nome do cliente: ");
    scanf("%s", novoCliente.nome);

    printf("Digite o endereco do cliente: ");
    scanf("%s", novoCliente.endereco);

    printf("Digite o telefone do cliente: ");
    scanf("%s", novoCliente.telefone);

    clientes[*numClientes] = novoCliente;
    (*numClientes)++;
    printf("Cliente cadastrado com sucesso!\n");
}

void cadastrarFuncionario(Funcionario *funcionarios, int *numFuncionarios) {
    Funcionario novoFuncionario;
    novoFuncionario.codigo = *numFuncionarios + 1;

    printf("Digite o nome do funcionario: ");
    scanf("%s", novoFuncionario.nome);

    printf("Digite o telefone do funcionario: ");
    scanf("%s", novoFuncionario.telefone);

    printf("Digite o cargo do funcionario: ");
    scanf("%s", novoFuncionario.cargo);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &novoFuncionario.salario);

    funcionarios[*numFuncionarios] = novoFuncionario;
    (*numFuncionarios)++;
    printf("Funcionario cadastrado com sucesso!\n");
}

void cadastrarEstadia(Estadia *estadias, int *numEstadias, Cliente *clientes, int numClientes, Quarto *quartos, int numQuartos) {
    Estadia novaEstadia;
    int codigoCliente, numeroQuarto;

    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigoCliente);

    // Verificar se o cliente existe
    int clienteExiste = 0;
    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].codigo == codigoCliente) {
            clienteExiste = 1;
            break;
        }
    }
    if (!clienteExiste) {
        printf("Cliente nao encontrado.\n");
        return;
    }

    printf("Digite a quantidade de hospedes: ");
    int quantidadeHospedes;
    scanf("%d", &quantidadeHospedes);

    // Encontrar um quarto disponível
    int quartoEncontrado = 0;
    for (int i = 0; i < numQuartos; i++) {
        if (quartos[i].quantidadeHospedes >= quantidadeHospedes && strcmp(quartos[i].status, "desocupado") == 0) {
            numeroQuarto = quartos[i].numeroQuarto;
            strcpy(quartos[i].status, "ocupado");
            quartoEncontrado = 1;
            break;
        }
    }
    if (!quartoEncontrado) {
        printf("Nao ha quartos disponiveis para a quantidade de hospedes desejada.\n");
        return;
    }

    novaEstadia.codigoEstadia = *numEstadias + 1;
    novaEstadia.codigoCliente = codigoCliente;
    novaEstadia.numeroQuarto = numeroQuarto;

    printf("Digite a data de entrada (dd/mm/aaaa): ");
    scanf("%s", novaEstadia.dataEntrada);
    printf("Digite a data de saida (dd/mm/aaaa): ");
    scanf("%s", novaEstadia.dataSaida);

    struct tm tmEntrada, tmSaida;
    strptime(novaEstadia.dataEntrada, "%d/%m/%Y", &tmEntrada);
    strptime(novaEstadia.dataSaida, "%d/%m/%Y", &tmSaida);

    time_t tEntrada = mktime(&tmEntrada);
    time_t tSaida = mktime(&tmSaida);

    novaEstadia.quantidadeDiarias = (difftime(tSaida, tEntrada) / (60 * 60 * 24));
    estadias[*numEstadias] = novaEstadia;
    (*numEstadias)++;
    printf("Estadia cadastrada com sucesso!\n");
}

void baixarEstadia(Estadia *estadias, int *numEstadias, Quarto *quartos, int numQuartos) {
    int codigoEstadia;
    printf("Digite o codigo da estadia: ");
    scanf("%d", &codigoEstadia);

    for (int i = 0; i < *numEstadias; i++) {
        if (estadias[i].codigoEstadia == codigoEstadia) {
            int numeroQuarto = estadias[i].numeroQuarto;
            float valorTotal = 0;
            for (int j = 0; j < numQuartos; j++) {
                if (quartos[j].numeroQuarto == numeroQuarto) {
                    valorTotal = quartos[j].valorDiaria * estadias[i].quantidadeDiarias;
                    strcpy(quartos[j].status, "desocupado");
                    break;
                }
            }
            printf("O valor total a ser pago pelo cliente e: %.2f\n", valorTotal);
            // Remover a estadia do array
            for (int k = i; k < *numEstadias - 1; k++) {
                estadias[k] = estadias[k + 1];
           