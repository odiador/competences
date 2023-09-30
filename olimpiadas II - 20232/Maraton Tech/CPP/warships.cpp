#include <iostream>

using namespace std;

int main() {
    string s, s2, aux, name;
    int turn = 0, cant;
    if (getline(cin, aux)) {
        int pos = aux.find(' ');
        name = aux.substr(0, pos);
        cant = stoi(aux.substr(pos, aux.length()));
    }
    while (getline(cin, aux)) {
        if (turn % 2 == 0) {}
        pos = s.find(' ');
        name = s.substr(0, pos);
        cant = stoi(s.substr(pos, s.length()));
        turn++;
    }
    return 0;
}