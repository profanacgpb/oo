#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Produto {
public:
    string nome;
    double preco;
    int quantidade;

    double valorTotalEmEstoque() {
        return preco * quantidade;
    }
};

int main() {
    vector<Produto> produtos;

    Produto p1;
    p1.nome = "PIppos";
    p1.preco = 2.5;
    p1.quantidade = 100;
    produtos.push_back(p1);

    Produto p2;
    p2.nome = "Miojo";
    p2.preco = 1000000000;  //KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK
    p2.quantidade = 40;
    produtos.push_back(p2);

    Produto p3;
    p3.nome = "Cimento";
    p3.preco = 43;
    p3.quantidade = 10;
    produtos.push_back(p3);

    Produto p4;
    p4.nome = "Lapis";
    p4.preco = 1;
    p4.quantidade = 200;
    produtos.push_back(p4);

    Produto p5;
    p5.nome = "Coca COla";
    p5.preco = 12;
    p5.quantidade = 150;
    produtos.push_back(p5);

    double total = 0;
    for (int i = 0; i < produtos.size(); i++) {
        cout << produtos[i].nome << ": R$ " << produtos[i].valorTotalEmEstoque() << endl;
        total = total + produtos[i].valorTotalEmEstoque();
    }

    cout << "Valor total: R$ " << total << endl;

    return 0;
}