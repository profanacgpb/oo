#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Aluno {
private:
    string nome;
    int matricula;

public:
    Aluno(const string& n, int m)
        : nome(n), matricula(m) {
    }

    string getNome() const {
        return nome;
    }

    int getMatricula() const {
        return matricula;
    }
};

class Disciplina {
private:
    string nome;

public:
    Disciplina(const string& n)
        : nome(n) {
    }

    string getNome() const {
        return nome;
    }
};

class Turma {
private:
    Disciplina disciplina;
    vector<Aluno> alunos;
    int capacidadeMaxima;

public:
    Turma(const Disciplina& d, int capacidade)
        : disciplina(d), capacidadeMaxima(capacidade) {

        if (capacidade <= 0) {
            throw invalid_argument("Capacidade invalida!");
        }
    }

    void matricular(const Aluno& novoAluno) {

        for (const Aluno& aluno : alunos) {
            if (aluno.getMatricula() ==
                novoAluno.getMatricula()) {

                throw runtime_error(
                    "Aluno ja matriculado!"
                );
            }
        }

        if (alunos.size() >=
            static_cast<size_t>(capacidadeMaxima)) {

            throw runtime_error("Turma lotada!");
        }

        alunos.push_back(novoAluno);

        cout << "Matricula realizada: "
             << novoAluno.getNome() << endl;
    }

    void listarAlunos() const {
        cout << "\nDisciplina: "
             << disciplina.getNome() << endl;

        cout << "Alunos matriculados:" << endl;

        for (const Aluno& aluno : alunos) {
            cout << aluno.getMatricula()
                 << " - "
                 << aluno.getNome()
                 << endl;
        }

        cout << "Vagas ocupadas: "
             << alunos.size()
             << "/"
             << capacidadeMaxima
             << endl;
    }
};

int main() {
    try {
        Disciplina disciplina("Programacao em C++");

        Turma turma(disciplina, 3);

        Aluno aluno1("Pedro", 1001);
        Aluno aluno2("Maria", 1002);
        Aluno aluno3("Carlos", 1003);
        Aluno aluno4("Ana", 1004);

        turma.matricular(aluno1);
        turma.matricular(aluno2);
        turma.matricular(aluno3);

        turma.listarAlunos();

        turma.matricular(aluno4);

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
