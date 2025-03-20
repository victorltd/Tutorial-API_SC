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
git clone https://github.com/lvc/api-sanity-checker.git
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

A saída édeverá ser similar a essa: 
```
API Sanity Checker 1.98.8
Copyright (C) 2018 Andrey Ponomarenko's ABI Laboratory
License: GNU LGPL 2.1 <http://www.gnu.org/licenses/>
This program is free software: you can redistribute it and/or modify it.

Written by Andrey Ponomarenko.
```
## Gerando e Executando Testes

Agora que o *API Sanity Checker* está pronto para uso, vamos gerar e rodar testes em uma biblioteca C/C++.
Antes de gerar os testes, é necessário criar um arquivo XML que descreve a versão da biblioteca e os caminhos para os arquivos de cabeçalho e bibliotecas compartilhadas.

Exemplo de arquivo descriptor.xml:

```
  <version>
            1.0
        </version>

        <headers>
            /home/victor/Documentos/Projetos/api-sanity-checker/PASTA
        </headers>

        <libs>
            /home/victor/Documentos/Projetos/api-sanity-checker/PASTA
        </libs>
```

É possível testar e verificar o uso da ferramenta ao executar:

```
api-sanity-checker -test
```
Serão criadas algumas pastas, onde irá gerar um pequeno teste, e será possível já ver a ferramenta funcionar.


## 5.2 Gerando testes

Para seguir nesse passo:
### 5.2.1 Clone esse repositório e cole a pasta inteira para a pasta onde estão os arquivos do API.

### 5.2.2 Mova o arquivo descriptor.xml que está dentro da pasta copiada pasta para a pasta raiz do API

A estrutura de pastas deve ficar dessa maneira:

├── INSTALL
├── LICENSE
├── Makefile
├── Makefile.pl
├── README.md
├── api-sanity-checker.pl
├── doc/
├── modules/
├── Tutorial-API_SC/
│   ├── descriptor.xml
│   ├── libsample.c
│   ├── libsample.h
│   ├── libsample.so
│   ├── Makefile
│   ├── version



Para gerar um conjunto de testes automatizados para os arquivos que criamos:

```
api-sanity-checker -lib NAME -d descriptor.xml -gen
```
## 5.3. Compilando os Testes
Depois de gerar os testes, compile-os usando:
```
api-sanity-checker -lib NAME -d descriptor.xml -build
```

## 5.3. Compilando os Testes
Depois de gerar os testes, compile-os usando:
```
api-sanity-checker -lib NAME -d descriptor.xml -build
```

## 5.4. Executando os Testes
Para rodar os testes gerados e verificar possíveis falhas:
```
api-sanity-checker -lib NAME -d descriptor.xml -run
```

_É possiível também fazer todas essas execuções de uma única vez por meio do comando:_
```
api-sanity-checker -lib NAME -d descriptor.xml -gen -build -run
```

## Referências:


- Documentação oficial: https://lvc.github.io/api-sanity-checker/
- Repositório da ferramenta: https://github.com/lvc/api-sanity-checker
- Artigo: https://www.devzery.com/post/api-sanity-checker-guide-for-testing-c-c-libraries
