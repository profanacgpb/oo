#include <iostream>
#include <memory>
using namespace std;

class Base {
public:
    virtual ~Base() {
        cout << "Destrutor da Base" << endl;
    }
};

class Derivada : public Base {
private:
    unique_ptr<int[]> dados;

public:
    Derivada()
        : dados(make_unique<int[]>(100)) {

        cout << "Objeto criado!" << endl;
    }

    ~Derivada() override {
        cout << "Destrutor da Derivada" << endl;
    }
};

int main() {
    Base* objeto = new Derivada();

    delete objeto;

    return 0;
}
