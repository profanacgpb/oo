#include <iostream>
#include <stdexcept>
using namespace std;

class Retangulo {
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double a) {
        setLargura(l);
        setAltura(a);
    }

    void setLargura(double valor) {
        if (valor <= 0) {
            throw invalid_argument("Largura invalida!");
        }

        largura = valor;
    }

    void setAltura(double valor) {
        if (valor <= 0) {
            throw invalid_argument("Altura invalida!");
        }

        altura = valor;
    }

    double getLargura() const {
        return largura;
    }

    double getAltura() const {
        return altura;
    }

    double area() const {
        return largura * altura;
    }

    double perimetro() const {
        return 2 * (largura + altura);
    }
};

int main() {
    try {
        Retangulo retangulo(5, 3);

        cout << "Largura: "
             << retangulo.getLargura() << endl;

        cout << "Altura: "
             << retangulo.getAltura() << endl;

        cout << "Area: "
             << retangulo.area() << endl;

        cout << "Perimetro: "
             << retangulo.perimetro() << endl;

        retangulo.setLargura(10);

        cout << "Nova area: "
             << retangulo.area() << endl;

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
