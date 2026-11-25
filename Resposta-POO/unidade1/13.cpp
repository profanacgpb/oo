#include <iostream>
#include <string>
using namespace std;

class Livro {
public:
    string titulo;

    void mostrar() const {
        cout << "Livro: " << titulo << endl;
    }
};

int main() {
    Livro livroPilha{"Aprendendo C++"};
    livroPilha.mostrar();

    Livro* livroHeap = new Livro{"POO na Pratica"};
    livroHeap->mostrar();

    delete livroHeap;
    livroHeap = nullptr;

    return 0;
}
