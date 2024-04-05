#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int num1;
int num2;
int opcao;

int main() {

    cout << "Escolha uma opção : " << endl;
    cout << " 1 - Somar " << endl << "2 - Subtrair" << endl << "3 - Multiplicar " << endl << "4 - Dividir" << endl << "0: Sair..." << endl;
    cin >> opcao;

    if (opcao > 4) {
        cout << "Opção inválida ! " << endl << "Retorne ao menu de escolha " << endl;
    } else {
        switch (opcao) {
            case 0:
                cout << "Sair" << endl;
                break;

            case 1:
                cout << "Digite o primeiro número : " << endl;
                cin >> num1;
                cout << "Digite o segundo número : " << endl;
                cin >> num2;
                cout << "Soma : " << num1 + num2 << endl;
                break;

            case 2:
                cout << "Digite o primeiro número : " << endl;
                cin >> num1;
                cout << "Digite o segundo número : " << endl;
                cin >> num2;
                cout << "Subtrair : " << num1 - num2 << endl;
                break;

            case 3:
                cout << "Digite o primeiro número : " << endl;
                cin >> num1;
                cout << "Digite o segundo número : " << endl;
                cin >> num2;
                cout << "Multiplicação : " << num1 * num2 << endl;
                break;

            case 4:
                cout << "Digite o primeiro número : ";
                cin >> num1;
                cout << "Digite o segundo número : ";
                cin >> num2;

                while (num2 == 0) {
                    cout << "Opção inválida, não existe divisão por zero!" << endl;
                    cout << "Digite o segundo número novamente : ";
                    cin >> num2;
                }

                cout << "Divisão : " << static_cast<double>(num1) / num2 << endl;
                break;

            default:
                cout << "Opção inválida!" << endl;
                break;
        }
    }

    return 0;
}
