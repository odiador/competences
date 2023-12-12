#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

class Entrada {
public:
    int key;
    int value;

    Entrada(int key, int value) {
        this->key = key;
        this->value = value;
    }

    bool operator<(const Entrada &o) const {
        if (value == o.value) {
            return key < o.key;
        }
        return value < o.value;
    }
};

// NOT SOLVED
int main() {
    int multi = 1;
    map<int, int> lista;
    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        regex regex("\\s+");
        sregex_token_iterator iter(line.begin(), line.end(), regex, -1);
        sregex_token_iterator end;
        std::vector<std::string> tokens(iter, end);
        lista[stoi(tokens[1])] = stoi(tokens[2]);
    }
    int cant;
    cin >> cant;
    int aux = cant;
    vector<Entrada> lista1;

    const int tam = lista.size();
    while (aux > 0) {
        for (const auto &entry: lista) {
            int key = entry.first;
            int value = entry.second;
            lista1.emplace_back(key, value * multi);
        }
        aux -= tam;
        multi++;
    }
    sort(lista1.begin(), lista1.end());

    for (int i = 0; i < cant; i++)
        cout << lista1[i].key << endl;

    return 0;
}
