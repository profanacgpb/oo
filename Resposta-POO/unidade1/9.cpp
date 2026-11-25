#include <iostream>
#include <string>
using namespace std;

class ContaBancaria {
private:
    string titular;
    double saldo;

public:
    ContaBancaria(const string& nome, double inicial)
        : titular(nome), saldo(inicial >= 0 ? inicial : 0) {}

    void depositar(double valor) {
        if (valor > 0) {
            saldo += valor;
        }
    }

    bool sacar(double valor) {
        if (valor <= 0 || valor > saldo) {
            return false;
        }

        saldo -= valor;
        return true;
    }

    double consultarSaldo() const {
        return saldo;
    }
};

int main() {
    ContaBancaria conta("Pedro", 500);

    conta.depositar(200);

    if (conta.sacar(100)) {
        cout << "Saque realizado!\n";
    } else {
        cout << "Saque recusado!\n";
    }

        cout << "Saldo: R$ "
        << conta.consultarSaldo() << endl;

    return 0;
}
