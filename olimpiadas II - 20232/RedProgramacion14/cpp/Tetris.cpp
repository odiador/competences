#include <iostream>
#include <vector>
#include <array>

using namespace std;

int main() {
    vector<int> nums;
    vector<array<array<char, 3>, 3>> mat;

    mat.push_back({{{'A', '-', '-'},
                    {'B', '-', '-'},
                    {'C', 'D', '-'}}});
    mat.push_back({{{'-', '-', 'A'},
                    {'-', '-', 'B'},
                    {'-', 'D', 'C'}}});

    mat.push_back({{{'-', '-', '-'},
                    {'A', 'B', '-'},
                    {'-', 'C', 'D'}}});

    mat.push_back({{{'-', '-', '-'},
                    {'-', 'C', 'D'},
                    {'A', 'B', '-'}}});

    mat.push_back({{{'-', '-', '-'},
                    {'-', 'D', '-'},
                    {'A', 'B', 'C'}}});

    mat.push_back({{{'-', '-', '-'},
                    {'A', 'B', '-'},
                    {'C', 'D', '-'}}});
    int f, r, state;
    cin >> f >> r;
    f = f - 1;
    state = 0;
    int arr[r];
    for (int &i: arr)
        cin >> i;
    for (int i = 0; i < r; i++) {
        switch (arr[i]) {
            case 90:
            case -270:
                state++;
                break;
            case -90:
            case 270:
                state--;
                break;
            case 180:
            case -180:
                state += 2;
                break;
        }
    }
    state = state % 4;
    if (state < 0)
        state += 4;

    switch (state) {
        case 0:
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cout << mat[f][i][j];
                }
                cout << endl;
            }
            break;
        case 1:
            for (int j = 0; j < 3; j++) {
                for (int i = 2; i >= 0; i--) {
                    cout << mat[f][i][j];
                }
                cout << endl;
            }
            break;
        case 2:
            for (int i = 2; i >= 0; i--) {
                for (int j = 2; j >= 0; j--) {
                    cout << mat[f][i][j];
                }
                cout << endl;
            }
            break;
        case 3:
            for (int j = 2; j >= 0; j--) {
                for (auto &i: mat[f]) {
                    cout << i[j];
                }
                cout << endl;
            }
            break;
        default:
            break;
    }

    return 0;
}