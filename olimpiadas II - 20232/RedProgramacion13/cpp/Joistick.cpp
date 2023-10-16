#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    char newWinner[n];
    char record[n];
    cin >> newWinner >> record;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (record[i] == newWinner[i])
            continue;
        char mayor = newWinner[i];
        if (record[i] > newWinner[i])
            mayor = record[i];
        char fromZ = 'Z' - mayor + 1;
        if (mayor == record[i]) {
            fromZ += newWinner[i];
        } else
            fromZ += record[i];
    }
    return 0;
}