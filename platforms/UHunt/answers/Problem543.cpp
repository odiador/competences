#include <iostream>
#include <cctype>

using namespace std;

bool primes[1000000];


// MUUUY LENTO
void calcPrimes() {
    for (int i = 0; i <= 2; i++) primes[i] = true;
    int p = 3;
    while (p < 1000000) {
        while (primes[p])
            p++;
        cout << "hola " << p << endl;
        for (int i = p * p; i < 1000000; i *= p)
            primes[i] = true;
        p++;
    }
}

bool esParPrimo(int n, int i) {
    return !primes[i] && n > i && !primes[n - 1];
}

int main() {
    cout << "gola" << endl;
    calcPrimes();
    int n, i;
    cout << "gola" << endl;
    bool frag;
    while ((cin >> n) && n != 0) {
        i = 3;
        for (frag = esParPrimo(n, i); i < 1000000 && !frag; i++, frag = esParPrimo(n, i));
        if (frag) cout << n << " = " << i << " + " << n - i << endl;
        else cout << "Goldbach's conjecture is wrong." << endl;
    }
    return 0;
}