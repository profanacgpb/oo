#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    void apresentar() {
        cout << "Oi, meu nome Joalison " << nome << " e tenho " << idade << " anos." << endl;
    }
};

int main() {
    Pessoa p;
    p.nome = "Joalison";
    p.idade = 20;

    p.apresentar();

    return 0;
}