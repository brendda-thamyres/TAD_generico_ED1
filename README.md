# Trabalho de Estrutura de Dados - TAD Coleção Genérica

**Aluna:** Brendda Thamyres Mendes Rodrigues  
**Professor:** Anselmo Cardoso de Paiva (ACP)  
**Data:** Maio de 2025

**Universidade Federal do Maranhão**  
**Curso de Ciência da Computação**

---

### Sobre o projeto

Esse trabalho implementa um Tipo Abstrato de Dados (TAD) para uma coleção estruturadamente genérica e modular, o que permite flexibilidade de armazenamento de dados e reciclagem de código.

No caso deste projeto, o tipo específico de dado armazenado é a estrutura `Casa`, que contém:

- Nome do proprietário: `char nomeDono[30]`
- Número da casa: `int endereço`
- Coordenadas (x, y) da localização da casa: `float localizacao[2]`

Para maior facilidade ao utilizar o TAD, o programa oferece um menu interativo, permitindo que o usuário escolha qual operação realizar:

1. Criar uma nova coleção  
2. Inserir elementos na coleção  
3. Listar elementos da coleção  
4. Consultar elemento  
5. Remover elemento  
6. Esvaziar coleção  
7. Destruir coleção  
8. Sair do programa  

**Sistema:** Windows 10  
**Terminal:** MYSYS2  
**Ambiente:** UCRT64  
**Compilador:** GCC  
**Método de compilação:** via Makefile  

---

### Como rodar o projeto

#### Pré-requisitos

- Ter o MYSYS2 UCRT64 instalado (também é possível utilizar via prompt de comando)
- Ter o GCC instalado
- Ter o Make instalado

---

#### Clone o repositório no terminal (powershell ou prompt de comando)

```bash
git clone https://github.com/brendda-thamyres/TAD_generico_ED1.git
````

### Via MYSYS2

#### Vá até a pasta do projeto

```bash
cd TAD_generico_ED1
```

#### Compile no terminal

```bash
make
```

#### Execute:

```bash
./main.exe
```

---

### Via Prompt de Comando

#### Vá até a pasta do projeto

```bash
cd TAD_generico_ED1
```

#### Compile:

```bash
gcc -Wall -Wextra -g3 casa.c main.c -o main.exe
```

#### Execute:

```bash
./main.exe
```

--- 
Este trabalho foi feito somente para fins acadêmicos.
