#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Variáveis globais (poderiam ser evitadas usando uma classe)
string palavra_secreta = "MELANCIA";
map<char, bool> chutou;
vector<char> chutes_errados;

// Verifica se a letra está na palavra secreta
bool letraExiste(char chute) {
    for (char letra : palavra_secreta) {
        if (chute == letra) {
            return true;
        }
    }
    return false;
}

// Verifica se existem letras não chutadas na palavra secreta
bool naoAcertou() {
    for (char letra : palavra_secreta) {
        if (!chutou[letra]) {
            return true;
        }
    }
    return false;
}

// Verifica se o jogador ainda pode fazer chutes errados
bool naoEnforcou() {
    return chutes_errados.size() < 5;
}

// Imprime o cabeçalho do jogo
void imprimeCabecalho() {
    cout << " ********************* " << endl;
    cout << "  ** Jogo da Forca ** " << endl;
    cout << " ********************* " << endl;
    cout << endl;
}

// Imprime os chutes errados
void imprimiErros() {
    cout << "Chutes errados: ";
    for (char letra : chutes_errados) {
        cout << letra << " ";
    }
    cout << endl;
}

// Imprime a palavra oculta, mostrando as letras acertadas
void imprimiPalavra() {
    for (char letra : palavra_secreta) {
        if (chutou[letra]) {
            cout << letra << " ";
        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

// Solicita um chute do jogador
void chuta() {
    cout << "Seu chute: ";
    char chute;
    cin >> chute;

    chutou[chute] = true;

    if (letraExiste(chute)) {
        cout << "Você acertou! Seu chute está na palavra." << endl;
    } else {
        cout << "Você errou! Seu chute não está na palavra." << endl;
        chutes_errados.push_back(chute);
    }
    cout << endl;
}

// Lê as palavras do arquivo e retorna como um vetor de strings
vector<string> lerArquivo() {
    ifstream arquivo;
    arquivo.open("palavras.txt");

    int quantidade_palavras;
    arquivo >> quantidade_palavras;

    vector<string> palavras_arquivo;

    for (int i = 0; i < quantidade_palavras; i++) {
        string palavra_lida;
        arquivo >> palavra_lida;

        palavras_arquivo.push_back(palavra_lida);
    }

    if (arquivo.is_open()) {
        arquivo.close();
        return palavras_arquivo;
    } else {
        cout << "Não foi possível acessar o banco de palavras!" << endl;
        exit(0);
    }
}

// Sorteia uma nova palavra secreta a partir do arquivo
void sorteiaPalavra() {
    vector<string> palavras = lerArquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    palavra_secreta = palavras[indice_sorteado];
}

// Salva um vetor de palavras no arquivo
void salvaArquivo(vector<string> nova_lista) {
    ofstream arquivo;
    arquivo.open("palavras.txt");
    
    if (arquivo.is_open()) {
        arquivo << nova_lista.size() << endl;

        for (string palavra : nova_lista) {
            arquivo << palavra << endl;
        }

        arquivo.close();
    } else {
        cout << "Não foi possível acessar o banco de palavras!" << endl;
        exit(0);
    }
}

// Adiciona uma nova palavra ao arquivo
void adicionaPalavra() {
    cout << "Digite a nova palavra, usando letras maiúsculas! " << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = lerArquivo();
    lista_palavras.push_back(nova_palavra);

    salvaArquivo(lista_palavras);
}

int main() {
    imprimeCabecalho();

    lerArquivo();
    sorteiaPalavra();

    while (naoAcertou() && naoEnforcou()) {
        imprimiErros();
        imprimiPalavra();
        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << palavra_secreta << endl;

    if (naoAcertou()) {
        cout << "Você perdeu! Tente novamente." << endl;
    } else {
        cout << "Parabéns! Você acertou a palavra secreta!" << endl;

        cout << "Você deseja adicionar uma nova palavra ao banco? (S/N) ";
        char resposta;
        cin >> resposta;
        if (resposta == 'S') {
            adicionaPalavra();
        }
    }

    return 0;
}
