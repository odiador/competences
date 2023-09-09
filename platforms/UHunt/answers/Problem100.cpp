#include <iostream>

using namespace std;

int getNumSequences(int n) {
    int i = 1;
    while (n != 1) {
        n = n % 2 == 1 ? n * 3 + 1 : n / 2;
        i++;
    }
    return i;
}

int main() {
    int i, j;
    while (cin >> i >> j) {

        int inicio = i > j ? j : i;
        int fin = i == inicio ? j : i;
        int answer = 0;
        for (int n = inicio; n <= fin; n++) {
            int sequences = getNumSequences(n);
            if (sequences > answer) answer = sequences;
        }

        cout << i << " " << j << " " << answer << endl;
    }
    return 0;
}
