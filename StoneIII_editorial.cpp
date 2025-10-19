#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int stones[n];
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int dp[n + 1];
    dp[0] = 0; // No stones, no cost
    dp[1] = 0; // First stone, no cost

    for (int i = 2; i <= n; i++) {
        dp[i] = INT32_MAX;
        for (int j = 1; j <= 3; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(stones[i - 1] - stones[i - j]));
            }
        }
    }

    cout << dp[n] << endl;
    return 0;
}