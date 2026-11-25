#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Contato {
private:
    string nome;
    string telefone;
    string email;

public:
    Contato(
        const string& n,
        const string& t,
        const string& e
    ) : nome(n), telefone(t), email(e) {
    }

    string getNome() const {
        return nome;
    }

    void mostrar() const {
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Email: " << email << endl;
    }
};

class Agenda {
private:
    vector<Contato> contatos;

public:
    void cadastrar(const Contato& novoContato) {
        for (const Contato& contato : contatos) {
            if (contato.getNome() ==
                novoContato.getNome()) {

                throw runtime_error(
                    "Contato ja cadastrado!"
                );
            }
        }

        contatos.push_back(novoContato);

        cout << "Contato cadastrado!" << endl;
    }

    bool buscar(const string& nome) const {
        for (const Contato& contato : contatos) {
            if (contato.getNome() == nome) {
                contato.mostrar();
                return true;
            }
        }

        return false;
    }

    bool remover(const string& nome) {
        for (auto it = contatos.begin();
             it != contatos.end(); ++it) {

            if (it->getNome() == nome) {
                contatos.erase(it);
                return true;
            }
        }

        return false;
    }

    void listar() const {
        if (contatos.empty()) {
            cout << "Agenda vazia!" << endl;
            return;
        }

        for (const Contato& contato : contatos) {
            contato.mostrar();

            cout << "--------------------" << endl;
        }
    }
};

int main() {
    Agenda agenda;

    int opcao;
    string nome;
    string telefone;
    string email;

    do {
        cout << "\n===== AGENDA =====" << endl;
        cout << "1 - Cadastrar contato" << endl;
        cout << "2 - Buscar contato" << endl;
        cout << "3 - Remover contato" << endl;
        cout << "4 - Listar contatos" << endl;
        cout << "0 - Sair" << endl;
        cout << "Opcao: ";

        if (!(cin >> opcao)) {
            cout << "Entrada invalida!" << endl;
            return 1;
        }

        try {
            switch (opcao) {

                case 1:
                    cout << "Nome: ";
                    getline(cin >> ws, nome);

                    cout << "Telefone: ";
                    getline(cin, telefone);

                    cout << "Email: ";
                    getline(cin, email);

                    agenda.cadastrar(
                        Contato(nome, telefone, email)
                    );

                    break;

                case 2:
                    cout << "Nome para buscar: ";
                    getline(cin >> ws, nome);

                    if (!agenda.buscar(nome)) {
                        cout << "Contato nao encontrado!"
                             << endl;
                    }

                    break;

                case 3:
                    cout << "Nome para remover: ";
                    getline(cin >> ws, nome);

                    if (agenda.remover(nome)) {
                        cout << "Contato removido!" << endl;
                    } else {
                        cout << "Contato nao encontrado!"
                             << endl;
                    }

                    break;

                case 4:
                    agenda.listar();
                    break;

                case 0:
                    cout << "Encerrando..." << endl;
                    break;

                default:
                    cout << "Opcao invalida!" << endl;
            }

        } catch (const exception& erro) {
            cout << "Erro: " << erro.what() << endl;
        }

    } while (opcao != 0);

    return 0;
}
