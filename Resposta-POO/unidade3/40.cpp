#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Conta {
private:
    string titular;
    double saldo;

protected:
    void alterarSaldo(double valor) {
        saldo += valor;
    }

public:
    Conta(const string& nome, double valor)
        : titular(nome), saldo(valor) {

        if (valor < 0) {
            throw invalid_argument("Saldo inicial invalido!");
        }
    }

    string getTitular() const {
        return titular;
    }

    double getSaldo() const {
        return saldo;
    }

    void depositar(double valor) {
        if (valor <= 0) {
            throw invalid_argument("Deposito invalido!");
        }

        alterarSaldo(valor);
    }

    virtual bool sacar(double valor) {
        if (valor <= 0 || valor > saldo) {
            return false;
        }

        alterarSaldo(-valor);

        return true;
    }

    virtual void fecharMes() = 0;

    virtual string getTipo() const = 0;

    virtual ~Conta() = default;
};

class ContaCorrente : public Conta {
private:
    double limite;

public:
    ContaCorrente(
        const string& nome,
        double saldo,
        double l
    ) : Conta(nome, saldo), limite(l) {

        if (l < 0) {
            throw invalid_argument("Limite invalido!");
        }
    }

    bool sacar(double valor) override {
        if (valor <= 0 ||
            valor > getSaldo() + limite) {

            return false;
        }

        alterarSaldo(-valor);

        return true;
    }

    void fecharMes() override {
        constexpr double TARIFA = 15.0;

        if (sacar(TARIFA)) {
            cout << "Tarifa mensal descontada."
                 << endl;
        } else {
            cout << "Limite insuficiente para tarifa."
                 << endl;
        }
    }

    string getTipo() const override {
        return "Conta Corrente";
    }
};

class ContaPoupanca : public Conta {
private:
    double rendimento;

public:
    ContaPoupanca(
        const string& nome,
        double saldo,
        double taxa
    ) : Conta(nome, saldo), rendimento(taxa) {

        if (taxa < 0) {
            throw invalid_argument("Taxa invalida!");
        }
    }

    void fecharMes() override {
        double juros = getSaldo() * rendimento;

        alterarSaldo(juros);

        cout << "Rendimento: R$ "
             << juros << endl;
    }

    string getTipo() const override {
        return "Conta Poupanca";
    }
};

int main() {
    try {
        vector<unique_ptr<Conta>> contas;

        contas.push_back(
            make_unique<ContaCorrente>(
                "Pedro", 1000, 500
            )
        );

        contas.push_back(
            make_unique<ContaPoupanca>(
                "Maria", 2000, 0.005
            )
        );

        cout << fixed << setprecision(2);

        cout << "===== TESTE DE SAQUE =====" << endl;

        if (contas[0]->sacar(1200)) {
            cout << "Saque autorizado!" << endl;
        } else {
            cout << "Saque recusado!" << endl;
        }

        cout << "\n===== FECHAMENTO MENSAL ====="
             << endl;

        for (const auto& conta : contas) {

            cout << "\nTitular: "
                 << conta->getTitular() << endl;

            cout << "Tipo: "
                 << conta->getTipo() << endl;

            cout << "Saldo anterior: R$ "
                 << conta->getSaldo() << endl;

            conta->fecharMes();

            cout << "Saldo atualizado: R$ "
                 << conta->getSaldo() << endl;
        }

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
