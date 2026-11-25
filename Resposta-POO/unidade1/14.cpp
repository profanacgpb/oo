#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cstdlib>
using namespace std;

class Fracao {
private:
    int numerador;
    int denominador;

public:
    Fracao(int n, int d) : numerador(n), denominador(d) {
        if (d == 0) {
            throw invalid_argument("Denominador zero!");
        }
        simplificar();
    }

    void simplificar() {
        int divisor = gcd(numerador, denominador);
        numerador /= divisor;
        denominador /= divisor;

        if (denominador < 0) {
            numerador = -numerador;
            denominador = -denominador;
        }
    }

    Fracao somar(const Fracao& outra) const {
        return Fracao(
            numerador * outra.denominador +
            outra.numerador * denominador,
            denominador * outra.denominador
        );
    }

    Fracao multiplicar(const Fracao& outra) const {
        return Fracao(
            numerador * outra.numerador,
            denominador * outra.denominador
        );
    }

    void mostrar() const {
        cout << numerador << "/" << denominador << endl;
    }
};

int main() {
    Fracao a(1, 2);
    Fracao b(2, 4);

    std::cout << "Soma: ";
    a.somar(b).mostrar();

    cout << "Multiplicacao: ";
    a.multiplicar(b).mostrar();

    return 0;
}
