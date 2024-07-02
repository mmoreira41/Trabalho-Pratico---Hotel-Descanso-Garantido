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

