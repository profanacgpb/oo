// Crie a classe Retangulo com largura e altura , e os métodos area() e
// perimetro() . Crie 3 objetos e imprima os resultados.

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
        return 2 * (altura + largura);
    }

    void exibirResultado(){
        cout << "--------RESULTADO--------" << endl;;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
    }
};

int main(){

    Retangulo r1, r2, r3;

    r1.largura = 5;
    r1.altura = 3;

    r2.largura = 8;
    r2.altura = 4;
    
    r3.largura = 10;
    r3.altura = 6;

    cout << "Retangulo 1: " << endl;
    r1.exibirResultado();

    cout << "Retangulo 2: " << endl;
    r2.exibirResultado();

    cout << "Retangulo 3: " << endl;
    r3.exibirResultado();

    return 0;
}
