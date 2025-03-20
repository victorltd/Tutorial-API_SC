# Tutorial API Sanity Checker

 O API Sanity Checker é uma ferramenta automática para gerar testes básicos de unidade para bibliotecas compartilhadas C/C++. Ele pode detectar falhas críticas executando testes gerados automaticamente.

Este guia explica como instalar todas as dependências e configurar o API Sanity Checker no Ubuntu

## 1. Instalando as Dependências
O API Sanity Checker depende das seguintes ferramentas:

* ABI Compliance Checker (1.99.24 ou mais recente)
* Perl 5
*  G++ Compiler
*  GNU Binutils
*  tags

### 1.1 Instalando o ABI Compliance Checker

```
sudo apt update
sudo apt install abi-compliance-checker
```

### 1.2 Instalando o ABI Compliance Checker
O Perl geralmente já vem instalado, mas você pode verificar com:

```
perl -v
```
Se o Perl não estiver instalado:

```
sudo apt update
sudo apt install perl
```


### 1.3 Instalando o G++ Compiler
O G++ é essencial para compilar os testes gerados pelo API Sanity Checker.

```
sudo apt update
sudo apt install g++
```
### 1.4 Instalando o GNU Binutils
O GNU Binutils é um conjunto de ferramentas para manipulação de binários.

```
sudo apt update
sudo apt install binutils
```
### 1.5 Instalando o Ctags
O Ctags ajuda a analisar o código-fonte e gerar tags para facilitar a interpretação da API.

```
sudo apt update
sudo apt install exuberant-ctags
```

## 2. Verificando as Dependências
Após a instalação, verifique se todas as dependências estão corretamente instaladas:

```
abi-compliance-checker --version   # Verifica o ABI Compliance Checker
perl -v                            # Verifica o Perl
g++ --version                      # Verifica o compilador G++
ld --version                        # Verifica o GNU Binutils
ctags --version                     # Verifica o Ctags
```
Se todos os comandos retornarem informações sobre a versão instalada, as dependências foram configuradas corretamente.

## 3. Instalando o API Sanity Checker
Agora que todas as dependências foram instaladas, podemos configurar o API Sanity Checker.


### 3.1. Baixando o API Sanity Checker
Clone o repositório oficial do GitHub:
```
git clone git://github.com/lvc/api-sanity-checker
```
Entre no diretório do projeto:
```
cd api-sanity-checker
```
### 3.2 Compilando e Instalando
Compile o código e instale o programa no sistema:
```
make
sudo make install prefix=/usr
```
##4. Verificando a Instalação

Depois da instalação, execute o seguinte comando para confirmar que o API Sanity Checker foi instalado corretamente:

```
api-sanity-checker --version
```

A saída é para ser algo similar a isso: 
```
API Sanity Checker 1.98.8
Copyright (C) 2018 Andrey Ponomarenko's ABI Laboratory
License: GNU LGPL 2.1 <http://www.gnu.org/licenses/>
This program is free software: you can redistribute it and/or modify it.

Written by Andrey Ponomarenko.
```

