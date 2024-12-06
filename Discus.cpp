#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int maxn = 0;
    deque<int> dq;

    for (int i = 0; i < n; i++) {
        if (!dq.empty() && dq.front() < i - m) {
            dq.pop_front();
        }

        if (!dq.empty()) {
            maxn = max(maxn, array[i] - array[dq.front()]);
        }

        while (!dq.empty() && array[dq.back()] >= array[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    cout << maxn << endl;
    return 0;
}
