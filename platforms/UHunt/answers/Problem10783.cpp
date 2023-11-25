#include <iostream>

using namespace std;

int getOddSum(int i, int j) {
    int x = i % 2 == 0 ? i + 1 : i;
    int sum = 0;
    for (int n = x; n <= j; n += 2)
        sum += n;
    return sum;
}

int main() {
    int i, j, n;
    cin >> n;
    for (int x = 1; x <= n; x++) {
        cin >> i >> j;
        cout << "Case " << x << ": " << getOddSum(i, j) << endl;
    }
    return 0;
}