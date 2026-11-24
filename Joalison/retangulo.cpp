#include <iostream>
using namespace std;

class Retangulo {
public:
    double largura;
    double altura;

    double area() {
        return largura * altura;
    }

    double perimetro() {
        return 2 * (largura + altura);
    }
};

int main() {
    Retangulo r1;
    r1.largura = 3;
    r1.altura = 4;

    Retangulo r2;
    r2.largura = 5.5;
    r2.altura = 2;

    Retangulo r3;
    r3.largura = 10;
    r3.altura = 10;

    cout << "Retangulo 1 - area: " << r1.area() << " - perimetro: " << r1.perimetro() << endl;
    cout << "Retangulo 2 - area: " << r2.area() << " - perimetro: " << r2.perimetro() << endl;
    cout << "Retangulo 3 - area: " << r3.area() << " - perimetro: " << r3.perimetro() << endl;

    return 0;
}