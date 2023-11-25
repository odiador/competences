#include <iostream>
#include <cctype>

using namespace std;

// NOT SOLVED
int main() {
    int m, n, index = 1;
    while (cin >> n >> m && (m != 0 || n != 0)) {
        char arr[n][m], arrcopy[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
                arrcopy[i][j] = arr[i][j];
            }
        }
        int count = 48;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++, count = 48) {
                if (arr[i][j] == '*') continue;
                if (i > 0 && j > 0 && arr[i - 1][j - 1] == '*')
                    count++;
                if (i > 0 && arr[i - 1][j] == '*')
                    count++;
                if (i > 0 && j < m - 1 && arr[i - 1][j + 1] == '*')
                    count++;
                if (j > 0 && arr[i][j - 1] == '*')
                    count++;
                if (j < m - 1 && arr[i][j + 1] == '*')
                    count++;
                if (i < n - 1 && j > 0 && arr[i + 1][j - 1] == '*')
                    count++;
                if (i < n - 1 && arr[i + 1][j] == '*')
                    count++;
                if (i < n - 1 && j < m - 1 && arr[i + 1][j + 1] == '*')
                    count++;
                arrcopy[i][j] = (char) count;
            }
        }
        cout << endl << "Field #" << index << ":" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << arrcopy[i][j];
            }
            cout << endl;
        }
        index++;
    }
    return 0;
}