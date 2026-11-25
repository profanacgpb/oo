#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;


double calcularMedia(const vector<double>& valores) {

    if (valores.empty()) {
        throw invalid_argument("O vetor esta vazio!");
    }

    double soma = 0;

    for (double valor : valores) {
        soma += valor;
    }

    return soma / valores.size();
}

int main() {
    try {
        vector<double> notas = {
            8.0, 7.0, 9.0, 6.0
        };

        cout << "Media: "
             << calcularMedia(notas)
             << endl;

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
