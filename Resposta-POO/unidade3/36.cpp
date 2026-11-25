#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>
using namespace std;

class Veiculo {
public:
    virtual double calcularPedagio() const = 0;

    virtual string getTipo() const = 0;

    virtual ~Veiculo() = default;
};

class Carro : public Veiculo {
private:
    int eixos;

public:
    Carro(int quantidade)
        : eixos(quantidade) {
    }

    double calcularPedagio() const override {
        return eixos * 5.0;
    }

    string getTipo() const override {
        return "Carro";
    }
};

class Moto : public Veiculo {
public:
    double calcularPedagio() const override {
        return 4.0;
    }

    string getTipo() const override {
        return "Moto";
    }
};

class Caminhao : public Veiculo {
private:
    double peso;

public:
    Caminhao(double toneladas)
        : peso(toneladas) {
    }

    double calcularPedagio() const override {
        return peso * 3.0;
    }

    string getTipo() const override {
        return "Caminhao";
    }
};

int main() {
    vector<unique_ptr<Veiculo>> veiculos;

    veiculos.push_back(make_unique<Carro>(2));

    veiculos.push_back(make_unique<Moto>());

    veiculos.push_back(make_unique<Caminhao>(10));

    double total = 0;

    cout << fixed << setprecision(2);

    cout << "===== PEDAGIO =====" << endl;

    for (const auto& veiculo : veiculos) {

        double valor = veiculo->calcularPedagio();

        cout << veiculo->getTipo()
             << ": R$ " << valor << endl;

        total += valor;
    }

    cout << "Total arrecadado: R$ "
         << total << endl;

    return 0;
}
