
#include <cstdio>
#include <cstdlib>
#include <clocale>
#include <cstring>
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <iomanip>    // "setprecision()".
#include <vector>
using namespace std; 

// DESLOCAMENTO ENCRIPTAÇÃO
const int DESLOCAMENTO = 3;

// Definição da classe
class Tenis
{
 private:   // Dados devem ser privados	
    //*   - código do livro -> posição no vetor
	string marca;
	string modelo;
	string cor;
    float preco;
	float tamanho;
    int numArmario;
    char letraPrateleira;
    int numUnidades;
    int indiceQuebra;
	bool antiDerrapante;    
  
//****************************************************
//* Função encripta()
//****************************************************
string  encripta(string mensagemO, int desl)
{
const int MAXCHARS = 100;	
char mensagem[MAXCHARS];
for(int cLetra=0; cLetra<MAXCHARS; cLetra++) 
                         mensagem[cLetra]='\0';
                         
strcpy_s(mensagem,mensagemO.c_str());
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)	
   {
   	int valor = (int)mensagem[cLetra] + desl;
   	if ( ((valor) > 90 && isupper(mensagem[cLetra]))
	    || ((valor) > 122 && islower(mensagem[cLetra]))
	   )
	   valor = valor - 26;
	if (mensagem[cLetra]=='.')
	   mensagem[cLetra] ='.';
    else if (!isalpha(mensagem[cLetra]))
       mensagem[cLetra] = mensagem[cLetra];
	else   
   	   mensagem[cLetra] = valor; 
   }
//cout<<mensagem;	
return mensagem;	
}

//****************************************************
//* Função desencripta()
//****************************************************
string  desencripta(string mensagemE, int desl)
{
const int MAXCHARS = 100;	
char mensagem[MAXCHARS];
for(int cLetra=0; cLetra<MAXCHARS; cLetra++) 
                         mensagem[cLetra]='\0';
                         
strcpy_s(mensagem,mensagemE.c_str());
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

for(int cLetra=0; cLetra< mensagemE.length(); cLetra++)	
   {
   	int valor = (int)mensagem[cLetra] - desl;
   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
	    || ((valor) < 97 && islower(mensagem[cLetra]))
	   )
	   
   	   valor = valor + 26;
	if (mensagem[cLetra]=='.')
	   mensagem[cLetra] ='.';
    else if (!isalpha(mensagem[cLetra]))
       mensagem[cLetra] = mensagemE[cLetra];
	else   
   	   mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
return mensagem;	
}

//****************************************************
//* Função desencripta()
//****************************************************
char*  desencriptaII(char mensagemE[], int desl)
{
const int MAXCHARS = 100;	
char mensagem[MAXCHARS];
for(int cLetra=0; cLetra<MAXCHARS; cLetra++) 
                         mensagem[cLetra]='\0';
                         
strcpy_s(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
   {
   	int valor = (int)mensagem[cLetra] - desl;
   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
	    || ((valor) < 97 && islower(mensagem[cLetra]))
	   )
	   
   	   valor = valor + 26;
	if (mensagem[cLetra]=='.')
	   mensagem[cLetra] ='.';
    else if (!isalpha(mensagem[cLetra]))
       mensagem[cLetra] = mensagemE[cLetra];
	else   
   	   mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
return mensagem;	
}    

//****************************************************
//* Função desencripta()
//****************************************************
void  desencriptaIII(char mensagemE[], int desl,char mensagemO[])
{
const int MAXCHARS = 100;	
char mensagem[MAXCHARS];
for(int cLetra=0; cLetra<MAXCHARS; cLetra++) 
                         mensagem[cLetra]='\0';
                         
strcpy_s(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
   {
   	int valor = (int)mensagem[cLetra] - desl;
   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
	    || ((valor) < 97 && islower(mensagem[cLetra]))
	   )
	   
   	   valor = valor + 26;
	if (mensagem[cLetra]=='.')
	   mensagem[cLetra] ='.';
	else if (!isalpha(mensagem[cLetra]))
       mensagem[cLetra] = mensagemE[cLetra];   
	else   
   	   mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
strcpy_s(mensagemO, sizeof(mensagemO),mensagem);
//strcpy_s(destino, sizeof(destino), origem);
}    

   public:    // Funções devem ser públicas 
    // Dados estáticos
    static int numTenis;
    
    // 2. Funções
    // 2.0 Funções de inicialização
	void inicializaTenis()
	{
		marca = ""; modelo = ""; tamanho = 0; preco = 0; cor = "";
		numArmario = 0; letraPrateleira = '\0'; numUnidades = 0;
		indiceQuebra = 0; antiDerrapante = false;
	}
    // 2.1  Funções construtoras
    //      Servem para inicializar os dados de cada objeto.
    
    // 2.1.1 Construtor sem argumentos
	Tenis()
	{
		marca = ""; modelo = ""; tamanho = 0; preco = 0; cor = "";
		numArmario = 0; letraPrateleira = '\0'; numUnidades = 0;
		indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.2 Construtor com 2 argumentos
	Tenis(string mrc, string mdl)
	{
		marca = mrc; modelo = mdl; tamanho = 0; preco = 0;
		cor = ""; numArmario = 0; letraPrateleira = '\0';
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}
  
	// 2.1.3 Construtor com 3 argumentos
	Tenis(string mrc, string mdl, float t)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = 0; cor = ""; numArmario = 0; letraPrateleira = '\0';
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.4 Construtor com 4 argumentos
	Tenis(string mrc, string mdl, float t, float p)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = p; cor = ""; numArmario = 0; letraPrateleira = '\0';
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.5 Construtor com 5 argumentos
	Tenis(string mrc, string mdl, float t, float p, string c)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = p; cor = c; numArmario = 0; letraPrateleira = '\0';
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.6 Construtor com 6 argumentos
	Tenis (string mrc, string mdl, float t, float p, string c, int nA)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = p; cor = c; numArmario = nA; letraPrateleira = '\0';
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.7 Construtor com 7 argumentos
	Tenis(string mrc, string mdl, float t, float p, string c, int nA,
		char l)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = p; cor = c; numArmario = nA; letraPrateleira = l;
		numUnidades = 0; indiceQuebra = 0; antiDerrapante = false;
	}

	// 2.1.8 Construtor com todos os argumentos
	Tenis(string mrc, string mdl, float t, float p, string c, int nA,
		char l, int nU, int iQ, bool a)
	{
		marca = mrc; modelo = mdl; tamanho = t;
		preco = p; cor = c; numArmario = nA; letraPrateleira = l;
		numUnidades = nU; indiceQuebra = iQ; antiDerrapante = a;
	}

	 
	// 2.2 Destrutor
	//     Código que é executado antes de um objeto
	//     sair de memória.
    ~Tenis() {
	         }
	
	// 2.3 Setters
	//     Permitem a atribuição de valores a cada 
	//     dado de um objeto.
	void setMarca(string m) { marca = m;}
	void setModelo(string m) { modelo = m;}
	void setCor(string c) { cor = c;}
	void setTamanho(float t) { tamanho = t; }
	void setPreco  (float p)   { preco = p;}
	void setNumArmario(int na) { numArmario = na;}
	void setLetraPrateleira  (char lp)   
	                           { letraPrateleira = lp;}
	void setNumUnidades(int nu)   
	                           { numUnidades = nu;}	
	void setIndiceQuebra(int iq)   
	                           { indiceQuebra = iq;}		
	void setAntiDerrapante(bool a)
								{ antiDerrapante = a; }
	         
	// 2.4 Getters
	//     Permitem a obtenção do valor de  cada 
	//     dado de um objeto.
	string getMarca  ()		  { return marca;}
	string getModelo ()		  { return modelo;}
	string getCor    ()		  { return cor; }
	float getTamanho ()		  { return tamanho; }
	float getPreco  ()        { return preco;}
	int getNumArmario()       { return numArmario;}
	char getLetraPrateleira() { return letraPrateleira;}
	int getNumUnidades()      { return numUnidades;}
	int getIndiceQuebra()     { return indiceQuebra;}
	bool getAntiDerrapante()  { return antiDerrapante; }
	
	// 2.5 Funções de Leitura
	void leMarca()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout << "Qual a marca dos ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setMarca(string(letras));
      }
	  	
	void leModelo()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<< "Qual o modelo dos ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setModelo(string(letras));
      }
	  	
	void leCor()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual a cor dos ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCor(string(letras));
      }
	  	
	void leTamanho()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout << "Qual o tamanho dos ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setTamanho(atof(letras));  
	     // atoi() - ascii to integer - converte
		 //          array de chars para inteiro 
      }
	  	
	void lePreco()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o preço dos ténis (XX,XX)? "; // Deve colocar ","
	  cin.getline(letras, sizeof(letras),'\n');
	  setPreco(atof(letras));
	      // atof() - ascii to float- converte 
	      //          array de chars para float
      }	  	  	  	
	  		  	
	void leNumArmario()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o número do armário dos ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumArmario(atoi(letras));
      }	  	
	  
	void leLetraPrateleira()
	  {
      char letra = '\0';	
	  cout<<"Qual a letra da prateleira? ";
	  cin>>letra; 	  
	  if (isalpha(letra)) letra=toupper(letra); 
	  cin.ignore();  // fflush(stdin);
	  setLetraPrateleira(letra);
      }			

	void leNumUnidades()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Quantas unidades existem destes ténis? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumUnidades(atoi(letras));
      }	 
	  
	void leIndiceQuebra()
	  {
	  const int MAXCHARS = 40;	
	  char letras[MAXCHARS];
	  for (int cLetra=0; cLetra<MAXCHARS; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o índice de quebra? ";
	  cin.getline(letras, sizeof(letras),'\n');				
	  setIndiceQuebra(atoi(letras));
      }	 	

	void leAntiDerrapante()
	{
		bool nao_derrapam = false;
		char letra = '\0';
		cout << "Os ténis são AntiDerrapantes (S/N)? ";
		cin >> letra;

		if (isalpha(letra)) letra = toupper(letra);
		cin.ignore();  // fflush(stdin);

		if (letra == 'S')
			nao_derrapam = true;

		setAntiDerrapante(nao_derrapam);
	}
	
	void leTudoTenis()
	  {
	  leMarca(); leModelo(); leCor();
	  leTamanho(); lePreco(); leNumArmario();
	  leLetraPrateleira(); leNumUnidades();	
	  leIndiceQuebra(); leAntiDerrapante();
	  }
	  
	// 2.6 Funções de Escrita
	void mostraMarca()
	   { cout<< "Marca: "<<getMarca()<<"."<<endl; }  

	void mostraModelo()
	   { cout<< "Modelo "<<getModelo()<<"."<<endl; } 
	   
	void mostraCor()
	   { cout<< "Cor: "<<getCor()<<"."<<endl; }    	

	void mostraTamanho()
	   { cout<< "Tamanho: "<<getTamanho()<<"."<<endl; } 

	void mostraPreco()
	   { 
	   cout<< "Preço s/IVA: "<<getPreco()<<" euros."<<endl;
	   cout<< "Preço c/IVA: "<<obtemPrecoComIVA(getPreco());
	   cout<<" euros."<<endl;
	   } 

	void mostraNumArmario()
	{ cout<< "N.º Armário: "<<getNumArmario()<<"."<<endl; } 

	void mostraLetraPrateleira()
	{ cout<<"Prateleira: "<<getLetraPrateleira()<<"."<<endl;}

	void mostraNumUnidades()
	{ cout<<"N.º Unidades: "<<getNumUnidades()<<"."<<endl; } 

	void mostraIndiceQuebra()
	{ cout<<"Índice quebra: "<<getIndiceQuebra()<<"."<<endl;}

	void mostraAntiDerrapante()
	{
		if (getAntiDerrapante() == true)
			cout << "Não derrapam" << "." << endl;
		else
			cout << "Derrapam" << "." << endl;
	}

    void mostraTudoTenis()
       { mostraMarca(); mostraModelo(); mostraCor();
         mostraTamanho(); mostraPreco(); mostraNumArmario();
         mostraLetraPrateleira(); mostraNumUnidades();
		 mostraIndiceQuebra(); mostraAntiDerrapante();
       }
       
    // Outras Funções
	static float obtemPrecoComIVA(float psi)
	  {
	  const float TIVATENIS = 0.23;
	  return (psi*(1+TIVATENIS));	
	  }
	   
	static float obtemPrecoSemIVA(float pci)
	  {
	  const float TIVATENIS = 0.23;
	  return (pci/(1+TIVATENIS));	
	  }  
	  
//*************************************************************************************
//* Redefinição do operador ">>"
//**************************************************************************************
friend istream& operator>> (istream& is, Tenis& ten)
{
  	char letra='\0';
	
    { 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra < MAXNOME; cLetra++) 
	                            texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	ten.setMarca(ten.desencripta(string(texto), DESLOCAMENTO));
    }
	
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++) texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	ten.setModelo(ten.desencripta(string(texto),DESLOCAMENTO));
	}

	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++) texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	ten.setCor(ten.desencripta(string(texto),DESLOCAMENTO));
    }

    { 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++)
	                                     texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setTamanho(atof(texto));
	}


   
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++) texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setPreco(atof(texto));
	}                   
	 
					
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++)
	                                     texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setNumUnidades(atoi(texto));
	}										 	
     
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++)
	                                     texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setIndiceQuebra(atoi(texto));
	}	                 
					  
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++)
	                                     texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setNumArmario(atoi(texto));
	}					  
					  		
	{ 
	const int MAXNOME = 40; char texto[MAXNOME];
	for(int cLetra= 0; cLetra<MAXNOME;cLetra++)
	                                     texto[cLetra]= '\0';
	is.getline(texto, MAXNOME, '\n');
	strcpy_s(texto,ten.desencriptaII(texto,DESLOCAMENTO) );
    ten.setLetraPrateleira(atoi(texto));
	}	  
	
	{
		char letra = '\0';
		is.get(letra);
		if (isalpha(letra))
			letra = toupper(letra);

		if (letra == 'S')
			ten.setAntiDerrapante(true);
		else
			ten.setAntiDerrapante(false);
	}

    is.ignore(); 	
    return is;

}

//*************************************************************************************
//* Redefinição do operador "<<"
//**************************************************************************************
friend ostream& operator<< (ostream& os, Tenis& ten)
{
	os << ten.encripta(ten.getMarca(),DESLOCAMENTO)<<endl;  	
	os << ten.encripta(ten.getModelo(),DESLOCAMENTO)<<endl;
	os << ten.encripta(ten.getCor(),DESLOCAMENTO)<<endl;
	os << ten.encripta(to_string(ten.getTamanho()),DESLOCAMENTO)<<endl;  	
	os << ten.encripta(to_string(ten.getPreco()),DESLOCAMENTO)<<endl;
	os << ten.encripta(to_string(ten.getNumUnidades()),DESLOCAMENTO)<<endl;
	os << ten.encripta(to_string(ten.getIndiceQuebra()),DESLOCAMENTO)<<endl;
	os << ten.encripta(to_string(ten.getNumArmario()),DESLOCAMENTO)<<endl;  	
	os << ten.encripta(to_string(ten.getLetraPrateleira()),DESLOCAMENTO)<<endl;
	os << ten.encripta(to_string(ten.getAntiDerrapante()), DESLOCAMENTO) << endl;
	 	

    return os;
}  

}; // Fim da classe


