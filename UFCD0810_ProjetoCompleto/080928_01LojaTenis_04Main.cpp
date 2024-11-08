
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
#include "080928_01Tenis_01FComuns.cpp" 
              // Inclusão das funções comuns
#include "080928_01Tenis_02ClasseTenis.cpp"
#include "Fornecedor.cpp"
#include "Encomenda.cpp"
              // Inclusão do ficheiro de classe
using namespace std; 


// Declaração e inicialização dos dados estaticos
int Tenis::numTenis = 0;
int Fornecedor::numFornecedores = 0;
int Encomenda::numEncomenda = 0;


// Dados globais
const int MAXOPCOES = 9;
//extern vector<Livro> livros;

vector<Tenis> listaTenis;
vector<Fornecedor> fornecedores;
vector<Encomenda> encomendas;

// Protótipos das funções
// Declaração das funções - Cabeçalhos das funções
void mostraMenuTenis();
char obtemEscolha(char, int);
bool processaEscolhaTenis(vector<Tenis>*, char, bool, int);
void escolhaInvalida(int );
void despedida();
void pausa();
bool sairDoPrograma(bool );
void listarTenis(vector<Tenis>);
void inserirTenis(vector<Tenis>*);
void apagarTenis(vector<Tenis>*);
void pesquisarTenis(vector<Tenis>);
void atualizarTenis(vector<Tenis>*);
void venderTenis(vector<Tenis>*);
void reporTenis(vector<Tenis>*);
void guardaFicheiro(vector<Tenis> listaTenis);
void lerFicheiro(vector<Tenis>* listaTenis);

void guardaFicheiroFornecedor(vector<Fornecedor> fornecedores);
void lerFicheiroFornecedor(vector<Fornecedor>* fornecedores);
void mostraMenuFornecedor();
void mainFornecedor();
char obtemEscolhaFornecedor(char, int);
bool processaEscolhaFornecedor(vector<Fornecedor>*,char, bool, int);
void inserirFornecedor(vector<Fornecedor>*);
void apagarFornecedor(vector<Fornecedor>*);
void pesquisarFornecedor(vector<Fornecedor>);
void atualizarFornecedor(vector<Fornecedor>*);
void listarFornecedores(vector<Fornecedor>);

void mostraMenuPrincipal();
bool processaEscolhaPrincipal(char escolha, bool queroSair, int numOp);
void MainTenis();

void mostraMenuEncomenda();
void mainEncomenda();
void inserirEncomenda(vector<Encomenda>*);
void listarEncomendas(vector<Encomenda>);
void pesquisarEncomendas(vector<Encomenda>);
void guardaFicheiroEncomenda(vector<Encomenda>);
void lerFicheiroEncomenda(vector<Encomenda>*);
bool processaEscolhaEncomenda(vector<Encomenda>*, char, bool, int);
void pagamentoFaturas(vector <Encomenda>* encomendas);



//******************************************
using namespace std;

//****************************************************
//* Função principal
//****************************************************
int main()
{
    setlocale(LC_ALL, "Portuguese");

    // 1. Dados
    //vector<Livro> livros;

    try
    {
        char escolha = '\0';
        bool queroSair = false;
        const int NUMOPCOES = 4;
        // 2. Programa principal

        do
        {
            mostraMenuPrincipal();

            escolha = obtemEscolha(escolha, NUMOPCOES);
            queroSair = processaEscolhaPrincipal(escolha, queroSair, NUMOPCOES);
        } while (!queroSair);
        despedida();
    }
    catch (const exception&)
    {
        cout << "Algo correu mal, o programa será encerrado. Lamentamos o sucedido." << endl;
    }

    return 0;
} // Fim da função "main()"

void mostraMenuEncomenda()
{
    system("cls");   // Limpa o ecrã 
    system("color F");
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*          Encomendas             *" << endl;
    cout << "*                                 *" << endl;
    cout << "*    A. Inserir encomenda.        *" << endl;
    cout << "*    B. Listar encomendas         *" << endl;
    cout << "*    C. Pesquisar encomendas      *" << endl;
    cout << "*    D. Pagamento de faturas      *" << endl;
    cout << "*    E. Sair                      *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cout << endl;

}

void mainEncomenda()
{
    mostraMenuEncomenda();
    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 5;
    // 2. Programa principal
    lerFicheiroEncomenda(&encomendas);

    do
    {
        escolha = obtemEscolha(escolha, NUMOPCOES);
        queroSair = processaEscolhaEncomenda(&encomendas, escolha, queroSair, NUMOPCOES);
    } while (!queroSair);

}

bool processaEscolhaEncomenda(vector<Encomenda>* encomendas,
    char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a':
        inserirEncomenda(encomendas);
        guardaFicheiroEncomenda(*encomendas);
        break;
    case 'B': case 'b': listarEncomendas(*encomendas);
        break;
    case 'C': case 'c': pesquisarEncomendas(*encomendas);
        break;
    case 'D': case 'd': pagamentoFaturas(encomendas);
        break;
    case 'E': case 'e': queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);

    } // Fim do "switch"

    return queroSair;
}

void pagamentoFaturas(vector <Encomenda>* encomendas)
{
    int nEncomendas = 0;
    nEncomendas = encomendas->size();
    Encomenda* e;

    nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas a pagar!" << endl;
        pausa();
    }
    else
    {

        do {
            cout << "Qual a encomenda a pagar? (1-" << nEncomendas << ")? ";
            cin >> nEncomendas; cin.ignore();
            if (nEncomendas < 1 || nEncomendas > nEncomendas)
            {
                cout << "Número de encomendas entre 1 e " << nEncomendas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nEncomendas < 1 || nEncomendas > nEncomendas);


        encomendas->erase(encomendas->begin() + (nEncomendas- 1));
        Encomenda::numEncomenda--;
        cout << "Fatura paga com sucesso com sucesso!" << endl;
        pausa();
        mostraMenuFornecedor();
    }
}

void inserirEncomenda(vector<Encomenda>* encomendas)
{
    Encomenda* e;
    e = new Encomenda;
    e->leTudoEncomenda();

    int nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;

    encomendas->push_back(*e);
    Encomenda::numEncomenda++;
    //livros.insert(livros.begin()+nLivros, livro);
    encomendas->at(nEncomendas).mostraTudoEncomenda();
    nEncomendas = encomendas->size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;
    cout << "Encomenda inserida com sucesso!" << endl;
    guardaFicheiroEncomenda(*encomendas);
    pausa();
    mostraMenuEncomenda();
} // Fim da função "Inserirlivro()".

void listarEncomendas(vector<Encomenda> encomendas)
{
    int nEncomendas = encomendas.size();
    cout << "Número de encomendas: " << nEncomendas << "." << endl;
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        cout << "-> Listagem de encomendas: \n";
        cout << endl;
        for (int cEncomenda = 0; cEncomenda < nEncomendas; cEncomenda++)
        {
            cout << "Encomenda: " << cEncomenda + 1 << ": ";
            cout << " -> Status: " << encomendas[cEncomenda].getStatus();
            cout << " -> Data Entrega: " << encomendas[cEncomenda].getDataEntrega();
            cout << " -> Preço Custo: " << encomendas[cEncomenda].getPrecoCusto() << " euros";
            cout << " -> Quantidade: " << encomendas[cEncomenda].getQuantidade();
            cout << " unidades.";
            cout << " -> Id Fornecedor: " << encomendas[cEncomenda].getIdFornecedor();
            cout << " -> Id da encomenda: " << encomendas[cEncomenda].getIdProduto() << endl;;
            cout << "********************************************************************************";
            cout << endl;
        } // Fim do "for"    
        cout << endl;
    }
    pausa();
    mostraMenuEncomenda();
} // Fim da função "listarLivroes()".

void pesquisarEncomendas(vector<Encomenda> encomendas)
{
    int nEncomendas = 0;
    nEncomendas = encomendas.size();
    if (nEncomendas <= 0)
    {
        cout << "Não existem encomendas!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais as encomendas a pesquisar (1-" << nEncomendas << ")? ";
            cin >> nEncomendas; cin.ignore();
            if (nEncomendas < 1 || nEncomendas > nEncomendas)
            {
                cout << "Número de encomendas entre 1 e " << nEncomendas << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nEncomendas < 1 || nEncomendas > nEncomendas);

        encomendas[nEncomendas - 1].mostraTudoEncomenda();
        pausa();
        mostraMenuEncomenda();
    }
} // Fim da função "pesquisarlivro()".

// 
//****************************************************************
//* GravarFicheiro
//****************************************************************
void guardaFicheiroEncomenda(vector<Encomenda> encomendas)
{
    string caminho = "", nomeFicheiro = "encomendas.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nEncomendas = encomendas.size();
        cout << "Número de encomendas: " << nEncomendas << "." << endl;
        if (nEncomendas <= 0)
        {
            cout << "Não existem encomendas!" << endl;
            pausa();
        }
        else
        {
            cout << "-> Gravação das encomendas: \n";
            for (int cEncomendas = 0; cEncomendas < nEncomendas; cEncomendas++)
                ficheiro << encomendas[cEncomendas];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiro()".

void lerFicheiroEncomenda(vector<Encomenda>* encomendas)
{
    string caminho = "", nomeFicheiro = "encomendas.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    encomendas->erase(encomendas->begin(), encomendas->end());

    cout << "-> Leitura das encomendas: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {

        Encomenda e;
        // 4. Leitura dos objetos
        int contaEncomendas = 0;
        while (ficheiroL >> e && !ficheiroL.eof())
        {
            encomendas->push_back(e);
            contaEncomendas++;
            cout << "Encomenda " << contaEncomendas << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
        cout << endl;
    }
} // FIm do ler ficheiro


//***********************************************
//* Função "inicializaLivraria()"
//* Entrada(s):  livros.
//* Saida(s): não tem.
//************************************************
void inicializaLojaTenis()
{


} // Fim da função "inicializaLivraria()"

//*******************************************************
//* Função "mostraMenuTenis()".
//* Entrada(s): não tem.
//* Saida(s): não tem.
//*******************************************************
void mostraMenuPrincipal()
{
    system("cls");   // Limpa o ecrã 
    system("color E");
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*          Ténis Gest             *" << endl;
    cout << "*                                 *" << endl;
    cout << "*    A. Gestão dos ténis.         *" << endl;
    cout << "*    B. Gestão de fornecedores    *" << endl;
    cout << "*    C. Gestão de encomendas      *" << endl;
    cout << "*    D. Sair                      *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cout << endl;
}

bool processaEscolhaPrincipal(char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a':
        MainTenis();
        break;
    case 'B': case 'b':
        mainFornecedor();
        break;
    case 'C': case 'c':
        mainEncomenda();
        break;

    case 'D': case 'd':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch")
    return queroSair;
}

void mostraMenuTenis()
{
    system("cls");   // Limpa o ecrã 
    system("color A");
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*          Ténis Gest             *" << endl;
    cout << "*                                 *" << endl;
    cout << "*    A. Inserir ténis.            *" << endl;
    cout << "*    B. Listar ténis              *" << endl;
    cout << "*    C. Pesquisar ténis.          *" << endl;
    cout << "*    D. Vender ténis.             *" << endl;
    cout << "*    E. Repor ténis.              *" << endl;
    cout << "*    F. Apagar ténis              *" << endl;
    cout << "*    G. Atualizar ténis.          *" << endl;
    cout << "*    H. Voltar ao menu anterior   *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cout << endl;
} // Fim da função "mostraMenuTenis()".

void MainTenis()
{
    mostraMenuTenis();
    char escolha = '\0';
    bool queroSair = false;
    const int NUMOPCOES = 8;
    // 2. Programa principal
    lerFicheiro(&listaTenis);
   
    do
    {
        escolha = obtemEscolha(escolha, NUMOPCOES);
        queroSair = processaEscolhaTenis(&listaTenis, escolha, queroSair, NUMOPCOES);
    } while (!queroSair);   
}
  
  //*********************************************
//* Função "obtemEscolha()"
//* Entrada(s): char escolha 
//* Saida(s): char
//*********************************************
char obtemEscolha(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
} // Fim do "obtemEscolha()".

//**********************************************
//*  Função processaEscolhaTenis()"
//*    Entradas: vector<Livro>& livros, int numLivros,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
bool processaEscolhaTenis(vector<Tenis>* listaTenis,
    char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a': inserirTenis(listaTenis);
        
        break;
    case 'B': case 'b': listarTenis(*listaTenis);
        break;
    case 'C': case 'c': pesquisarTenis(*listaTenis);
        break;
    case 'D': case 'd':venderTenis(listaTenis);
       
        break;
    case 'E': case 'e': reporTenis(listaTenis);

        break;        
    case 'F': case 'f': apagarTenis(listaTenis);

        break;
    case 'G': case 'g':atualizarTenis(listaTenis);
        guardaFicheiro(*listaTenis);
        break;
    case 'H': case 'h': 
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
} // Fim da Função "processaEscolhaTenis()".

//**********************************************
//*  Função inserirLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void inserirTenis(vector<Tenis>* listaTenis)
{
    Tenis* t;
    t = new Tenis;
    t->leTudoTenis();

    int nTenis = listaTenis->size();
    cout << "Número de Ténis: " << nTenis << "." << endl;

    listaTenis->push_back(*t);
    Tenis::numTenis++;
    //livros.insert(livros.begin()+nLivros, livro);
    listaTenis->at(nTenis).mostraTudoTenis();
    nTenis = listaTenis->size();
    cout << "Número de ténis: " << nTenis<< "." << endl;
    cout << "Ténis inserido com sucesso!" << endl;
    guardaFicheiro(*listaTenis);
    pausa();
    mostraMenuTenis();
} // Fim da função "Inserirlivro()".

//**********************************************
//*  Função apagarLivro()"
//*    Entradas: vector<Livro>& livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void apagarTenis(vector<Tenis>* listaTenis)
{
    int nTenis = 0;
    nTenis = listaTenis->size();
    cout << "Número de ténis: " << nTenis << "." << endl;
    if (nTenis <= 0)
    {
        cout << "Não existem ténis!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais os ténis a apagar (1-" << nTenis << ")? ";
            cin >> nTenis; cin.ignore();
            if (nTenis< 1 || nTenis> nTenis)
            {
                cout << "Número de ténis entre 1 e " << nTenis<< "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nTenis < 1 || nTenis > nTenis);

        listaTenis->erase(listaTenis->begin() + (nTenis - 1));
        Tenis::numTenis--;
        cout << "Ténis apagado com sucesso!" << endl;
        guardaFicheiro(*listaTenis);
        pausa();
        mostraMenuTenis();
    }

} // Fim da função "apagarlivro()".

//**********************************************
//*  Função pesquisarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void pesquisarTenis(vector<Tenis> listaTenis)
{
    int nTenis = 0;
    nTenis = listaTenis.size();
    if (nTenis <= 0)
    {
        cout << "Não existem ténis!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais os ténis a pesquisar (1-" << nTenis << ")? ";
            cin >> nTenis; cin.ignore();
            if (nTenis < 1 || nTenis > nTenis)
            {
                cout << "Número de ténis entre 1 e " << nTenis << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nTenis < 1 || nTenis > nTenis);

        listaTenis[nTenis - 1].mostraTudoTenis();
        pausa();
        mostraMenuTenis();
    }
} // Fim da função "pesquisarlivro()".

//**********************************************
//*  Função atualizarLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void atualizarTenis(vector<Tenis>* listaTenis)
{
    int nTenis = 0;
    nTenis = listaTenis->size();
    if (nTenis <= 0)
    {
        cout << "Não existem Ténis!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais os ténis a atualizar (1-" << nTenis << ")? ";
            cin >> nTenis; cin.ignore();
            if (nTenis < 1 || nTenis > nTenis)
            if (nTenis < 1 || nTenis > nTenis)
            {
                cout << "Número de ténis entre 1 e " << nTenis << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nTenis < 1 || nTenis > nTenis);
        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        cout << "Insira o novo preço: " << endl;
        (*listaTenis)[nTenis - 1].lePreco();
        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        cout << "Atualização efetuada com sucesso!" << endl;
        pausa();
        mostraMenuTenis();
    }
} // Fim da função "atualizarlivro()".

//**************************************************
//* Função "listarLivros()"
//* Entrada(s): Livro livros[], int numLivros
//* Saida(s): não tem.
//**************************************************
void listarTenis(vector<Tenis > listaTenis)
{
    int nTenis = listaTenis.size();
    cout << "Número de ténis: " << nTenis << "." << endl;
    if (nTenis <= 0)
    {
        cout << "Não existem ténis!" << endl;
        pausa();
    }
    else
    {
        cout << "-> Listagem de ténis: \n";
        for (int cTenis = 0; cTenis < nTenis; cTenis++)
        {
            cout << "Ténis " << cTenis + 1 << ": ";
            cout << " -> " << listaTenis[cTenis].getMarca();
            cout << " -> " << listaTenis[cTenis].getModelo();
            cout << " -> " << listaTenis[cTenis].getPreco() << " euros";
            cout << " -> " << listaTenis[cTenis].getNumUnidades();
            cout << " unidades." << endl;
        } // Fim do "for"
      
        pausa();
        mostraMenuTenis();
    }
} // Fim da função "listarLivroes()".

//**********************************************
//*  Função venderLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void venderTenis(vector<Tenis>* listaTenis)
{
    int nTenis = 0;
    nTenis = listaTenis->size();
    if (nTenis <= 0)
    {
        cout << "Não existem ténis!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais os ténis a vender (1-" << nTenis << ")? ";
            cin >> nTenis; cin.ignore();
            if (nTenis < 1 || nTenis > nTenis)
            {
                cout << "Número de ténis entre 1 e " << nTenis << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nTenis < 1 || nTenis > nTenis);

        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        int uVendidas = 0, nUnidades = 0;
        nUnidades = (*listaTenis)[nTenis - 1].getNumUnidades();
        cout << "Quantas unidades vendeu? ";
        cin >> uVendidas; cin.ignore();
        nUnidades -= uVendidas;
        (*listaTenis)[nTenis - 1].setNumUnidades(nUnidades);
        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        cout << "Venda efetuada com sucesso!" << endl;
        guardaFicheiro(*listaTenis);
        pausa();
        mostraMenuTenis();
    }
} // Fim da função "venderlivro()".

//**********************************************
//*  Função reporLivro()"
//*    Entradas: vector<Livro> *livros, int numLivros.
//*    Saida(s): não tem.
//**********************************************
void reporTenis(vector<Tenis>* listaTenis)
{
    int nTenis = 0;
    nTenis = listaTenis->size();
    if (nTenis <= 0)
    {
        cout << "Não existem ténis!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Quais os ténis a repor (1-" << nTenis << ")? ";
            cin >> nTenis; cin.ignore();
            if (nTenis < 1 || nTenis > nTenis)
            {
                cout << "Número de ténis entre 1 e " << nTenis<< "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nTenis < 1 || nTenis > nTenis);

        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        int uRepostas = 0, nUnidades = 0;
        nUnidades = (*listaTenis)[nTenis - 1].getNumUnidades();
        cout << "Quantas unidades vai repor? ";
        cin >> uRepostas; cin.ignore();
        nUnidades += uRepostas;
        (*listaTenis)[nTenis - 1].setNumUnidades(nUnidades);
        (*listaTenis)[nTenis - 1].mostraTudoTenis();
        cout << "Reposição efetuada com sucesso!" << endl;
        guardaFicheiro(*listaTenis);
        pausa();
        mostraMenuTenis();
    }
} // Fim da função "venderlivro()".

// 
//****************************************************************
//* GravarFicheiro
//****************************************************************
void guardaFicheiro(vector<Tenis> listaTenis)
{
    string caminho = "", nomeFicheiro = "loja_tenis.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nTenis = listaTenis.size();
        cout << "Número de ténis: " << nTenis << "." << endl;
        if (nTenis <= 0)
        {
            cout << "Não existem ténis!" << endl;
            pausa();
        }
        else
        {
            cout << "-> Gravação dos ténis: \n";
            for (int cTenis = 0; cTenis < nTenis; cTenis++)
                ficheiro << listaTenis[cTenis];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiro()".

//****************************************************************
//* LerFicheiro
//****************************************************************
void lerFicheiro(vector<Tenis>* listaTenis)
{
    string caminho = "", nomeFicheiro = "loja_tenis.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    listaTenis->erase(listaTenis->begin(), listaTenis->end());

    cout << "-> Leitura dos ténis: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {

        Tenis t;
        // 4. Leitura dos objetos
        int contaTenis = 0;
        while (ficheiroL >> t && !ficheiroL.eof())
        {
            listaTenis->push_back(t);
            contaTenis++;
            cout << "Ténis " << contaTenis << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
        cout << endl;
    }
} // FIm do ler ficheiro

//**********************************************
//*  Função "pausa()"
//*    Entradas: não tem.
//*    Saida(s): não tem.
//**********************************************

//****************************************************************
//* GravarFicheiroFornecedor
//****************************************************************

void guardaFicheiroFornecedor(vector<Fornecedor> fornecedores)
{
    string caminho = "", nomeFicheiro = "fornecedores.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    // 4. Criar o objeto e abrir o ficheiro
    //ofstream ficheiro4(nomeCompleto.c_str());
    ofstream ficheiro;
    ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
    // Modos de abertura: "ios::out" -> escrita

    if (!ficheiro) {
        cout << "Ficheiro não foi aberto!" << endl;
        pausa();
    }
    else {
        // 4. Escrever mensagem
        int nFornecedores = fornecedores.size();
        cout << "Número de Fornecedores: " << nFornecedores << "." << endl;
        if (nFornecedores<= 0)
        {
            cout << "Não existem fornecedores!" << endl;
            pausa();
        }
        else
        {
            cout << "-> Gravação dos fornecedores: \n";
            for (int cFornecedor = 0; cFornecedor < nFornecedores; cFornecedor++)
                ficheiro << fornecedores[cFornecedor];
            // 5. Fechar o ficheiro
            ficheiro.close();
            cout << "Dados gravados com sucesso!" << endl;
            pausa();
        }
    }

} // Fim da função "guardaFicheiro()".

//****************************************************************
//* LerFicheiroFornecedor
//****************************************************************
void lerFicheiroFornecedor(vector<Fornecedor>* fornecedores)
{
    string caminho = "", nomeFicheiro = "fornecedores.txt";
    string nomeCompleto = caminho + nomeFicheiro;
    cout << "Nome do ficheiro: " << nomeCompleto.c_str() << "." << endl;

    fornecedores->erase(fornecedores->begin(), fornecedores->end());

    cout << "-> Leitura dos fornecedores: \n";
    // 3. Criar o objeto e abrir o ficheiro
   //ofstream ficheiro4(nomeCompleto.c_str());
    ifstream ficheiroL;
    ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary

    if (ficheiroL.is_open()) {
        Fornecedor f;
        // 4. Leitura dos objetos
        int contaFornecedor = 0;
        while (ficheiroL >> f && !ficheiroL.eof())
        {
            fornecedores->push_back(f);
            contaFornecedor++;
            cout << "Fornecedor " << contaFornecedor << ": " << endl;
        }
        // 5. Fechar o ficheiro
        ficheiroL.close();
     
    }
}// FIm ler ficheiro

void mostraMenuFornecedor()
{
    system("cls");   // Limpa o ecrã 
    system("color A");
    cout << "***********************************" << endl;
    cout << "*                                 *" << endl;
    cout << "*          Fornecedores           *" << endl;
    cout << "*                                 *" << endl;
    cout << "*    A. Inserir fornecedor.       *" << endl;
    cout << "*    B. Listar fornecedor         *" << endl;
    cout << "*    C. Pesquisar fornecedor.     *" << endl;
    cout << "*    D. Atualizar fornecedor      *" << endl;
    cout << "*    E. Apagar fornecedor         *" << endl;
    cout << "*    F. Voltar ao menu anterior.  *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;
    cout << endl;
} // Fim da função "mostraMenuTenis()".

void mainFornecedor()
{
    mostraMenuFornecedor();
   
    char escolhaFornecedor = '\0';
    bool queroSairFornecedor = false;
    const int NUMOPCOESFORNECEDOR= 6;

    lerFicheiroFornecedor(&fornecedores);

    do
    {
        escolhaFornecedor = obtemEscolhaFornecedor(escolhaFornecedor, NUMOPCOESFORNECEDOR);
        queroSairFornecedor = processaEscolhaFornecedor(&fornecedores, escolhaFornecedor, queroSairFornecedor, NUMOPCOESFORNECEDOR);
    } while (!queroSairFornecedor);
    pausa();
}

char obtemEscolhaFornecedor(char escolha, int numOp)
{
    char ultimaOp = (char)(numOp + 64); // "A" - ASCII 65	
    cout << "Qual a sua escolha (A-" << ultimaOp << ")? ";
    cin >> escolha; cin.ignore();
    return escolha;
} // Fim do "obtemEscolha()"

bool processaEscolhaFornecedor(vector<Fornecedor>* fornecedores,
    char escolha, bool queroSair, int numOp)
{
    switch (escolha)
    {
    case 'A': case 'a': inserirFornecedor(fornecedores);
   
        break;
    case 'B': case 'b': listarFornecedores(*fornecedores);
        break;
    case 'C': case 'c': pesquisarFornecedor(*fornecedores);
        break;
    case 'D': case 'd': atualizarFornecedor(fornecedores);
         guardaFicheiroFornecedor(*fornecedores);
        break;
    case 'E': case 'e':apagarFornecedor(fornecedores);
          guardaFicheiroFornecedor(*fornecedores);
        break;

    case 'F': case 'f':
        queroSair = sairDoPrograma(queroSair);
        break;
    default:
        escolhaInvalida(numOp);
    } // Fim do "switch"

    return queroSair;
} // Fim da Função "processaEscolhaTenis()".

void inserirFornecedor(vector<Fornecedor>* fornecedores)
{
    Fornecedor* f;
    f = new Fornecedor;
    f->leTudoFornecedor();

    int nFornecedor = fornecedores->size();
    cout << "Número de fornecedores: " << nFornecedor << "." << endl;

    fornecedores->push_back(*f);
    Fornecedor::numFornecedores++;
    //livros.insert(livros.begin()+nLivros, livro);
    fornecedores->at(nFornecedor).mostraTudoFornecedor();
    nFornecedor = fornecedores->size();
    cout << "Número de fornecedores: " << nFornecedor<< "." << endl;
    cout << "Fornecedor inserido com sucesso!" << endl;
    guardaFicheiroFornecedor(*fornecedores);
    pausa();
    mostraMenuFornecedor();
} // Fim da função "Inserirlivro()".

void apagarFornecedor(vector<Fornecedor>* fornecedores)
{
    int nFornecedor = 0;
    nFornecedor = fornecedores->size();
    cout << "Número de fornecedores: " << nFornecedor << "." << endl;
    if (nFornecedor <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o fornecedor a apagar (1-" << nFornecedor << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nFornecedor)
            {
                cout << "Número de fornecedores entre 1 e " << nFornecedor << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nFornecedor < 1 || nFornecedor > nFornecedor);

        fornecedores->erase(fornecedores->begin() + (nFornecedor - 1));
        Fornecedor::numFornecedores--;
        cout << "Ténis apagado com sucesso!" << endl;
        pausa();
        mostraMenuFornecedor();
    }

} // Fim da função "apagarlivro()".

void pesquisarFornecedor(vector<Fornecedor> fornecedores)
{
    int nFornecedor = 0;
    nFornecedor = fornecedores.size();
    if (nFornecedor <= 0)
    {
        cout << "Não existem Fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o fornecedor a pesquisar (1-" << nFornecedor << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nFornecedor)
            {
                cout << "Número de fornecedores entre 1 e " << nFornecedor << "." << endl;
                cout << "Prima qualquer tecla para continuar ... ";
                cin.get();
            }
        } while (nFornecedor < 1 || nFornecedor > nFornecedor);

        fornecedores[nFornecedor - 1].mostraTudoFornecedor();
        pausa();
        mostraMenuFornecedor();
    }
} // Fim da função "pesquisarlivro()".

void atualizarFornecedor(vector<Fornecedor>* fornecedores)
{
    int nFornecedor = 0;
    nFornecedor = fornecedores->size();
    if (nFornecedor <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        do {
            cout << "Qual o fornecedor a atualizar (1-" << nFornecedor << ")? ";
            cin >> nFornecedor; cin.ignore();
            if (nFornecedor < 1 || nFornecedor > nFornecedor)
                if (nFornecedor < 1 || nFornecedor > nFornecedor)
                {
                    cout << "Número de ténis entre 1 e " << nFornecedor << "." << endl;
                    cout << "Prima qualquer tecla para continuar ... ";
                    cin.get();
                }
        } while (nFornecedor < 1 || nFornecedor > nFornecedor);
        (*fornecedores)[nFornecedor - 1].mostraTudoFornecedor();
        cout << "Insira o novo nome: " << endl;
        (*fornecedores)[nFornecedor - 1].leNome();
        (*fornecedores)[nFornecedor - 1].mostraTudoFornecedor();
        cout << "Atualização efetuada com sucesso!" << endl;
        pausa();
        mostraMenuFornecedor();
    }
} // Fim da função "atualizarlivro()".

//**************************************************
//* Função "listarLivros()"
//* Entrada(s): Livro livros[], int numLivros
//* Saida(s): não tem.
//**************************************************
void listarFornecedores(vector<Fornecedor > fornecedores)
{
    int nFornecedor = fornecedores.size();
    cout << "Número de fornecedores: " << nFornecedor << "." << endl;
    if (nFornecedor <= 0)
    {
        cout << "Não existem fornecedores!" << endl;
        pausa();
    }
    else
    {
        cout << "-> Listagem de fornecedores: \n";
        for (int cFornecedor = 0; cFornecedor < nFornecedor; cFornecedor++)
        {
            cout << "Fornecedor" << cFornecedor + 1 << ": ";
            cout << " -> " << fornecedores[cFornecedor].getNome();
            cout << " -> Sr/a. " << fornecedores[cFornecedor].getRepresentante();
            cout << " -> " << fornecedores[cFornecedor].getDadosBancarios() << endl;
            cout << endl;
            
        } // Fim do "for"
        pausa();
        mostraMenuFornecedor();
    }
} // Fim da função "listarLivroes()".

void pausa()
    {
        cout << "Prima qualquer tecla para continuar ... ";
        cin.get();
    } // Fim da função "pausa()".

//*************************************************
    //*  Função "sairDoPrograma()"
    //*   Entrada(s): queroSair (bool) 
    //*   Saida(s): queroSair (bool)
    //*************************************************
bool sairDoPrograma(bool queroSair)
    {
        char resposta = '\0';
        fflush(stdin);
        cout << "Tem a certeza (S/N)? ";
        cin >> resposta; cin.ignore();
        if (resposta == 'S' || resposta == 's')
            queroSair = true;
        return queroSair;
    } // Fim da função "sairDoPrograma()".

//**************************************************
    //* Função "escolhaInvalida()"
    //*  Entrada(s): não tem.
    //*  Saida(s): não tem.
    //**************************************************
    //**************************************************
    //* Função escolhaInvalida()
    //***************************************************
void escolhaInvalida(int numOp)
    {
        char ultimaOp = (char)(64 + numOp);  // 68 -> 'D'
        cout << "Escolha inválida! Escolha deve ser de A a " << ultimaOp;
        cout << "." << endl;
        pausa();
    } // Fim da função "escolhaInvalida()".

//***************************************************
    //*  Função "despedida()"
    //*   Entrada(s): não tem.
    //*   Saida(s): não tem.
    //***************************************************
void despedida()
    {
        cout << "Obrigado por ter utilizado o nosso \"software\"!\n";
        cout << "Prima qualquer tecla para continuar ... ";
        cin.get();
    } // Fim da função "despedida()".