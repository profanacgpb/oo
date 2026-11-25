#include <iostream>
#include <vector>
using namespace std;

int main() {
    int total = 0;

    vector<int> numeros = {10, 20, 30};

    for (int numero : numeros) {
        total += numero;
    }

    cout << total << endl;

    return 0;
}
