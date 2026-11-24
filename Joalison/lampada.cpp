#include <iostream>
using namespace std;

class Lampada {
public:
    bool ligada;

    void ligar() {
        ligada = true;
    }

    void desligar() {
        ligada = false;
    }

    bool estaLigada() {
        return ligada;
    }
};

int main() {
    Lampada l;
    l.ligada = false;

    if (l.estaLigada() == true) {
        cout << "A lampada esta ligada" << endl;
    } else {
        cout << "A lampada esta desligada" << endl;
    }

    l.ligar();

    if (l.estaLigada() == true) {
        cout << "A lampada esta ligada" << endl;
    } else {
        cout << "A lampada esta desligada" << endl;
    }

    l.desligar();

    if (l.estaLigada() == true) {
        cout << "A lampada esta ligada" << endl;
    } else {
        cout << "A lampada esta desligada" << endl;
    }

    return 0;
}