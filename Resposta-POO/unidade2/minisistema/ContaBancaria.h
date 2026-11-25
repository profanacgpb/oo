#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H
#include <string>


class ContaBancaria {
private:
    std::string titular;
    double saldo;

public:
    ContaBancaria(
        const std::string& nome,
        double saldoInicial
    );

    void depositar(double valor);

    bool sacar(double valor);

    double getSaldo() const;

    std::string getTitular() const;
};

#endif
