#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Aluno {
private:
    string nome;
    double notas[3] = {0, 0, 0};

public:
    Aluno(const string& nomeAluno)
        : nome(nomeAluno) {
    }

    void setNota(int indice, double valor) {
        if (indice < 0 || indice >= 3) {
            throw invalid_argument("Indice invalido!");
        }

        if (valor < 0 || valor > 10) {
            throw invalid_argument("Nota invalida!");
        }

        notas[indice] = valor;
    }

    double getNota(int indice) const {
        if (indice < 0 || indice >= 3) {
            throw invalid_argument("Indice invalido!");
        }

        return notas[indice];
    }

    double media() const {
        double soma = 0;

        for (int i = 0; i < 3; i++) {
            soma += notas[i];
        }

        return soma / 3.0;
    }

    string situacao() const {
        if (media() >= 7) {
            return "Aprovado";
        }

        if (media() >= 4) {
            return "Final";
        }

        return "Reprovado";
    }

    void mostrar() const {
        cout << "Aluno: " << nome << endl;
        cout << "Media: " << media() << endl;
        cout << "Situacao: " << situacao() << endl;
    }
};

int main() {
    try {
        Aluno aluno("Pedro");

        aluno.setNota(0, 8);
        aluno.setNota(1, 9);
        aluno.setNota(2, 7);

        aluno.mostrar();

        aluno.setNota(3, 15);

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
