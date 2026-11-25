#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Produto {
private:
    string nome;
    double preco;
    int quantidade;

public:

    Produto(
        const string& nomeProduto,
        double precoProduto,
        int quantidadeProduto
    ) : nome(nomeProduto),
        preco(precoProduto),
        quantidade(quantidadeProduto) {

        if (nome.empty()) {
            throw invalid_argument("Nome invalido!");
        }

        if (!(preco >= 0) || quantidade < 0) {
            throw invalid_argument("Produto invalido!");
        }
    }

    double calcularValorTotal() const {
        return preco * quantidade;
    }

    void mostrar() const {
        cout << fixed << setprecision(2);

        cout << "Produto: " << nome << endl;

        cout << "Preco: R$ "
             << preco << endl;

        cout << "Quantidade: "
             << quantidade << endl;

        cout << "Valor total: R$ "
             << calcularValorTotal() << endl;
    }
};

int main() {
    try {
        Produto produto("Mouse", 50, 10);

        produto.mostrar();

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
