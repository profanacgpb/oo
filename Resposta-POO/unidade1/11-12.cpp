#include <iostream>
#include <string>
#include <array>
using namespace std;

class Aluno {
private:
    string nome;
    array<double, 3> notas;
    static int totalAlunos;

public:
    Aluno(const string& n, array<double, 3> valores)
        : nome(n), notas(valores) {
        totalAlunos++;
    }

    double media() const {
        return (notas[0] + notas[1] + notas[2]) / 3.0;
    }

    string situacao() const {
        double m = media();

        if (m >= 7) return "Aprovado";
        if (m >= 4) return "Final";
        return "Reprovado";
    }

    static int getTotalAlunos() {
        return totalAlunos;
    }

    void mostrar() const {
        cout << nome << ": " << media()
                  << " - " << situacao() << endl;
    }
};

int Aluno::totalAlunos = 0;

int main() {
    Aluno a1("Ana", {8, 9, 7});
    Aluno a2("Carlos", {5, 6, 4});
    Aluno a3("Maria", {2, 3, 3});

    a1.mostrar();
    a2.mostrar();
    a3.mostrar();

    cout << "Alunos criados: "
              << Aluno::getTotalAlunos() << endl;

    return 0;
}
