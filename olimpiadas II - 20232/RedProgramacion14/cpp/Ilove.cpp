#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<string> arr;
    long long n, res;
    int dig;
    while (cin >> n >> dig) {
        int digN = n % 10;
        if (digN == dig)
            res = n + 10;
        if (digN < dig)
            res = n - digN + dig;
        if (digN > dig)
            res = n + 10 - (digN - dig);
        cout << res << endl;
    }
    return 0;
}