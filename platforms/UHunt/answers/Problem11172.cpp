#include <iostream>

using namespace std;

int main() {
    int num, n, k;
    cin >> num;
    for (int i = 0; i < num; i++) {
        cin >> n >> k;
        if (n < k) cout << "<";
        else if (n > k) cout << ">";
        else cout << "=";
        cout << endl;
    }
    return 0;
}