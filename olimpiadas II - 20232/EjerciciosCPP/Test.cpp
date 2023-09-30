#include <iostream>
#include <string>

bool notSorted(const long int *arr, int len);

void printArr(const long int *arr, int len);

using namespace std;

int main() {
    long int arr[5];
    int len = 5;
    for (long int &i: arr)
        cin >> i;
    while (notSorted(arr, len)) {
        for (int i = 0; i < len - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int aux = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = aux;
                break;
            }
        }
        printArr(arr, len);
    }
    return 0;
}

void printArr(const long int *arr, const int len) {
    string s;
    for (int i = 0; i < len; i++) {
        s.append(to_string(arr[i]));
        s.append(" ");
    }
    cout << s << endl;
}

bool notSorted(const long int *arr, const int len) {
    for (int i = 0; i < len - 1; i++)
        if (arr[i] > arr[i + 1]) return true;
    return false;
}
