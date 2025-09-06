#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    stack<int> s;
    for (int num : a) {
        while (!s.empty() && s.top() == num) {
            num *= 2;  // Fusionar
            s.pop();
        }
        s.push(num);
    }

    // Encontrar el máximo en la pila
    int max_val = 0;
    while (!s.empty()) {
        max_val = max(max_val, s.top());
        s.pop();
    }
    cout << max_val << "\n";

    return 0;
}