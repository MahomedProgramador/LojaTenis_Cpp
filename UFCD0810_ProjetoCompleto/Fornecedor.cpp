#include "Fornecedores.h"
using namespace std;
// DESLOCAMENTO ENCRIPTAÇÃO
const int DESLOCAMENTOII = 3;

class Fornecedor
{
private:
	string nome;
	string email;
	string representante;
	string dataInicioRelacao;
	string dadosBancarios;
	int Nif;


	//****************************************************
//* Função encripta()
//****************************************************
	string  encripta(string mensagemO, int desl)
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemO.c_str());

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < mensagemO.length(); cLetra++)
		{
			int valor = (int)mensagem[cLetra] + desl;
			if (((valor) > 90 && isupper(mensagem[cLetra]))
				|| ((valor) > 122 && islower(mensagem[cLetra]))
				)
				valor = valor - 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
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
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE.c_str());

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < mensagemE.length(); cLetra++)
		{
			int valor = (int)mensagem[cLetra] - desl;
			if (((valor) < 65 && isupper(mensagem[cLetra]))
				|| ((valor) < 97 && islower(mensagem[cLetra]))
				)

				valor = valor + 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
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
	char* desencriptaII(char mensagemE[], int desl)
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE);

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < strlen(mensagemE); cLetra++)
		{
			int valor = (int)mensagem[cLetra] - desl;
			if (((valor) < 65 && isupper(mensagem[cLetra]))
				|| ((valor) < 97 && islower(mensagem[cLetra]))
				)

				valor = valor + 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
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
	void  desencriptaIII(char mensagemE[], int desl, char mensagemO[])
	{
		const int MAXCHARS = 100;
		char mensagem[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			mensagem[cLetra] = '\0';

		strcpy_s(mensagem, mensagemE);

		//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
		//    mensagem[cLetra]=toupper(mensagem[cLetra]);

		for (int cLetra = 0; cLetra < strlen(mensagemE); cLetra++)
		{
			int valor = (int)mensagem[cLetra] - desl;
			if (((valor) < 65 && isupper(mensagem[cLetra]))
				|| ((valor) < 97 && islower(mensagem[cLetra]))
				)

				valor = valor + 26;
			if (mensagem[cLetra] == '.')
				mensagem[cLetra] = '.';
			else if (!isalpha(mensagem[cLetra]))
				mensagem[cLetra] = mensagemE[cLetra];
			else
				mensagem[cLetra] = valor;
		}
		//cout<<mensagem;	
		strcpy_s(mensagemO, sizeof(mensagemO), mensagem);
		//strcpy_s(destino, sizeof(destino), origem);
	}

	public:
		static int numFornecedores;

	// 2. Funções
	// 2.0 Funções de inicialização
	void inicializaFornecedor()
	{
		nome = ""; email = ""; representante = ""; Nif = 0; 
		dataInicioRelacao = ""; dadosBancarios = "";
	}

	// 2.1.1 Construtor sem argumentos
	Fornecedor()
	{
		nome = ""; email = ""; representante = ""; Nif = 0;
		dataInicioRelacao = ""; dadosBancarios = "";
	}

	// 2.1.2 Construtor com 2 argumentos
	Fornecedor(string n, string e)
	{
		nome = n; email = e; representante = ""; Nif = 0;
		dataInicioRelacao = ""; dadosBancarios = "";
	}

	// 2.1.3 Construtor com 3 argumentos
	Fornecedor(string n, string e, string r)
	{
		nome = n; email = e; representante = r; Nif = 0;
		dataInicioRelacao = ""; dadosBancarios = "";
	}

	// 2.1.4 Construtor com 4 argumentos
	Fornecedor(string n, string e, string r, int nif)
	{
		nome = n; email = e; representante = r; Nif = nif;
		dataInicioRelacao = ""; dadosBancarios = "";
	}

	// 2.1.5 Construtor com 5 argumentos
	Fornecedor(string n, string e, string r, int nif, string di)
	{
		nome = n; email = e; representante = r; Nif = nif;
		dataInicioRelacao = di; dadosBancarios = "";
	}

	// 2.1.6 Construtor com todos os argumentos
	Fornecedor(string n, string e, string r, int nif, string di, float db)
	{
		nome = n; email = e; representante = r; Nif = nif;
		dataInicioRelacao = di; dadosBancarios = db;
	}


	// 2.2 Destrutor
//     Código que é executado antes de um objeto
//     sair de memória.
	~Fornecedor() {
	}

	// 2.3 Setters
	//     Permitem a atribuição de valores a cada 
	//     dado de um objeto.
	void setNome(string n) { nome = n; }
	void setEmail(string e) { email= e; }
	void setRepresentante(string r) { representante = r; }
	void setNif(int n) { Nif = n; }
	void setDataInicioRelacao(string di) { dataInicioRelacao = di; }
	void setDadosBancarios(string db) { dadosBancarios = db; }

	// 2.4 Getters
	//     Permitem a obtenção do valor de  cada 
	//     dado de um objeto.
	string getNome() { return nome; }
	string getEmail() { return email; }
	string getRepresentante() { return representante; }
	int getNif() { return Nif; }
	string getDataInicioRelacao() { return dataInicioRelacao; }
	string getDadosBancarios() { return dadosBancarios; }

	// 2.5 Funções de Leitura
	void leNome()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual o nome do fornecedor? ";
		cin.getline(letras, sizeof(letras), '\n');
		setNome(string(letras));
	}

	// 2.5 Funções de Leitura
	void leEmail()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual o email do fornecedor?";
		cin.getline(letras, sizeof(letras), '\n');
		setEmail(string(letras));
	}

	// 2.5 Funções de Leitura
	void leRepresentante()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual o nome do representante? ";
		cin.getline(letras, sizeof(letras), '\n');
		setRepresentante(string(letras));
	}

	void leNif()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Qual o nif do fornecedor? ";
		cin.getline(letras, sizeof(letras), '\n');
		setNif(atoi(letras));
	}

	void leDataInicioRelacao()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual a data de incio da relação? ";
		cin.getline(letras, sizeof(letras), '\n');
		setDataInicioRelacao(string(letras));
	}

	void leDadosBancarios()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Quais os dados bancários? ";
		cin.getline(letras, sizeof(letras), '\n');
		setDadosBancarios(string(letras));
	}

	void leTudoFornecedor()
	{
		leNome(); leEmail(); leRepresentante(); 
		leNif(); leDataInicioRelacao(); leDadosBancarios();
	}

	// 2.6 Funções de Escrita
	void mostraNome()
	{
		cout << "Nome: " << getNome() << "." << endl;
	}

	void mostraEmail()
	{
		cout << "Email " << getEmail() << "." << endl;
	}

	void mostraRepresentante()
	{
		cout << "Representante: " << getRepresentante() << "." << endl;
	}

	void mostraNif()
	{
		cout << "Nif: " << getNif() << "." << endl;
	}

	void mostraDadosBancarios()
	{
		cout << "Dados bancários: " << getDadosBancarios() << endl;

	}

	void mostraTudoFornecedor()
	{
		mostraNome(); mostraEmail(); mostraRepresentante();
		mostraNif(); mostraDadosBancarios();
	}


	//*************************************************************************************
	//* Redefinição do operador ">>"
	//**************************************************************************************
	friend istream& operator>> (istream& is, Fornecedor& forn)
	{
		char letra = '\0';

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			forn.setNome(forn.desencripta(string(texto), DESLOCAMENTOII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			forn.setEmail(forn.desencripta(string(texto), DESLOCAMENTOII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			forn.setRepresentante(forn.desencripta(string(texto), DESLOCAMENTOII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, forn.desencriptaII(texto, DESLOCAMENTOII));
			forn.setNif(atoi(texto));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			forn.setDataInicioRelacao(forn.desencripta(string(texto), DESLOCAMENTOII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			forn.setDadosBancarios(forn.desencripta(string(texto), DESLOCAMENTOII));
		}

		return is;

	}

	//*************************************************************************************
	//* Redefinição do operador "<<"
	//**************************************************************************************
	friend ostream& operator<< (ostream& os, Fornecedor& forn)
	{
		os << forn.encripta(forn.getNome(), DESLOCAMENTOII) << endl;
		os << forn.encripta(forn.getEmail(), DESLOCAMENTOII) << endl;
		os << forn.encripta(forn.getRepresentante(), DESLOCAMENTOII) << endl;
		os << forn.encripta(to_string(forn.getNif()), DESLOCAMENTOII) << endl;
		os << forn.encripta(forn.getDataInicioRelacao(), DESLOCAMENTOII) << endl;
		os << forn.encripta(forn.getDadosBancarios(), DESLOCAMENTOII) << endl;
	

		return os;
	}

	};