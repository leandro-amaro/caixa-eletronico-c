# 🏧 Simulador de Caixa Eletrônico em C

Projeto desenvolvido durante o curso de Análise e Desenvolvimento de Sistemas (ADS) para praticar lógica de programação estruturada, controle de fluxo e validação de dados.

## 📋 Sobre o Projeto
Este é um simulador de ATM (Caixa Eletrônico) via console (CLI). O objetivo principal foi criar um sistema robusto que simula operações bancárias reais, com foco em **tratamento de erros** e **segurança de entrada de dados**.

Diferente de exercícios simples, este código foi projetado para não "quebrar" caso o usuário digite letras ou caracteres inválidos.

## 🚀 Funcionalidades

### 🔐 Segurança e Autenticação
- **Sistema de Login:** Acesso protegido por senha numérica de 4 dígitos.
- **Limite de Tentativas:** O usuário tem 3 chances para acertar a senha.
- **Bloqueio de Conta:** Se as tentativas se esgotarem, o sistema bloqueia o acesso e encerra.

### 💰 Operações Bancárias
- **Consultar Saldo:** Visualização do saldo atualizado.
- **Saque:**
  - Validação de saldo insuficiente (não permite ficar negativo).
  - Validação de valores inválidos (negativos ou zero).
- **Depósito:** Incremento seguro do saldo.

### 🛡️ Tratamento de Erros (Input Safety)
- **Proteção contra Loop Infinito:** Uso de limpeza de buffer (`getchar`) para impedir que o programa trave se o usuário digitar letras em campos numéricos.
- **Validação de Menus:** O sistema ignora opções inexistentes e pede nova entrada.

## 🛠️ Tecnologias Utilizadas
- **Linguagem C** (Padrão ANSI/C99)
- **Bibliotecas:** `stdio.h`, `stdbool.h`

## 💻 Como Rodar o Projeto

### Pré-requisitos
Você precisa de um compilador C instalado (como GCC no Linux/Windows ou Clang no Mac).

### Passo a passo
1. Clone o repositório:
   ```bash
   git clone [https://github.com/leandro-amaro/sistema-bancario-c.git](https://github.com/leandro-amaro/sistema-bancario-c.git)
   
2. Entre na Pasta: 
**cd sistema-bancario-c**

3. Compile o código:
gcc menu.c -o caixa_eletronico

4. Execute o Programa:
- Linux/Mac: ./caixa_eletronico
- Windows: caixa_eletronico.exe

### 📝 Autor

Desenvolvido por Leandro Amaro como parte dos estudos de Lógica de Programação.

Este projeto é apenas para fins educacionais.
