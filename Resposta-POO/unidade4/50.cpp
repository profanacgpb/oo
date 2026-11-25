#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Livro {
private:
    string titulo;

public:
    explicit Livro(const string& t)
        : titulo(t) {

        cout << "Livro criado: "
             << titulo << endl;
    }

    void mostrar() const {
        cout << "Titulo: "
             << titulo << endl;
    }

    ~Livro() {
        cout << "Livro destruido: "
             << titulo << endl;
    }
};

int main() {
    cout << "===== OBJETO NA PILHA =====" << endl;

    Livro livroPilha("Aprendendo C++");

    livroPilha.mostrar();

    cout << "\n===== OBJETO NO HEAP =====" << endl;

    unique_ptr<Livro> livroHeap =
        make_unique<Livro>("POO na Pratica");

    livroHeap->mostrar();

    cout << "\nEncerrando programa..." << endl;

    return 0;
}
