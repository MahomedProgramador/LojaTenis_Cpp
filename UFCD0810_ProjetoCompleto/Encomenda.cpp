#include <cstdio>
#include <cstdlib>
// Biblioteca de C++
#include <string>     // Classe "string"
#include <iostream>   // Objetos: "cin" e "cout"
#include <vector>

using namespace std;

const int DESLOCAMENTOIII = 3;

class Encomenda
{
	string status;
	string dataEntrega;
	float precoCusto;
	int quantidade;
	int idProduto;
	int idFornecedor;

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
	static int numEncomenda;

	void inicializaFornecedor()
	{
		status = ""; dataEntrega = ""; precoCusto = 0; quantidade = 0;
		idProduto = 0; idFornecedor = 0;
	}

	// 2.1.1 Construtor sem argumentos
	Encomenda()
	{
		status = "";  dataEntrega = ""; precoCusto = 0;quantidade = 0;
		idProduto = 0; idFornecedor = 0;
	}

	// 2.1.2 Construtor com 2 argumentos
	Encomenda(string s, string dE)
	{
		status = s; dataEntrega = dE; precoCusto = 0; quantidade = 0;
		idProduto = 0; idFornecedor = 0;
	}

	// 2.1.3 Construtor com 3 argumentos
	Encomenda(string s, string dE, float pC)
	{
		status = s; dataEntrega = dE; precoCusto = pC;
		quantidade = 0; idProduto = 0; idFornecedor = 0;
	}

	// 2.1.4 Construtor com 4 argumentos
	Encomenda(string s, string dE, float pC, int qt)
	{
		status = s; dataEntrega = dE; precoCusto = pC;
		quantidade = qt; idProduto = 0; idFornecedor = 0;
	}

	// 2.1.5 Construtor com 5 argumentos
	Encomenda(string s, string dE, float pC, int qt, int idP)
	{
		status = s; dataEntrega = dE; precoCusto = pC;
		quantidade = qt; idProduto = idP; idFornecedor = 0;
	}

	// 2.1.6 Construtor com 6 argumentos
	Encomenda(string s, string dE, float pC, int qt, int idP, int idF)
	{
		status = s; dataEntrega = dE; precoCusto = pC;
		quantidade = qt; idProduto = idP; idFornecedor = idF;
	}

	~Encomenda(){ }

	void setStatus(string s) { status = s; }
	void setDataEntrega(string dE) { dataEntrega = dE; }
	void setPrecoCusto(float pC) { precoCusto = pC; }
	void setQuantidade(int qt) { quantidade = qt; }
	void setIdProduto(int idP) { idProduto = idP; }
	void setIdFornecedor(int idF) { idFornecedor = idF; }

	string getStatus() { return status; }
	string getDataEntrega() { return dataEntrega; }
	float getPrecoCusto() { return precoCusto; }
	int getQuantidade() { return quantidade; }
	int getIdProduto() { return idProduto; }
	int getIdFornecedor() { return idFornecedor; }


	// 2.5 Funções de Leitura
	void leStatus()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual o status da encomenda? ";
		cin.getline(letras, sizeof(letras), '\n');
		setStatus(string(letras));
	}

	void leDataEntrega()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';

		cout << "Qual a data de entrega da encomenda? ";
		cin.getline(letras, sizeof(letras), '\n');
		setDataEntrega(string(letras));
	}
	
	void lePrecoCusto()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Qual o preço de custo dos ténis (XX,XX)? "; // Deve colocar ","
		cin.getline(letras, sizeof(letras), '\n');
		setPrecoCusto(atof(letras));
	}

	void leQuantidade()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Qual a quantidade a encomendar? ";
		cin.getline(letras, sizeof(letras), '\n');
		setQuantidade(atoi(letras));
	}

	void leIdProduto()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Qual o id dos ténis a encomendar? ";
		cin.getline(letras, sizeof(letras), '\n');
		setIdProduto(atoi(letras));
	}

	void leIdFornecedor()
	{
		const int MAXCHARS = 40;
		char letras[MAXCHARS];
		for (int cLetra = 0; cLetra < MAXCHARS; cLetra++)
			letras[cLetra] = '\0';
		cout << "Qual o id do fornecedor a pedir a encomenda? ";
		cin.getline(letras, sizeof(letras), '\n');
		setIdFornecedor(atoi(letras));
	}

	void leTudoEncomenda()
	{
		leStatus(); leDataEntrega(); lePrecoCusto();
		leQuantidade(); leIdProduto(); leIdFornecedor();

	}

	void mostraStatus()
	{
		cout << "Status: " << getStatus() << "." << endl;
	}

	void mostraDataEntrega()
	{
		cout << "Data entrega: " << getDataEntrega() << "." << endl;
	}

	void mostraPrecoCusto()
	{
		cout << "Preço custo: " << getPrecoCusto() << "." << endl;
	}

	void mostraQuantidade()
	{
		cout << "Quantidade: " << getQuantidade() << "." << endl;
	}

	void mostraIdProduto()
	{
		cout << "Id Produto: " << getIdProduto() << "." << endl;
	}

	void mostraIdFornecedor()
	{
		cout << "Fornecedor: " << getIdFornecedor() << "." << endl;
	}

	void mostraTudoEncomenda()
	{
		mostraStatus(); mostraDataEntrega(); mostraPrecoCusto();
		mostraQuantidade(); mostraIdProduto(); mostraIdFornecedor();
	}

	//*************************************************************************************
//* Redefinição do operador ">>"
//**************************************************************************************
	friend istream& operator>> (istream& is, Encomenda& enc)
	{
		char letra = '\0';

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME; cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			enc.setStatus(enc.desencripta(string(texto), DESLOCAMENTOIII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			enc.setDataEntrega(enc.desencripta(string(texto), DESLOCAMENTOIII));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, enc.desencriptaII(texto, DESLOCAMENTOIII));
			enc.setPrecoCusto(atof(texto));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++) texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, enc.desencriptaII(texto, DESLOCAMENTOIII));
			enc.setQuantidade(atoi(texto));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, enc.desencriptaII(texto, DESLOCAMENTOIII));
			enc.setIdProduto(atoi(texto));
		}

		{
			const int MAXNOME = 40; char texto[MAXNOME];
			for (int cLetra = 0; cLetra < MAXNOME;cLetra++)
				texto[cLetra] = '\0';
			is.getline(texto, MAXNOME, '\n');
			strcpy_s(texto, enc.desencriptaII(texto, DESLOCAMENTOIII));
			enc.setIdFornecedor(atoi(texto));
		}

		return is;
	}

	//*************************************************************************************
	//* Redefinição do operador "<<"
	//**************************************************************************************
	friend ostream& operator<< (ostream& os, Encomenda& enc)
	{
		os << enc.encripta(enc.getStatus(), DESLOCAMENTOIII) << endl;
		os << enc.encripta(enc.getDataEntrega(), DESLOCAMENTOIII) << endl;
		os << enc.encripta(to_string(enc.getPrecoCusto()), DESLOCAMENTOIII) << endl;
		os << enc.encripta(to_string(enc.getQuantidade()), DESLOCAMENTOIII) << endl;
		os << enc.encripta(to_string(enc.getIdProduto()), DESLOCAMENTOIII) << endl;
		os << enc.encripta(to_string(enc.getIdFornecedor()), DESLOCAMENTOIII) << endl;

		return os;
	}
	// Outras Funções
	static float obtemPrecoComIVAEncomenda(float psi)
	{
		const float TIVAENCOMENDA = 0.23;
		return (psi * (1 + TIVAENCOMENDA));
	}

	static float obtemPrecoSemIVAEncomenda(float pci)
	{
		const float TIVAENCOMENDA = 0.23;
		return (pci / (1 + TIVAENCOMENDA));
	}

	void mostraPrecoEncomenda()
	{
		cout << "Preço s/IVA: " << getPrecoCusto() * getQuantidade() << " euros." << endl;
		cout << "Preço c/IVA: " << obtemPrecoComIVAEncomenda(getPrecoCusto() * getQuantidade());
		cout << " euros." << endl;
	}

};