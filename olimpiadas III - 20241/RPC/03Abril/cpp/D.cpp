#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> divisores;
    divisores.push_back(1);
    for (int i = 2; i <= n / 3; i++)
        if (n % i == 0) divisores.push_back(i);
    if (n % (n / 2) == 0)
        divisores.push_back(n / 2);
    divisores.push_back(n);
    for (int &i: divisores) cout << i << ' ';
    cout << endl;
    cout << divisores.size() << endl;
    return 0;
}