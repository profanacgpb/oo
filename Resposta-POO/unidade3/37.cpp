#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Imprimivel {
public:
    virtual void imprimir() const = 0;

    virtual ~Imprimivel() = default;
};

class Relatorio : public Imprimivel {
private:
    string titulo;
    string conteudo;

public:
    Relatorio(const string& t, const string& c)
        : titulo(t), conteudo(c) {
    }

    void imprimir() const override {
        cout << "===== RELATORIO =====" << endl;

        cout << "Titulo: " << titulo << endl;

        cout << "Conteudo: " << conteudo << endl;
    }
};

class Fatura : public Imprimivel {
private:
    string cliente;
    double valor;

public:
    Fatura(const string& c, double v)
        : cliente(c), valor(v) {
    }

    void imprimir() const override {
        cout << "===== FATURA =====" << endl;

        cout << "Cliente: " << cliente << endl;

        cout << fixed << setprecision(2);

        cout << "Valor: R$ " << valor << endl;
    }
};

void imprimirDocumento(const Imprimivel& documento) {
    documento.imprimir();

    cout << endl;
}

int main() {
    Relatorio relatorio(
        "Relatorio Academico",
        "Todos os alunos foram cadastrados."
    );

    Fatura fatura("Pedro", 250.00);

    imprimirDocumento(relatorio);

    imprimirDocumento(fatura);

    return 0;
}
