#include "ContaBancaria.h"
#include <stdexcept>
using namespace std;

ContaBancaria::ContaBancaria(
    const string& nome,
    double saldoInicial
) : titular(nome), saldo(saldoInicial) {

    if (saldoInicial < 0) {
        throw invalid_argument("Saldo invalido!");
    }
}

void ContaBancaria::depositar(double valor) {
    if (valor <= 0) {
        throw invalid_argument("Deposito invalido!");
    }

    saldo += valor;
}

bool ContaBancaria::sacar(double valor) {
    if (valor <= 0 || valor > saldo) {
        return false;
    }

    saldo -= valor;

    return true;
}

double ContaBancaria::getSaldo() const {
    return saldo;
}

    string ContaBancaria::getTitular() const {
    return titular;
}
