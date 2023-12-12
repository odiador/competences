#include <iostream>
#include <utility>

using namespace std;

pair<int, int> calc(long long num) {
    int total = 0;
    int i = 2;

    while (num >= 3) {
        long long triangles = i * (i + 1) / 2;
        if (num < triangles) {
            i = 2;
        } else {
            total++;
            num -= triangles;
            i++;
        }
    }
    return make_pair(total, static_cast<int>(num));
}

int main() {
    long long num;
    while (cin >> num) {
        pair<int, int> resultado = calc(num);
        cout << resultado.first << " " << resultado.second << endl;
    }
    return 0;
}
