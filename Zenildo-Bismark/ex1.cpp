#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    int matricula;
    int idade;
    float nota;

    void estudar() {
        cout << nome << " está estudando." << endl;
    }

    void fazerProva() {
        cout << nome << " está fazendo uma prova." << endl;
    }

    void mostrarDados() {
        cout << "\n--- Dados do Aluno ---" << endl;
        cout << "Nome: " << nome << endl;
        cout << "Matricula: " << matricula << endl;
        cout << "Idade: " << idade << endl;
        cout << "Nota: " << nota << endl;
    }
};

int main() {

    Aluno aluno1;
    aluno1.nome = "Joao";
    aluno1.matricula = 1001;
    aluno1.idade = 20;
    aluno1.nota = 8.5;

    Aluno aluno2;
    aluno2.nome = "Maria";
    aluno2.matricula = 1002;
    aluno2.idade = 22;
    aluno2.nota = 9.0;

    Aluno aluno3;
    aluno3.nome = "Pedro";
    aluno3.matricula = 1003;
    aluno3.idade = 19;
    aluno3.nota = 7.5;

    aluno1.mostrarDados();
    aluno2.mostrarDados();
    aluno3.mostrarDados();

    aluno1.estudar();
    aluno2.fazerProva();
    aluno3.estudar();

    return 0;
}