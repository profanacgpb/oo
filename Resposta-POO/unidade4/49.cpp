#include <iostream>
#include <string>
#include <array>
#include <stdexcept>
using namespace std;

class Aluno {
private:
    string nome;
    array<double, 3> notas = {0, 0, 0};

public:

    explicit Aluno(const string& nomeAluno)
        : nome(nomeAluno) {
    }

    string getNome() const {
        return nome;
    }

    void setNome(const string& novoNome) {
        nome = novoNome;
    }

    void setNota(int indice, double valor) {

        if (indice < 0 || indice >= 3) {
            throw invalid_argument("Indice invalido!");
        }

        if (!(valor >= 0 && valor <= 10)) {
            throw invalid_argument("Nota invalida!");
        }

        notas[indice] = valor;
    }

    double media() const {
        double soma = 0;

        for (double nota : notas) {
            soma += nota;
        }

        return soma / notas.size();
    }

    string situacao() const {
        double mediaAluno = media();

        if (mediaAluno >= 7) {
            return "Aprovado";
        }

        if (mediaAluno >= 4) {
            return "Final";
        }

        return "Reprovado";
    }

    void mostrar() const {
        cout << "Nome: " << nome << endl;
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

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
