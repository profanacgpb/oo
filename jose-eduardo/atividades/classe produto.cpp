#include <iostream>
#include <string>
#include <vector>

class Produto {
public:
    std::string nome;
    double preco;
    int quantidade;

    Produto(const std::string& n, double p, int q)
        : nome(n), preco(p), quantidade(q) {}

    double valorTotalEmEstoque() const {
        return preco * quantidade;
    }
};

double calcularTotalGeral(const std::vector<Produto>& estoque) {
    double total = 0.0;
    for (const auto& prod : estoque) {
        total += prod.valorTotalEmEstoque();
    }
    return total;
}

int main() {
    // Entrada 1: estoque principal com 5 produtos
    std::vector<Produto> estoque1 = {
        {"Teclado Mecanico", 250.0, 4},
        {"Mouse Gamer", 120.0, 10},
        {"Monitor 24\"", 890.0, 3},
        {"Headset USB", 180.0, 5},
        {"Webcam HD", 210.0, 2}
    };

    // Entrada 2: estoque reduzido
    std::vector<Produto> estoque2 = {
        {"Cabo HDMI", 35.0, 20},
        {"Adaptador USB-C", 60.0, 8}
    };

    // Entrada 3: estoque zerado
    std::vector<Produto> estoque3 = {
        {"Notebook", 3500.0, 0}
    };

    std::cout << "Total Estoque 1 (5 produtos): R$ " << calcularTotalGeral(estoque1) << '\n';
    std::cout << "Total Estoque 2 (2 produtos): R$ " << calcularTotalGeral(estoque2) << '\n';
    std::cout << "Total Estoque 3 (sem unidades): R$ " << calcularTotalGeral(estoque3) << '\n';

    return 0;
}