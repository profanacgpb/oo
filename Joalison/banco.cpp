#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
public:
    string titular;
    double saldo;

    void depositar(double valor) {
        saldo = saldo + valor;
    }

    bool sacar(double valor) {
        if (valor > saldo) {
            return false;
        } else {
            saldo = saldo - valor;
            return true;
        }
    }
};

int main() {
    ContaBancaria conta;
    conta.titular = "Joalison";
    conta.saldo = 1000;

    cout << "Titular: " << conta.titular << endl;
    cout << "Saldo inicial: " << conta.saldo << endl;

    conta.depositar(50);
    cout << "Saldo depois de depositar 50: " << conta.saldo << endl;

    if (conta.sacar(120) == true) {
        cout << "Saque de 120 realizado" << endl;
    } else {
        cout << "Saldo insuficiente para sacar 120" << endl;
    }
    cout << "Saldo: " << conta.saldo << endl;

    if (conta.sacar(100) == true) {
        cout << "Saque de 100 realizado" << endl;
    } else {
        cout << "Saldo insuficiente para sacar 100" << endl;
    }
    cout << "Saldo final: " << conta.saldo << endl;

    return 0;
}