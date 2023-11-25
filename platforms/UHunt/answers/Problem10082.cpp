#include <iostream>

using namespace std;

int main() {
    string cad, info = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./", msg;
    while (getline(cin, cad)) {
        msg = "";
        for (char c: cad) {
            if (c == ' ') {
                msg.append(" ");
                continue;
            }
            unsigned long long pos = info.find(c) - 1;
            msg.push_back(info.at(pos));
        }
        cout << msg << endl;
    }
    return 0;
}