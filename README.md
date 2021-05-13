# Trabalho-TR1

Trabalho prático desenvolvido para a disciplina de TR1 na Universidade de Brasília no semestre de 2020-2.

### Participantes do Projeto 

|Projeto Engenharia de Software|  |
|--|--|
| Mariana Borges de Sampaio|  180046926 |

## Descrição do Projeto

Criar um simulador em c++ que desenvolva o funcinamento da camada física por meio da implementação das seguintes codificações:
- Binária
- Manchester 
- Bipolar

A segunda parte do trabalho consiste em criar um simulador em c++ que desenvolva o funcionamento da camada de enlace, sendo implementada algumas funções:

- Enquadramento por contagem de caracter 
- Enquadramento por inserção de bytes
- Desenquadramento por contagem de caracter
- Desenquadramento por inserção de bytes
- Correção de Erro usando Bit de paridade par
- Correção de Erro usando CRC
- Código Hamming 

## Especificações do SO 

> cat /etc/lsb-release

> DISTRIB_ID=Ubuntu
> 
> DISTRIB_RELEASE=18.04
> 
> DISTRIB_CODENAME=bionic
> 
> DISTRIB_DESCRIPTION="Ubuntu 18.04.5 LTS"
> 


## Camadas implementadas

- camadafisica.cpp
- camadafisica.h
- simulador.cpp
- camadaenlace.cpp
- camadaenlace.h

## Compilação 

> g++ -o simulador simulador.cpp

> ./simulador

