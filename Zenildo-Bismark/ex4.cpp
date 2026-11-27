// Crie a classe Lampada com o atributo ligada e os métodos ligar() , desligar() e estaLigada() .


#include <iostream>
using namespace std;

class Lampada {
public:
    bool ligada;

    void ligar() {
        ligada = true;
        cout << "Lampada ligada!" << endl;
    }

    void desligar() {
        ligada = false;
        cout << "Lampada desligada!" << endl;
    }

    bool estaLigada() {
        return ligada;
    }
};

int main() {

    Lampada l1;

    l1.ligada = false;

    l1.ligar();

    if (l1.estaLigada()) {
        cout << "A lampada esta ligada." << endl;
    } else {
        cout << "A lampada esta desligada." << endl;
    }

    l1.desligar();

    if (l1.estaLigada()) {
        cout << "A lampada esta ligada." << endl;
    } else {
        cout << "A lampada esta desligada." << endl;
    }

    return 0;
}