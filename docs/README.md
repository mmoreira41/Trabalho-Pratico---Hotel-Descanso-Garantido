
# Documentação do Sistema de Gerenciamento de Hotel

## Descrição
Este sistema foi desenvolvido para gerenciar clientes, funcionários, estadias e quartos do Hotel Descanso Garantido. Ele permite cadastrar clientes e funcionários, registrar estadias, baixar estadias e consultar informações cadastradas.

## Funcionalidades

### 1. Cadastrar Cliente
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
