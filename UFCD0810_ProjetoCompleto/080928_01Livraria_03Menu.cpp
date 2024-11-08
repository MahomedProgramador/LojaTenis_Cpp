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
//* Ficheiro: 080928_01Livraria_03Menus.cpp
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
//************************************************************
//* http://www.dontpad.com/Prog05/0811_Livraria
//*******************************************************
//* Criação de Bibliotecas
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11
//*******************************************************
//********************************************************
//* Este ficheiro contém todas as funções que 
//* implementam as opções do menu.
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
              // Inclusão das funções comuns
#include "080928_01Livraria_02ClasseLivro.cpp"
              // Inclusão do ficheiro de classe
using namespace std; 


//*******************
// Declaração de um vetor dinâmico
vector<Livro> livros;



// Protótipos das funções
// Declaração das funções - Cabeçalhos das funções
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
//* Função "inicializaLivraria()"
//* Entrada(s):  livros.
//* Saida(s): não tem.
//************************************************
void inicializaLivraria()
{


} // Fim da função "inicializaLivraria()"





//*******************************************************
//* Função "mostraMenu()".
//* Entrada(s): não tem.
//* Saida(s): não tem.
//*******************************************************
void mostraMenu()
{
system("cls");   // Limpa o ecrã 
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
} // Fim da função "mostraMenu()".



//*********************************************
//* Função "obtemEscolha()"
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
//*  Função processaEscolha()"
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
} // Fim da Função "processaEscolha()".


//**********************************************
//*  Função inserirLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void inserirLivro(vector<Livro> *livros)
{    
Livro* livro= new Livro;
livro->leTudoLivro();

int nLivros = livros->size();
cout<<"Número de livros: "<<nLivros<<"."<<endl;

livros->push_back(*livro); 
Livro::numLivros++;
//livros.insert(livros.begin()+nLivros, livro);
livros->at(nLivros).mostraTudoLivro();
nLivros = livros->size();
cout<<"Número de livros: "<<nLivros<<"."<<endl;
cout<< "Livro inserido com sucesso!"<<endl;
pausa();
} // Fim da função "Inserirlivro()".

//**********************************************
//*  Função apagarLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void apagarLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
cout<<"Número de livros: "<<nLivros<<"."<<endl;
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
  pausa();	
  } 
else
  {
  do {
   cout<<"Qual o livro a apagar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"Número de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
  } while (nLivro < 1 || nLivro > nLivros);

  livros->erase(livros->begin()+(nLivro-1)); 
  Livro::numLivros--;
  cout<<"Livro apagado com sucesso!"<<endl;
  pausa();
  }
 
  
} // Fim da função "apagarlivro()".


//**********************************************
//*  Função pesquisarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void pesquisarLivro(vector<Livro> livros)
{ 
int nLivro = 0;
int nLivros = livros.size();
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a pesquisar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"Número de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);
 
livros[nLivro-1].mostraTudoLivro();  
pausa();
}
} // Fim da função "pesquisarlivro()".

//**********************************************
//*  Função atualizarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void atualizarLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a atualizar (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"Número de livros entre 1 e "<<nLivros<<"."<<endl;
      cout<< "Prima qualquer tecla para continuar ... ";
      cin.get(); 		
	  }
} while (nLivro < 1 || nLivro > nLivros);
(*livros)[nLivro-1].mostraTudoLivro();  
cout<<"Insira o novo preço: "<<endl;
(*livros)[nLivro-1].lePreco();
(*livros)[nLivro-1].mostraTudoLivro();
cout<< "Atualização efetuada com sucesso!"<<endl; 
pausa();
}
} // Fim da função "atualizarlivro()".

//**************************************************
//* Função "listarLivros()"
//* Entrada(s): Livro livros[], int numLivros
//* Saida(s): não tem.
//**************************************************
void listarLivros(vector<Livro> livros)
{
int nLivros = livros.size();
cout<<"Número de livros: "<<nLivros<<"."<<endl;
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
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
} // Fim da função "listarLivroes()".

//**********************************************
//*  Função venderLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void venderLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a vender (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"Número de livros entre 1 e "<<nLivros<<"."<<endl;
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
} // Fim da função "venderlivro()".

//**********************************************
//*  Função reporLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void reporLivro(vector<Livro> *livros)
{ 
int nLivro = 0;
int nLivros = livros->size();
if (nLivros <= 0) 
  {
  cout<<"Não existem livros!"<<endl;
  pausa();	
  } 
else
  {
do {
   cout<<"Qual o livro a repor (1-"<<nLivros<<")? ";
   cin>> nLivro; cin.ignore();
   if (nLivro < 1 || nLivro > nLivros)
      {
      cout<<"Número de livros entre 1 e "<<nLivros<<"."<<endl;
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
cout<< "Reposição efetuada com sucesso!"<<endl;
pausa();
}
} // Fim da função "venderlivro()".



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
 	cout<<"Ficheiro não foi aberto!"<<endl; 
 	pausa();
 }
 else {  
   // 4. Escrever mensagem
   int nLivros = livros.size(); 
   cout<<"Número de livros: "<<nLivros<<"."<<endl;
   if (nLivros <= 0) 
      {
      cout<<"Não existem livros!"<<endl;
      pausa();	
      } 
   else
      {
      cout<<"-> Gravação dos livros: \n";
      for(int cLivro=0; cLivro<nLivros; cLivro++)
	     ficheiro<<livros[cLivro];
   // 5. Fechar o ficheiro
   ficheiro.close();
   cout<<"Dados gravados com sucesso!"<<endl;  
   pausa();
  }
}
 
} // Fim da função "guardaFicheiro()".
   
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


