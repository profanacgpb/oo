#include <iostream>

class Retangulo {
public:
    double largura;
    double altura;

    Retangulo(double l, double h) : largura(l), altura(h) {}

    double area() const {
        return largura * altura;
    }

    double perimetro() const {
        return 2.0 * (largura + altura);
    }
};

int main() {
    Retangulo r1(5.0, 3.0);
    Retangulo r2(10.0, 4.5);
    Retangulo r3(2.5, 2.5);

    std::cout << "R1 -> Area: " << r1.area() << " | Perimetro: " << r1.perimetro() << '\n';
    std::cout << "R2 -> Area: " << r2.area() << " | Perimetro: " << r2.perimetro() << '\n';
    std::cout << "R3 -> Area: " << r3.area() << " | Perimetro: " << r3.perimetro() << '\n';

    return 0;
}