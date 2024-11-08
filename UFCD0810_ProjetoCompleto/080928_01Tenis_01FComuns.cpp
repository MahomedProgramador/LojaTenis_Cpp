//*************************************************
//*  0806 - Princ�pios Metodol�gicos de 
//*         Programa��o
//*************************************************
//*************************************************
//* Cap�tulo 05 - Projeto Completo
//*************************************************
//*************************************************
//*  0809 - Programa��o em C/C++ - Fundamentos
//*************************************************
//*************************************************
//* Cap�tulo 28 - Projeto Completo
//*************************************************
//*************************************************
//*  0811 - An�lise de Sistemas Inform�ticos
//*************************************************
//*************************************************
//* Cap�tulo 05 - Projeto Completo
//*************************************************
//******************************************************
//* Ficheiro: 080928_01Livraria_01FComuns.cpp
//*******************************************************
//* http://www.dontpad.com/Prog05/0811_Principal
//*******************************************************
//* Cria��o de Bibliotecas
//*******************************************************
//* Enunciado: Fa�a um programa que gere uma livraria.
//*    Especifica��es:
//*     Op��es do menu:   
//*       -> 
//*        - Inserir produto      - Apagar produto
//*        - Pesquisar produto    - Listar produto
//*        - Repor produto        - Vender produto
//*        - Sair do programa.
//*
//*  Dados de um livro:
//*   - c�digo do livro;
//*   - autor do livro;
//*   - t�tulo do livro;
//*   - editora do livro; 
//*   - pre�o do livro; 
//*   - ano de Publica��o;
//*   - n�mero do arm�rio onde est� guardado;
//*   - letra da prateleira.
//*
//**********************************************************
//*   - Vetores din�micos; classes derivadas; ficheiros
//*   - Operadores; Linguagem orientada a objetos - conceitos 
//*   - Bibliotecas. Base de Dados. 
//************************************************************
//* Vers�o 01 
//*   - Vetores est�ticos - locais
//* Vers�o 02 
//*   - Vetores din�micos - globais
//* Vers�o 03 
//*   - Vetores din�micos - globais
//* Vers�o 04 
//*   - Vetores din�micos - locais
//* Vers�o 05 
//*   - Vetores din�micos - locais
//* Vers�o 06 
//*   - Vetores din�micos - locais
//* Vers�o 07 
//*   - Vetores din�micos - Ficheiros
//* Vers�o 08 
//*   - Vetores din�micos - Ficheiros - Libraries
//* Vers�o 09 
//*   - Vetores din�micos - Ficheiros - Libraries - Encripta��o
//************************************************************
//* "dontpad.com/Prog05"
//************************************************************
//*********************************************************
//*  Ordem de trabalhos:
//*   - Classe: dados, construtores, setters, getters, 
//*             leitura e escrita. 
//*   - Menu: op��es do menu.
//*
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11

//*******************************************************
//* Cria��o de Bibliotecas
//*******************************************************
//* Este ficheiro cont�m as fun��es comuns
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
//* Obten��o dos elementos de uma data e hora - Vers�o C/C++
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
        // substr(posi��o inicial, num. carcateres)
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
//* Obten��o dos elementos de uma data e hora - Vers�o C++
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



	




	
