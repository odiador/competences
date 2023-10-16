#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

double calcDis(int numx, int numy, int num2x, int num2y) {
    return sqrt(pow(numx - num2x, 2) + pow(numy - num2y, 2));
}

int main() {
    int n;
    cin >> n;
    vector<int> arrx(n), arry(n);
    for (int i = 0; i < n; i++)
        cin >> arrx[i] >> arry[i];
    double minProm = 0;
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            if (i != j)
                sum += calcDis(arrx[i], arry[i], arrx[j], arry[j]);
        }
        if (i == 0) minProm = sum / (n - 1);
        else
            minProm = min(sum / (n - 1), minProm);
    }

    cout << setprecision(10) << minProm << endl;
    return 0;
}
