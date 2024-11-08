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
//* Ficheiro: 080928_01Livraria_03Menus.cpp
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
//************************************************************
//* http://www.dontpad.com/Prog05/0811_Livraria
//*******************************************************
//* Cria��o de Bibliotecas
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11
//*******************************************************
//********************************************************
//* Este ficheiro cont�m todas as fun��es que 
//* implementam as op��es do menu.
//********************************************************
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
#include <vector>
#include <fstream>
#include "080928_01Livraria_01FComuns.cpp" 
              // Inclus�o das fun��es comuns
#include "080928_01Livraria_02ClasseLivro.cpp"
              // Inclus�o do ficheiro de classe
using namespace std; 


//*******************
// Declara��o de um vetor din�mico
vector<Livro> livros;



// Prot�tipos das fun��es
// Declara��o das fun��es - Cabe�alhos das fun��es
void mostraMenu();
char obtemEscolha(char, int);
bool processaEscolha(vector<Livro>*, char, bool,int );
void despedida();

void listarLivros(vector<Livro>);
void inserirLivro(vector<Livro>*);
void apagarLivro(vector<Livro>*);
void pesquisarLivro(vector<Livro>);
void atualizarLivro(vector<Livro>*);
void venderLivro(vector<Livro>*);
void reporLivro(vector<Livro>*);
void guardaFicheiro(vector<Livro> livros);
void lerFicheiro(vector<Livro> *livros);



//***********************************************
//* Fun��o "inicializaLivraria()"
//* Entrada(s):  livros.
//* Saida(s): n�o tem.
//************************************************
void inicializaLivraria()
{


} // Fim da fun��o "inicializaLivraria()"





//*******************************************************
//* Fun��o "mostraMenu()".
//* Entrada(s): n�o tem.
//* Saida(s): n�o tem.
//*******************************************************
void mostraMenu()
{
system("cls");   // Limpa o ecr� 
system("color A");
cout<<"***********************************"<<endl;
cout<<"*                                 *"<<endl;
cout<<"*          Livraria Gest          *"<<endl;
cout<<"*                                 *"<<endl;
cout<<"*    A. Inserir livro.            *"<<endl;
cout<<"*    B. Apagar livro.             *"<<endl;
cout<<"*    C. Pesquisar livro.          *"<<endl;
cout<<"*    D. Atualizar livro.          *"<<endl;
cout<<"*    E. Listar livro.             *"<<endl;
cout<<"*    F. Vender livro.             *"<<endl;
cout<<"*    G. Repor livro.              *"<<endl;
cout<<"*    H. Sair do programa.         *"<<endl;
cout<<"*                                 *"<<endl;
cout<<"***********************************"<<endl;
cout<<endl;	
} // Fim da fun��o "mostraMenu()".



//*********************************************
//* Fun��o "obtemEscolha()"
//* Entrada(s): char escolha 
//* Saida(s): char
//*********************************************
char obtemEscolha(char escolha, int numOp)
{
char ultimaOp = (char)(numOp+64); // "A" - ASCII 65	
cout<<"Qual a sua escolha (A-"<<ultimaOp<<")? ";
cin>>escolha; cin.ignore();	
return escolha;	
} // Fim do "obtemEscolha()".


//**********************************************
//*  Fun��o processaEscolha()"
//*    Entradas: vector<Livro>& livros, int numLivros,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
bool processaEscolha(vector<Livro> *livros,
                        char escolha, bool queroSair, int numOp)
{    
 switch(escolha)
 {
  case 'A': case 'a': inserirLivro(livros);
                      guardaFicheiro(*livros);
                      break;
  case 'B': case 'b': apagarLivro(livros);
                      guardaFicheiro(*livros);
                      break;
  case 'C': case 'c': pesquisarLivro(*livros); 
                      break;
  case 'D': case 'd': atualizarLivro(livros);
                      guardaFicheiro(*livros);
                      break;
  case 'E': case 'e': listarLivros(*livros);
                      break;
  case 'F': case 'f': venderLivro(livros);  
                      guardaFicheiro(*livros);
                      break;			
  case 'G': case 'g': reporLivro(livros);
                      guardaFicheiro(*livros);
                      break;			  	 
  case 'H': case 'h': queroSair = sairDoPrograma(queroSair);
                      break;
  default:	 
	  escolhaInvalida(numOp);
 } // Fim do "switch"

return queroSair;	
} // Fim da Fun��o "processaEscolha()".


//**********************************************
//*  Fun��o inserirLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void inserirLivro(vector<Livro> *livros)
{    
Livro* livro= new Livro;
livro->leTudoLivro();

int nLivros = livros->size();
cout<<"N�mero de livros: "<<nLivros<<"."<<endl;

livros->push_back(*livro); 
Livro::numLivros++;
//livros.insert(livros.begin()+nLivros, livro);
livros->at(nLivros).mostraTudoLivro();
nLivros = livros->size();
cout<<"N�mero de livros: "<<nLivros<<"."<<endl;
cout<< "Livro inserido com sucesso!"<<endl;
pausa();
} // Fim da fun��o "Inserirlivro()".

//**********************************************
//*  Fun��o apagarLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void apagarLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
cout<<"N�mero de livros: "<<nLivros<<"."<<endl;
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
  do {
   cout<<"Qual o livro a apagar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"N�mero de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
  } while (nLivro < 1 || nLivro > nLivros);

  livros->erase(livros->begin()+(nLivro-1)); 
  Livro::numLivros--;
  cout<<"Livro apagado com sucesso!"<<endl;
  pausa();
  }
 
  
} // Fim da fun��o "apagarlivro()".


//**********************************************
//*  Fun��o pesquisarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void pesquisarLivro(vector<Livro> livros)
{ 
int nLivro = 0;
int nLivros = livros.size();
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a pesquisar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"N�mero de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);
 
livros[nLivro-1].mostraTudoLivro();  
pausa();
}
} // Fim da fun��o "pesquisarlivro()".

//**********************************************
//*  Fun��o atualizarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void atualizarLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a atualizar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"N�mero de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);
(*livros)[nLivro-1].mostraTudoLivro();  
cout<<"Insira o novo pre�o: "<<endl;
(*livros)[nLivro-1].lePreco();
(*livros)[nLivro-1].mostraTudoLivro();
cout<< "Atualiza��o efetuada com sucesso!"<<endl; 
pausa();
}
} // Fim da fun��o "atualizarlivro()".

//**************************************************
//* Fun��o "listarLivros()"
//* Entrada(s): Livro livros[], int numLivros
//* Saida(s): n�o tem.
//**************************************************
void listarLivros(vector<Livro> livros)
{
int nLivros = livros.size();
cout<<"N�mero de livros: "<<nLivros<<"."<<endl;
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
cout<<"-> Listagem de livros: \n";
for(int cLivro=0; cLivro<nLivros; cLivro++)
	{
	cout<<"Livro "<< cLivro+1<<": ";	
    cout<<" -> "<<livros[cLivro].getTitulo();
    cout<<" -> "<<livros[cLivro].getAutor();
	cout<<" -> "<<livros[cLivro].getPreco()<<" euros";
	cout<<" -> "<<livros[cLivro].getNumUnidades();
	cout<<" unidades."<<endl;
    } // Fim do "for"
pausa();
}
} // Fim da fun��o "listarLivroes()".

//**********************************************
//*  Fun��o venderLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void venderLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a vender (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"N�mero de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);

(*livros)[nLivro-1].mostraTudoLivro();  
int uVendidas = 0, nUnidades=0;
nUnidades = (*livros)[nLivro-1].getNumUnidades(); 
cout<<"Quantas unidades vendeu? ";
cin >> uVendidas; cin.ignore();
nUnidades -= uVendidas;
(*livros)[nLivro-1].setNumUnidades(nUnidades); 
(*livros)[nLivro-1].mostraTudoLivro(); 
cout<< "Venda efetuada com sucesso!"<<endl;
pausa();
}
} // Fim da fun��o "venderlivro()".

//**********************************************
//*  Fun��o reporLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): n�o tem.
//**********************************************
void reporLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"N�o existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a repor (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"N�mero de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);

(*livros)[nLivro-1].mostraTudoLivro();  
int uRepostas = 0, nUnidades=0;
nUnidades = (*livros)[nLivro-1].getNumUnidades(); 
cout<<"Quantas unidades vai repor? ";
cin >> uRepostas; cin.ignore();
nUnidades += uRepostas;
(*livros)[nLivro-1].setNumUnidades(nUnidades); 
(*livros)[nLivro-1].mostraTudoLivro(); 
cout<< "Reposi��o efetuada com sucesso!"<<endl;
pausa();
}
} // Fim da fun��o "venderlivro()".



//****************************************************************
//* GravarFicheiro
//****************************************************************
void guardaFicheiro(vector<Livro> livros)
{
 string caminho="", nomeFicheiro="livraria.txt";
 string nomeCompleto = caminho + nomeFicheiro;
 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;

   // 4. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
   ofstream ficheiro;
   ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita
   
 if(!ficheiro)  {
 	cout<<"Ficheiro n�o foi aberto!"<<endl; 
 	pausa();
 }
 else {  
   // 4. Escrever mensagem
   int nLivros = livros.size(); 
   cout<<"N�mero de livros: "<<nLivros<<"."<<endl;
   if (nLivros <= 0) 
      {
      cout<<"N�o existem livros!"<<endl;
      pausa();	
      } 
   else
      {
      cout<<"-> Grava��o dos livros: \n";
      for(int cLivro=0; cLivro<nLivros; cLivro++)
	     ficheiro<<livros[cLivro];
   // 5. Fechar o ficheiro
   ficheiro.close();
   cout<<"Dados gravados com sucesso!"<<endl;  
   pausa();
  }
}
 
} // Fim da fun��o "guardaFicheiro()".
   
//****************************************************************
//* LerFicheiro
//****************************************************************
void lerFicheiro(vector<Livro> *livros)
{
 	
 string caminho="", nomeFicheiro="livraria.txt";
 string nomeCompleto = caminho + nomeFicheiro;
 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;   
   
 livros->erase(livros->begin(),livros->end());
 
 cout<<"-> Leitura dos livros: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
   ifstream ficheiroL;
   ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary
   
 if (ficheiroL.is_open ()) {  
 
   Livro livro;
    // 4. Leitura dos objetos
   int contaLivros = 0;
   while(ficheiroL>>livro && !ficheiroL.eof() )
    {
   	livros->push_back(livro);
    contaLivros++;
    cout<<"Livro "<<contaLivros<<": "<<endl;
    }
   // 5. Fechar o ficheiro
   ficheiroL.close();
   cout<<endl;
    }
}


