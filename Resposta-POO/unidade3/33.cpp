#include <iostream>
using namespace std;

class Animal {
public:
    virtual void emitirSom() const {
        cout << "Som de animal" << endl;
    }

    virtual ~Animal() = default;
};

class Cachorro : public Animal {
public:
    void emitirSom() const override {
        cout << "Cachorro: Au au!" << endl;
    }
};

class Gato : public Animal {
public:
    void emitirSom() const override {
        cout << "Gato: Miau!" << endl;
    }
};

int main() {
    Animal animal;
    Cachorro cachorro;
    Gato gato;

    Animal* animais[] = {
        &animal,
        &cachorro,
        &gato
    };

    for (Animal* a : animais) {
        a->emitirSom();
    }

    return 0;
}
