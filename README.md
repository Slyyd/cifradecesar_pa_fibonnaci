# Criptografia de Texto em C

Este projeto consiste em uma aplicação em linguagem C para criptografia de mensagens via terminal. O programa implementa combinações de técnicas de substituição (Cifra de César, Progressão Aritmética e Sequência de Fibonacci) e registra os resultados em um arquivo de log local.

---

## Funcionalidades

- **Cifra de César**: Aplica um deslocamento fixo de posições aos caracteres no alfabeto selecionado.
- **Cifra de Progressão Aritmética (PA)**: Modifica o deslocamento de cada caractere progressivamente com base em uma variação geométrica/aritmética calculada passo a passo.
- **Cifra de Fibonacci (Golden)**: Aplica um deslocamento dinâmico a cada caractere utilizando os termos sequenciais da Sequência de Fibonacci ($1, 1, 2, 3, 5, 8, \dots$).
- **Configurações Personalizáveis**: Permite alterar dinamicamente em tempo de execução:
  - Tamanho do deslocamento da Cifra de César (`shift`).
  - Alfabeto customizado.
  - Peso da cifra por Progressão Aritmética (`criptograficValue`).
  - Tipo de cifra ativa (PA ou Fibonacci).
- **Log Automático**: Salva cada mensagem criptografada no arquivo `resultado_criptografia.txt` contendo a palavra gerada, o tipo de cifra utilizada e o número de letras.

---

## Estrutura do Código

- `appConfigs`: Estrutura de dados que armazena as configurações atuais da aplicação (`shift`, `criptograficValue`, `selectedEncription` e `alfabet`).
- `applyCesar`: Realiza o deslocamento fixo inicial nos caracteres da mensagem.
- `applyPA`: Aplica a camada secundária de criptografia baseada em Progressão Aritmética.
- `applyGolden`: Aplica a camada secundária de criptografia baseada na Sequência de Fibonacci.
- `logMessage`: Registra o histórico das mensagens criptografadas no arquivo de texto.
- `initalMenu`, `configMenu`, `criptograficMenu`: Funções de interface interativa para navegação no terminal.

---

## Requisitos

- Compilador C (GCC, Clang ou similar).
- Sistema Operacional Linux/Unix ou ambiente com suporte ao comando `system("clear")`.

---

## Como Compilar e Executar

1. Clone o repositório ou baixe o arquivo fonte:
   ```bash
   git clone [https://github.com/slyyd/cifradecesar_pa_fibonnaci.git](https://github.com/slyyd/cifradecesar_pa_fibonnaci.git)
   cd cifradecesar_pa_fibonnaci
