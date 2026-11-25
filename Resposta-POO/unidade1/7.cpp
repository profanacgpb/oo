#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    void apresentar() const {
        cout << "Ola, meu nome e "
             << nome << " e tenho "
             << idade << " anos." << endl;
    }
};

int main() {
    Pessoa pessoa{"Pedro", 22};

    pessoa.apresentar();

    return 0;
}
