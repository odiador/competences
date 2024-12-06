#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int x;
    while (cin >> x) {
        vector<int> vect;
        vector<int> positions;
        for (int i = 0; i < x; ++i) {
            int n;
            cin >> n;
            vect.push_back(n);
        }

        positions.push_back(-1);
        
        for (int i = 1; i < x; ++i) {
            if (vect[i - 1] > vect[i]) {
                positions.push_back(i - 1);
            }
        }
        positions.push_back(x - 1);
        if (positions.size() != 2) {
            int maxi = 0;
            for (int i = 0; i < positions.size() - 2; ++i) {
                maxi = max(positions[i + 2] - positions[i], maxi);
            }
            cout << maxi << endl;
        } else {
            cout << x << endl;
        }
    }

    return 0;
}