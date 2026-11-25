#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Produto {
public:
    string nome;
    double preco;
    int quantidade;

    double valorTotalEmEstoque() const {
        return preco * quantidade;
    }
};

int main() {
    vector<Produto> produtos = {
        {"Mouse", 50, 10},
        {"Teclado", 100, 5},
        {"Monitor", 800, 3},
        {"Webcam", 150, 4},
        {"Headset", 200, 2}
    };

    double total = 0;

    for (const Produto& produto : produtos) {
        total += produto.valorTotalEmEstoque();
    }

    cout << "Valor total: R$ " << total << endl;

    return 0;
}
