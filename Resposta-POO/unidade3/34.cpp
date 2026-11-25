#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class Funcionario {
private:
    string nome;

public:
    Funcionario(const string& n)
        : nome(n) {
    }

    string getNome() const {
        return nome;
    }

    virtual double calcularSalario() const = 0;

    virtual ~Funcionario() = default;
};

class Gerente : public Funcionario {
private:
    double salarioBase;
    double bonus;

public:
    Gerente(const string& nome, double salario, double b)
        : Funcionario(nome), salarioBase(salario), bonus(b) {
    }

    double calcularSalario() const override {
        return salarioBase + bonus;
    }
};

class Estagiario : public Funcionario {
private:
    double bolsa;

public:
    Estagiario(const string& nome, double valor)
        : Funcionario(nome), bolsa(valor) {
    }

    double calcularSalario() const override {
        return bolsa;
    }
};

int main() {
    vector<unique_ptr<Funcionario>> funcionarios;

    funcionarios.push_back(
        make_unique<Gerente>("Carlos", 5000, 1000)
    );

    funcionarios.push_back(
        make_unique<Estagiario>("Pedro", 1200)
    );

    funcionarios.push_back(
        make_unique<Estagiario>("Maria", 1500)
    );

    double total = 0;

    cout << fixed << setprecision(2);

    cout << "===== FOLHA DE PAGAMENTO =====" << endl;

    for (const auto& funcionario : funcionarios) {

        double salario = funcionario->calcularSalario();

        cout << funcionario->getNome()
             << ": R$ " << salario << endl;

        total += salario;
    }

    cout << "Total: R$ " << total << endl;

    return 0;
}
