#include <iostream>
using namespace std;

int main() {
    int A[5], L[5], N, KWF;
    for (int i = 0; i < 5; ++i) cin >> A[i] >> L[i];
    cin >> N >> KWF;

    int total_kernels = 0;
    for (int i = 0; i < 5; ++i) total_kernels += A[i] * L[i];
    int avg_kernels = total_kernels / 5;

    int bushels = (avg_kernels * N) / KWF;
    cout << bushels << endl;

    return 0;
}