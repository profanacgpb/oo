#include <iostream>
#include <iomanip>
using namespace std;

constexpr double DESCONTO_TIPO_1 = 0.10;
constexpr double DESCONTO_TIPO_2 = 0.20;
constexpr double TAXA_IMPOSTO = 0.15;

double calcularSubtotal(
    double precoUnitario,
    int quantidade
) {
    return precoUnitario * quantidade;
}

double aplicarDesconto(
    double subtotal,
    int tipoCliente
) {
    if (tipoCliente == 1) {
        return subtotal - subtotal * DESCONTO_TIPO_1;
    }

    if (tipoCliente == 2) {
        return subtotal - subtotal * DESCONTO_TIPO_2;
    }

    return subtotal;
}

double calcularImposto(double valorTotal) {
    return valorTotal * TAXA_IMPOSTO;
}

void imprimirVenda(
    double valorTotal,
    double imposto
) {
    cout << fixed << setprecision(2);

    cout << "Total: R$ "
         << valorTotal << endl;

    cout << "Imposto: R$ "
         << imposto << endl;
}

void processarVenda(
    double precoUnitario,
    int quantidade,
    int tipoCliente
) {
    double subtotal = calcularSubtotal(
        precoUnitario,
        quantidade
    );

    double valorTotal = aplicarDesconto(
        subtotal,
        tipoCliente
    );

    double imposto = calcularImposto(valorTotal);

    imprimirVenda(valorTotal, imposto);
}

int main() {
    double precoUnitario;
    int quantidade;
    int tipoCliente;

    cout << "Preco do produto: ";

    if (!(cin >> precoUnitario)) {
        return 1;
    }

    cout << "Quantidade: ";

    if (!(cin >> quantidade)) {
        return 1;
    }

    cout << "Tipo de cliente:" << endl;
    cout << "0 - Sem desconto" << endl;
    cout << "1 - Desconto de 10%" << endl;
    cout << "2 - Desconto de 20%" << endl;
    cout << "Opcao: ";

    if (!(cin >> tipoCliente)) {
        return 1;
    }

    processarVenda(
        precoUnitario,
        quantidade,
        tipoCliente
    );

    return 0;
}
