#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> arr;
    string x, y, z;
    string final, aux;
    while (cin >> x >> y >> z) {
        arr.clear();
        arr.push_back(x);
        arr.push_back(y);
        arr.push_back(z);
        final = arr[0] + arr[1] + arr[2];

        aux = arr[0] + arr[2] + arr[1];
        if (aux.compare(final) > 0)
            final = aux;
        aux = arr[1] + arr[0] + arr[2];
        if (aux.compare(final) > 0)
            final = aux;
        aux = arr[1] + arr[2] + arr[0];
        if (aux.compare(final) > 0)
            final = aux;
        aux = arr[2] + arr[1] + arr[0];
        if (aux.compare(final) > 0)
            final = aux;
        aux = arr[2] + arr[0] + arr[1];
        if (aux.compare(final) > 0)
            final = aux;
        cout << final << endl;
    }
    return 0;
}