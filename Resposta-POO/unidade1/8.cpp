#include <iostream>
using namespace std;

class Lampada {
private:
    bool ligada = false;

public:
    void ligar() {
        ligada = true;
    }

    void desligar() {
        ligada = false;
    }

    bool estaLigada() const {
        return ligada;
    }
};

int main() {
    Lampada lampada;

    lampada.ligar();
        cout << "Ligada: "
            << lampada.estaLigada() << endl;

    lampada.desligar();
        cout << "Ligada: "
            << lampada.estaLigada() << endl;

    return 0;
}
