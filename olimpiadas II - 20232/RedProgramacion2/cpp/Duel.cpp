#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int &i: array)
        cin >> i;
    int cant = 0;
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > array[i]) {
            array[j + 1] = array[j];
            j--;
            cant++;
        }
        array[j + 1] = key;
    }
    cout << cant << endl;
    cout << ((cant % 2 == 0) ? "Oh No!" : "Smokin Joe!") << endl;
    return 0;
}