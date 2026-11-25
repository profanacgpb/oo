#include <iostream>

class Lampada {
public:
    bool ligada;

    Lampada(bool estadoInicial = false) : ligada(estadoInicial) {}

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
    Lampada sala;
    Lampada quarto(true);
    Lampada cozinha;

    sala.ligar();
    quarto.desligar();

    std::cout << "Sala ligada? " << (sala.estaLigada() ? "Sim" : "Nao") << '\n';
    std::cout << "Quarto ligada? " << (quarto.estaLigada() ? "Sim" : "Nao") << '\n';
    std::cout << "Cozinha ligada? " << (cozinha.estaLigada() ? "Sim" : "Nao") << '\n';

    return 0;
}