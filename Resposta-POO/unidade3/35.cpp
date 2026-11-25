#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <string>
#include <stdexcept>
#include <iomanip>
using namespace std;

constexpr double PI = 3.141592653589793;

class Forma {
public:
    virtual double area() const = 0;

    virtual double perimetro() const = 0;

    virtual string getNome() const = 0;

    virtual ~Forma() = default;
};

class Circulo : public Forma {
private:
    double raio;

public:
    Circulo(double r) : raio(r) {
        if (r <= 0) {
            throw invalid_argument("Raio invalido!");
        }
    }

    double area() const override {
        return PI * raio * raio;
    }

    double perimetro() const override {
        return 2 * PI * raio;
    }

    string getNome() const override {
        return "Circulo";
    }
};

class Retangulo : public Forma {
private:
    double largura;
    double altura;

public:
    Retangulo(double l, double h)
        : largura(l), altura(h) {

        if (l <= 0 || h <= 0) {
            throw invalid_argument("Dimensoes invalidas!");
        }
    }

    double area() const override {
        return largura * altura;
    }

    double perimetro() const override {
        return 2 * (largura + altura);
    }

    string getNome() const override {
        return "Retangulo";
    }
};

class Triangulo : public Forma {
private:
    double a;
    double b;
    double c;

public:
    Triangulo(double x, double y, double z)
        : a(x), b(y), c(z) {

        if (a <= 0 || b <= 0 || c <= 0 ||
            a + b <= c ||
            a + c <= b ||
            b + c <= a) {

            throw invalid_argument("Triangulo invalido!");
        }
    }

    double perimetro() const override {
        return a + b + c;
    }

    double area() const override {
        double s = perimetro() / 2.0;

        return sqrt(
            s * (s - a) * (s - b) * (s - c)
        );
    }

    string getNome() const override {
        return "Triangulo";
    }
};

int main() {
    try {
        vector<unique_ptr<Forma>> formas;

        formas.push_back(make_unique<Circulo>(3));

        formas.push_back(make_unique<Retangulo>(5, 4));

        formas.push_back(make_unique<Triangulo>(3, 4, 5));

        sort(
            formas.begin(),
            formas.end(),
            [](const auto& a, const auto& b) {
                return a->area() < b->area();
            }
        );

        cout << fixed << setprecision(2);

        for (const auto& forma : formas) {

            cout << "Forma: "
                 << forma->getNome() << endl;

            cout << "Area: "
                 << forma->area() << endl;

            cout << "Perimetro: "
                 << forma->perimetro() << endl;

            cout << "--------------------" << endl;
        }

    } catch (const exception& erro) {
        cout << "Erro: " << erro.what() << endl;
    }

    return 0;
}
