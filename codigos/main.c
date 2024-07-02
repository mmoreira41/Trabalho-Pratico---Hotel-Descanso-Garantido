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
void pesquisarCliente(Cliente *clientes, int numClientes) {
    int codigo;
    printf("Digite o codigo do cliente: ");
    scanf("%d", &codigo);

    for (int i = 0; i < numClientes; i++) {
        if (clientes[i].codigo == codigo) {
            printf("Codigo: %d\nNome: %s\nEndereco: %s\nTelefone: %s\n", clientes[i].codigo, clientes[i].nome, clientes[i].endereco, clientes[i].telefone);
            return;
        }
    }
    printf("Cliente nao encontrado.\n");
}

void pesquisarFuncionario(Funcionario *funcionarios, int numFuncionarios) {
    int codigo;
    printf("Digite o codigo do funcionario: ");
    scanf("%d", &codigo);

    for (int i = 0; i < numFuncionarios; i++) {
        if (funcionarios[i].codigo == codigo) {
            printf("Codigo: %d\nNome: %s\nTelefone: %s\nCargo: %s\nSalario: %.2f\n", funcionarios[i].codigo, funcionarios[i].nome, funcionarios[i].telefone, funcionarios[i].cargo, funcionarios[i].salario);
            return;
        }
    }
    printf("Funcionario nao encontrado.\n");
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
            }
            (*numEstadias)--;
            return;
        }
    }
    printf("Estadia nao encontrada.\n");
}
void mostrarEstadiasCliente(Estadia *estadias, int numEstadias, int codigoCliente) {
    int encontrou = 0;
    for (int i = 0; i < numEstadias; i++) {
        if (estadias[i].codigoCliente == codigoCliente) {
            printf("Codigo Estadia: %d\nData Entrada: %s\nData Saida: %s\nQuantidade Diarias: %d\nNumero Quarto: %d\n", estadias[i].codigoEstadia, estadias[i].dataEntrada, estadias[i].dataSaida, estadias[i].quantidadeDiarias, estadias[i].numeroQuarto);
            encontrou = 1;
        }
    }
    if (!encontrou) {
        printf("Nenhuma estadia encontrada para o cliente com codigo %d.\n", codigoCliente);
    }
}
int main() {
    Cliente clientes[100];
    Funcionario funcionarios[100];
    Estadia estadias[100];
    Quarto quartos[100] = {
        {101, 2, 150.0, "desocupado"},
        {102, 2, 150.0, "desocupado"},
        {103, 4, 200.0, "desocupado"},
        {104, 1, 100.0, "desocupado"},
    };

    int numClientes = 0, numFuncionarios = 0, numEstadias = 0, numQuartos = 4;
    int opcao;

    do {
        printf("1. Cadastrar Cliente\n2. Cadastrar Funcionario\n3. Cadastrar Estadia\n4. Baixar Estadia\n5. Pesquisar Cliente\n6. Pesquisar Funcionario\n7. Mostrar Estadias de um Cliente\n8. Sair\n");
        printf("Digite a opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, &numClientes);
                break;
            case 2:
                cadastrarFuncionario(funcionarios, &numFuncionarios);
                break;
            case 3:
                cadastrarEstadia(estadias, &numEstadias, clientes, numClientes, quartos, numQuartos);
                break;
            case 4:
                baixarEstadia(estadias, &numEstadias, quartos, numQuartos);
                break;
            case 5:
                pesquisarCliente(clientes, numClientes);
                break;
            case 6:
                pesquisarFuncionario(funcionarios, numFuncionarios);
                break;
            case 7:
                printf("Digite o codigo do cliente: ");
                int codigoCliente;
                scanf("%d", &codigoCliente);
                mostrarEstadiasCliente(estadias, numEstadias, codigoCliente);
                break;
            case 8:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
