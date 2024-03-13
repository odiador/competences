#include <iostream>

using namespace std;

// NOT SOLVED
int main() {
    unsigned long i, j;
    while (cin >> i >> j && i != 0 && j != 0) {
        unsigned long total = 0, actualCarry = 0;
        while ((i > 0 && j > 0) || actualCarry == 1) {
            actualCarry = (i % 10 + j % 10 + actualCarry) / 10;
            total += actualCarry;
            i /= 10;
            j /= 10;
        }
        if (total == 0)
            cout << "No carry operation." << endl;
        else if (total == 1)
            cout << "1 carry operation" << endl;
        else
            cout << total << " carry operations." << endl;
    }
    return 0;
}