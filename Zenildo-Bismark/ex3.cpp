// Crie a classe Pessoa com nome e idade . Implemente apresentar() , que imprime
// "Olá, meu nome é X e tenho Y anos."

#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    void apresentar(){
        cout << "Ola, meu nome e: " << nome << " e tenho " << idade << " anos." << endl;
    }
};

int main(){

    Pessoa zenildo, alice, clarice;

    zenildo.nome = "Zenildo";
    zenildo.idade = 27;

    alice.nome = "Alice";
    alice.idade = 30;

    clarice.nome = "Clarice";
    clarice.idade = 04;

    zenildo.apresentar();
    alice.apresentar();
    clarice.apresentar();

    return 0;
}