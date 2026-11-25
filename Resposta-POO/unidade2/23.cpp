#include <iostream>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Termometro {
private:
    double celsius;

public:
    Termometro(double temperatura) {
        setCelsius(temperatura);
    }

    void setCelsius(double temperatura) {
        if (temperatura < -273.15) {
            throw invalid_argument("Temperatura invalida!");
        }

        celsius = temperatura;
    }

    double getCelsius() const {
        return celsius;
    }

    double getFahrenheit() const {
        return celsius * 9.0 / 5.0 + 32;
    }

    double getKelvin() const {
        return celsius + 273.15;
    }
};

int main() {
    try {
        double temperatura;

        cout << "Informe a temperatura em Celsius: ";

        if (!(cin >> temperatura)) {
            throw invalid_argument("Entrada invalida!");
        }

        Termometro termometro(temperatura);

        cout << fixed << setprecision(2);

        cout << "Celsius: "
             << termometro.getCelsius() << endl;

        cout << "Fahrenheit: "
             << termometro.getFahrenheit() << endl;

        cout << "Kelvin: "
             << termometro.getKelvin() << endl;

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
