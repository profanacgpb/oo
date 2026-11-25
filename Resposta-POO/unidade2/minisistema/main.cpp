#include <iostream>
#include <exception>
#include "ContaBancaria.h"
using namespace std;

int main() {
    try {
        ContaBancaria conta("Pedro", 1000);

        conta.depositar(500);

        if (conta.sacar(200)) {
            cout << "Saque realizado!" << endl;
        } else {
            cout << "Saque recusado!" << endl;
        }

        cout << "Titular: "
             << conta.getTitular() << endl;

        cout << "Saldo: R$ "
             << conta.getSaldo() << endl;

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
