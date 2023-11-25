#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int i, j, k, n;
    cin >> n;
    vector<int> vect;
    for (int x = 1; x <= n; x++) {
        vect.clear();
        cin >> i >> j >> k;
        vect.push_back(i);
        vect.push_back(j);
        vect.push_back(k);
        sort(vect.begin(), vect.end());
        cout << "Case " << x << ": " << vect[1] << endl;
    }
    return 0;
}