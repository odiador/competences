#include <iostream>
#include <string>

using namespace std;

int main() {
    string cad;
    while (getline(cin, cad)) {
        string msg;
        for (char i : cad)
            msg += static_cast<char>(i - 7);
        cout << msg << endl;
    }
    return 0;
}