# Documentação do Sistema de Gerenciamento de Hotel

## Descrição
Este sistema foi desenvolvido para gerenciar clientes, funcionários, estadias e quartos do Hotel Descanso Garantido. Ele permite cadastrar clientes e funcionários, registrar estadias, baixar estadias e consultar informações cadastradas.

## Índice
- [Funcionalidades](functionalities.md)
- [Plano de Testes](casos_de_testes.md)

## Funcionalidades Principais
O sistema permite realizar as seguintes operações:
- **Cadastro de Clientes**: Registra informações dos clientes.
- **Cadastro de Funcionários**: Registra informações dos funcionários.
- **Cadastro de Estadias**: Registra estadias dos clientes, assegurando que os quartos estejam disponíveis.
- **Baixa de Estadias**: Finaliza estadias, calcula o valor total a ser pago e libera o quarto.
- **Pesquisa de Clientes e Funcionários**: Permite buscar e exibir informações de clientes e funcionários.
- **Listagem de Estadias por Cliente**: Mostra todas as estadias de um cliente específico.

## Estrutura do Projeto
O projeto está organizado da seguinte forma:

```plaintext
hotel_management/
├── codigo/
│   └── main.c
├── docs/
│   ├── README.md
│   ├── functionalities.md
│   └── casos_de_testes.md
└── README.md
