#include <iostream>
#include <string>
using namespace std;

class Aluno {
public:
    string nome;
    double notas[3];

    double media() {
        double soma = 0;
        for (int i = 0; i < 3; i++) {
            soma = soma + notas[i];
        }
        return soma / 3;
    }

    string situacao() {
        double m = media();
        if (m >= 7) {
            return "aprovado";
        } else if (m >= 4) {
            return "final";
        } else {
            return "reprovado";
        }
    }
};

int main() {
    Aluno a1;
    a1.nome = "Joalison";
    a1.notas[0] = 8;
    a1.notas[1] = 9;
    a1.notas[2] = 7.5;

    Aluno a2;
    a2.nome = "Nosilaoj";
    a2.notas[0] = 5;
    a2.notas[1] = 6;
    a2.notas[2] = 4.5;

    Aluno a3;
    a3.nome = "Albuquerque";
    a3.notas[0] = 2;
    a3.notas[1] = 3.5;
    a3.notas[2] = 4;

    cout << a1.nome << " - media: " << a1.media() << " - " << a1.situacao() << endl;
    cout << a2.nome << " - media: " << a2.media() << " - " << a2.situacao() << endl;
    cout << a3.nome << " - media: " << a3.media() << " - " << a3.situacao() << endl;

    return 0;
}