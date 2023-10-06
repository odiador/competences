#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> values(n, vector<int>(12));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 12; j++) {
            cin >> values[i][j];
        }
    }

    vector<vector<int>> result(n + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int x = 0; x <= 12; x++) {
                if (x <= j) {
                    int sum = 0;
                    for (int y = 0; y < x; y++) {
                        sum += values[i - 1][y];
                    }
                    result[i][j] = max(result[i][j], sum + result[i - 1][j - x]);
                }
            }
        }
    }
    cout << result[n][k] << endl;
    return 0;
}