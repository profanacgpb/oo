#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

class Personagem {
private:
    string nome;
    int vida;

public:
    Personagem(const string& n, int v)
        : nome(n), vida(v) {
    }

    string getNome() const {
        return nome;
    }

    int getVida() const {
        return vida;
    }

    bool estaVivo() const {
        return vida > 0;
    }

    void receberDano(int dano) {
        if (dano > 0) {
            vida = max(0, vida - dano);
        }
    }

    virtual void atacar(Personagem& alvo) = 0;

    virtual ~Personagem() = default;
};

class Guerreiro : public Personagem {
public:
    Guerreiro(const string& nome)
        : Personagem(nome, 120) {
    }

    void atacar(Personagem& alvo) override {
        cout << getNome()
             << " atacou com uma espada!" << endl;

        alvo.receberDano(25);
    }
};

class Mago : public Personagem {
public:
    Mago(const string& nome)
        : Personagem(nome, 80) {
    }

    void atacar(Personagem& alvo) override {
        cout << getNome()
             << " lancou uma bola de fogo!" << endl;

        alvo.receberDano(35);
    }
};

class Arqueiro : public Personagem {
public:
    Arqueiro(const string& nome)
        : Personagem(nome, 100) {
    }

    void atacar(Personagem& alvo) override {
        cout << getNome()
             << " disparou uma flecha!" << endl;

        alvo.receberDano(20);
    }
};

using Equipe = vector<unique_ptr<Personagem>>;

bool equipeViva(const Equipe& equipe) {
    for (const auto& personagem : equipe) {
        if (personagem->estaVivo()) {
            return true;
        }
    }

    return false;
}

Personagem* encontrarAlvo(Equipe& equipe) {
    for (auto& personagem : equipe) {
        if (personagem->estaVivo()) {
            return personagem.get();
        }
    }

    return nullptr;
}

void realizarTurno(
    Equipe& atacantes,
    Equipe& defensores
) {
    for (auto& atacante : atacantes) {

        if (!atacante->estaVivo()) {
            continue;
        }

        Personagem* alvo = encontrarAlvo(defensores);

        if (alvo == nullptr) {
            return;
        }

        atacante->atacar(*alvo);

        cout << alvo->getNome()
             << " possui "
             << alvo->getVida()
             << " pontos de vida."
             << endl;

        if (!alvo->estaVivo()) {
            cout << alvo->getNome()
                 << " foi derrotado!"
                 << endl;
        }

        cout << endl;
    }
}

void mostrarEquipe(const Equipe& equipe) {
    for (const auto& personagem : equipe) {

        cout << personagem->getNome()
             << " | Vida: "
             << personagem->getVida()
             << endl;
    }
}

int main() {
    Equipe equipe1;
    Equipe equipe2;

    equipe1.push_back(
        make_unique<Guerreiro>("Arthur")
    );

    equipe1.push_back(
        make_unique<Mago>("Merlin")
    );

    equipe1.push_back(
        make_unique<Arqueiro>("Robin")
    );

    equipe2.push_back(
        make_unique<Guerreiro>("Darius")
    );

    equipe2.push_back(
        make_unique<Mago>("Morgana")
    );

    equipe2.push_back(
        make_unique<Arqueiro>("Legolas")
    );

    int rodada = 1;

    while (equipeViva(equipe1) &&
           equipeViva(equipe2)) {

        cout << "===== RODADA "
             << rodada
             << " ====="
             << endl;

        cout << "Turno da equipe 1" << endl;

        realizarTurno(equipe1, equipe2);

        if (equipeViva(equipe2)) {

            cout << "Turno da equipe 2" << endl;

            realizarTurno(equipe2, equipe1);
        }

        cout << "Status da equipe 1:" << endl;
        mostrarEquipe(equipe1);

        cout << "Status da equipe 2:" << endl;
        mostrarEquipe(equipe2);

        cout << endl;

        rodada++;
    }

    if (equipeViva(equipe1)) {
        cout << "Equipe 1 venceu!" << endl;
    } else {
        cout << "Equipe 2 venceu!" << endl;
    }

    return 0;
}
