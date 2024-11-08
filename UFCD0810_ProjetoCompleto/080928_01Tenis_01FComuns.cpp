//*************************************************
//*  0806 - Princípios Metodológicos de 
//*         Programação
//*************************************************
//*************************************************
//* Capítulo 05 - Projeto Completo
//*************************************************
//*************************************************
//*  0809 - Programação em C/C++ - Fundamentos
//*************************************************
//*************************************************
//* Capítulo 28 - Projeto Completo
//*************************************************
//*************************************************
//*  0811 - Análise de Sistemas Informáticos
//*************************************************
//*************************************************
//* Capítulo 05 - Projeto Completo
//*************************************************
//******************************************************
//* Ficheiro: 080928_01Livraria_01FComuns.cpp
//*******************************************************
//* http://www.dontpad.com/Prog05/0811_Principal
//*******************************************************
//* Criação de Bibliotecas
//*******************************************************
//* Enunciado: Faça um programa que gere uma livraria.
//*    Especificações:
//*     Opções do menu:   
//*       -> 
//*        - Inserir produto      - Apagar produto
//*        - Pesquisar produto    - Listar produto
//*        - Repor produto        - Vender produto
//*        - Sair do programa.
//*
//*  Dados de um livro:
//*   - código do livro;
//*   - autor do livro;
//*   - título do livro;
//*   - editora do livro; 
//*   - preço do livro; 
//*   - ano de Publicação;
//*   - número do armário onde está guardado;
//*   - letra da prateleira.
//*
//**********************************************************
//*   - Vetores dinâmicos; classes derivadas; ficheiros
//*   - Operadores; Linguagem orientada a objetos - conceitos 
//*   - Bibliotecas. Base de Dados. 
//************************************************************
//* Versão 01 
//*   - Vetores estáticos - locais
//* Versão 02 
//*   - Vetores dinâmicos - globais
//* Versão 03 
//*   - Vetores dinâmicos - globais
//* Versão 04 
//*   - Vetores dinâmicos - locais
//* Versão 05 
//*   - Vetores dinâmicos - locais
//* Versão 06 
//*   - Vetores dinâmicos - locais
//* Versão 07 
//*   - Vetores dinâmicos - Ficheiros
//* Versão 08 
//*   - Vetores dinâmicos - Ficheiros - Libraries
//* Versão 09 
//*   - Vetores dinâmicos - Ficheiros - Libraries - Encriptação
//************************************************************
//* "dontpad.com/Prog05"
//************************************************************
//*********************************************************
//*  Ordem de trabalhos:
//*   - Classe: dados, construtores, setters, getters, 
//*             leitura e escrita. 
//*   - Menu: opções do menu.
//*
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11

//*******************************************************
//* Criação de Bibliotecas
//*******************************************************
//* Este ficheiro contém as funções comuns
//*******************************************************
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstring>
#include <ctime>      // 
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
using namespace std; 

class DataEHoras {
	
	
	public:
		
//***************************************************************
static const std::string currentDate() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    //tstruct = *localtime_s(&now);
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
    return buf;
}

static const std::string currentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    //tstruct = *localtime_s(&now);
    localtime_s(&tstruct, &now);
    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
    return buf;
}

//***********************************************************
//* Obtenção dos elementos de uma data e hora - Versão C/C++
//**********************************************************
static int obtemAno(string data)
    {                                  // 01234567
    string infoAno = data.substr(0,4); // YYYY-MM-DD
	int ano = atoi(infoAno.c_str());  	
    return ano;	
	}  

static int obtemMes(string data)
    {                                  // 01234567
    string infoMes = data.substr(5,2); // YYYY-MM-DD
	int mes = atoi(infoMes.c_str());  	
    return mes;	
	}  

static int obtemDia(string data)
    {                                  // 012345678
    string infoDia = data.substr(8,2); // YYYY-MM-DD
	int dia = atoi(infoDia.c_str());  	
    return dia;	
	}  

static int obtemHoras(string tempo)
    {
    string infoHoras = tempo.substr(0,2);  // HH:MM:SS
        // substr(posição inicial, num. carcateres)
	int numHoras = atoi(infoHoras.c_str()); 
	    // ascii to integer    	
		// "c_str()" - c_STRING() - 
		// transforma uma "string" num array
		// de caracteres.
    return numHoras;	
	}   

static int obtemMinutos(string tempo)
    {                                       // 01234567
    string infoMinutos = tempo.substr(3,2); // HH:MM:SS
	int numMinutos = atoi(infoMinutos.c_str());  	
    return numMinutos;	
	}  




//***********************************************************
//* Obtenção dos elementos de uma data e hora - Versão C++
//**********************************************************
static int obtemAnoV2(string data)
    {                                  // 01234567
    string infoAno = data.substr(0,4); // YYYY-MM-DD
	int ano = stoi(infoAno,nullptr,10);  	
    return ano;	
	}  

static int obtemMesV2(string data)
    {                                  // 01234567
    string infoMes = data.substr(5,2); // YYYY-MM-DD
	int mes = stoi(infoMes,nullptr,10);  	
    return mes;	
	}  

static int obtemDiaV2(string data)
    {                                  // 01234567
    string infoDia = data.substr(8,2); // YYYY-MM-DD
	int dia = stoi(infoDia,nullptr,10);  	
    return dia;	
	}  
	
static int obtemHorasV2(string tempo)
    {                                   // 01234567
    string infoHoras = tempo.substr(0,2); // HH:MM:SS
	int horas = stoi(infoHoras,nullptr,10);  	
    return horas;	
	}  	

static int obtemMinutosV2(string tempo)
    {                                     // 01234567
    string infoMinutos = tempo.substr(0,2); // HH:MM:SS
	int minutos = stoi(infoMinutos,nullptr,10);  	
    return minutos;	
	} 	
	
	
};



	




	
