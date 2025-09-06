#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) cin >> A[i];

    vector<int> max_left(n), min_right(n);
    max_left[0] = INT_MIN; // No hay elementos a la izquierda del primero.
    for (int i = 1; i < n; ++i) {
        max_left[i] = max(max_left[i-1], A[i-1]);
    }

    min_right[n-1] = INT_MAX; // No hay elementos a la derecha del último.
    for (int i = n-2; i >= 0; --i) {
        min_right[i] = min(min_right[i+1], A[i+1]);
    }

    vector<int> pivots;
    for (int i = 0; i < n; ++i) {
        if (max_left[i] <= A[i] && A[i] < min_right[i]) {
            pivots.push_back(A[i]);
        }
    }

    cout << pivots.size();
    if (!pivots.empty()) {
        cout << " ";
        int limit = min(100, (int)pivots.size());
        for (int i = 0; i < limit; ++i) {
            if (i > 0) cout << " ";
            cout << pivots[i];
        }
    }
    cout << "\n";

    return 0;
}