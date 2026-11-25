#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
using namespace std;

class Item {
private:
    string nome;
    double preco;
    int quantidade;

public:
    Item(const string& n, double p, int q)
        : nome(n), preco(p), quantidade(q) {

        if (p < 0 || q <= 0) {
            throw invalid_argument("Item invalido!");
        }
    }

    string getNome() const {
        return nome;
    }

    int getQuantidade() const {
        return quantidade;
    }

    double subtotal() const {
        return preco * quantidade;
    }
};

class Carrinho {
private:
    vector<Item> itens;

public:
    void adicionar(const Item& item) {
        itens.push_back(item);

        cout << "Item adicionado: "
             << item.getNome() << endl;
    }

    bool remover(const string& nome) {
        for (auto it = itens.begin();
             it != itens.end(); ++it) {

            if (it->getNome() == nome) {
                itens.erase(it);
                return true;
            }
        }

        return false;
    }

    double total() const {
        double valorTotal = 0;

        for (const Item& item : itens) {
            valorTotal += item.subtotal();
        }

        return valorTotal;
    }

    void listar() const {
        cout << fixed << setprecision(2);

        cout << "\n===== CARRINHO =====" << endl;

        for (const Item& item : itens) {
            cout << item.getNome()
                 << " | Quantidade: "
                 << item.getQuantidade()
                 << " | R$ "
                 << item.subtotal()
                 << endl;
        }

        cout << "Total: R$ "
             << total() << endl;
    }
};

int main() {
    try {
        Carrinho carrinho;

        carrinho.adicionar(Item("Mouse", 50, 2));
        carrinho.adicionar(Item("Teclado", 100, 1));
        carrinho.adicionar(Item("Monitor", 800, 1));

        carrinho.listar();

        if (carrinho.remover("Teclado")) {
            cout << "\nItem removido!" << endl;
        }

        carrinho.listar();

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
