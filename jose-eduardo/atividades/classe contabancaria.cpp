#include <iostream>
#include <string>

class ContaBancaria {
public:
    std::string titular;
    double saldo;

    ContaBancaria(const std::string& t, double saldoInicial = 0.0)
        : titular(t), saldo(saldoInicial) {}

    void depositar(double valor) {
        if (valor > 0.0) {
            saldo += valor;
        }
    }

    bool sacar(double valor) {
        if (valor <= 0.0 || valor > saldo) {
            return false;
        }
        saldo -= valor;
        return true;
    }
};

int main() {
    ContaBancaria c1("Lucas", 500.0);
    ContaBancaria c2("Beatriz", 100.0);
    ContaBancaria c3("Rafael", 0.0);

    // Teste 1: deposito e saque valido
    c1.depositar(250.0);
    std::cout << c1.titular << " saque 600: " << (c1.sacar(600.0) ? "OK" : "Falhou")
              << " | Saldo: " << c1.saldo << '\n';

    // Teste 2: saque acima do saldo
    std::cout << c2.titular << " saque 150: " << (c2.sacar(150.0) ? "OK" : "Falhou")
              << " | Saldo: " << c2.saldo << '\n';

    // Teste 3: deposito seguido de saque exato
    c3.depositar(80.0);
    std::cout << c3.titular << " saque 80: " << (c3.sacar(80.0) ? "OK" : "Falhou")
              << " | Saldo: " << c3.saldo << '\n';

    return 0;
}