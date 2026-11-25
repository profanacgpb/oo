#include <iostream>
#include <string>

class Pessoa {
public:
    std::string nome;
    int idade;

    Pessoa(const std::string& n, int i) : nome(n), idade(i) {}

    void apresentar() const {
        std::cout << "Ola, meu nome e " << nome << " e tenho " << idade << " anos.\n";
    }
};

int main() {
    Pessoa p1("Ana", 21);
    Pessoa p2("Carlos", 34);
    Pessoa p3("Mariana", 19);

    p1.apresentar();
    p2.apresentar();
    p3.apresentar();

    return 0;
}