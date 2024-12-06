#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    while(getline(cin,s)) {
        int n, x, c = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x % 2 == 1) c++;
        }
        cout << (c % 2 == 0 ? 1 : 0) << endl;
    }
    return 0;
}