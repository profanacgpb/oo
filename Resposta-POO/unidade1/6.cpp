#include <iostream>
using namespace std;

class Retangulo {
public:
    double largura;
    double altura;

    double area() const {
        return largura * altura;
    }

    double perimetro() const {
        return 2 * (largura + altura);
    }
};

int main() {
    Retangulo r1{5, 3};
    Retangulo r2{10, 4};
    Retangulo r3{7, 2};

    Retangulo retangulos[] = {r1, r2, r3};

    for (const Retangulo& r : retangulos) {
        cout << "Area: " << r.area() << endl;
        cout << "Perimetro: " << r.perimetro() << endl;
    }

    return 0;
}
