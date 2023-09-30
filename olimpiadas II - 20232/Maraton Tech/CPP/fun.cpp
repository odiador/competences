//
// Created by juana on 15/09/2023.
//
#include <iostream>

using namespace std;

int main() {
    int n, i, j;
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> i >> j;
        for (int u = i; u <= j; u++) {
            if (u % 5 == 2 || u % 5 == 3)
                cout << u << '-';
        }
        cout << endl;
    }

    return 0;
}