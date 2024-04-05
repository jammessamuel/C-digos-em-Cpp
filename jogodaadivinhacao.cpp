#include<iostream>    // Biblioteca para entrada e saída
#include<stdbool.h>    // Suporte para o tipo de dado booleano
#include<stdlib.h>     // Biblioteca de utilidades gerais
#include<cmath>        // Funções matemáticas
#include<cstdlib>      // Biblioteca padrão de utilidades C
#include<ctime>        // Funções de tempo

using namespace std;

int main () {

    // Exibe uma mensagem de boas-vindas
    cout << " ******************************** " << endl;
    cout << " * Bem - vindos da adivinhação * " << endl;
    cout << " ******************************** " << endl;

    // Solicita ao usuário que escolha o nível de dificuldade
    cout << " Escolha a dificuldade que quer jogar : " << endl;
    cout << " Fácil (F) Médio (M) Difícil (D) " << endl;

    // Obtém a escolha de dificuldade do usuário
    char dificuldade;
    cin >> dificuldade;

    int numero_de_tentativas;

    // Define o número de tentativas com base no nível de dificuldade escolhido
    if(dificuldade == 'F') {
        numero_de_tentativas = 15;
    } else if (dificuldade == 'M') {
        numero_de_tentativas = 10;
    } else {
        numero_de_tentativas = 5;
    }

    // Gera um número aleatório como o número secreto
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    // Inicializa as variáveis do jogo
    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    // Loop principal do jogo
    for (numero_de_tentativas = 1; tentativas <= numero_de_tentativas; tentativas++) {
        int chute;
        cout << " Tentativa " << tentativas << endl;

        // Obtém o palpite do usuário
        cout << " Qual o seu chute ? " << endl;
        cin >> chute;

        // Calcula os pontos perdidos com base na diferença entre o palpite e o número secreto
        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontos = pontos - pontos_perdidos;

        cout << " O valor do seu chute é : " << chute << endl;

        // Verifica se o palpite está correto
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute >  NUMERO_SECRETO;

        if(acertou) {
            // Exibe uma mensagem para um palpite correto e sai do loop
            cout << " Parabéns ! Você acertou o número secreto ! " << endl;
            nao_acertou = false;
            break;
        } else if(maior) {
            // Exibe uma mensagem para um palpite maior que o número secreto
            cout << " Seu chute foi maior que o número secreto ! " << endl;
        } else {
            // Exibe uma mensagem para um palpite menor que o número secreto
            cout << " Seu número foi menor que o número secreto ! " << endl;
        }
    }

    // Exibe o resultado do jogo
    cout << " Fim de jogo ! " << endl;
    if(nao_acertou) {
        // Exibe uma mensagem para o caso de perder o jogo
        cout << " Você perdeu ! Tente novamente " << endl;
    } else {
        // Exibe uma mensagem para o caso de vencer o jogo, juntamente com a pontuação
        cout << " Você acertou o número secreto em : " << tentativas << " Tentativas " << endl;
        cout.precision(2);
        cout << fixed;
        cout << " Sua pontuação foi de : " << pontos << " pontos " << endl;
    }

    // Fim do programa
    return 0;
}
