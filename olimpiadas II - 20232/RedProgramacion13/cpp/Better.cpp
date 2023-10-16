#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> firstDie(n);
    vector<int> secondDie(n);

    for (int i = 0; i < n; i++) {
        cin >> firstDie[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> secondDie[i];
    }

    int firstDieProb = 0;
    int secondDieProb = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (firstDie[i] > secondDie[j]) {
                firstDieProb++;
            } else if (firstDie[i] < secondDie[j]) {
                secondDieProb++;
            }
        }
    }

    if (firstDieProb > secondDieProb) {
        cout << "first" << endl;
    } else if (firstDieProb < secondDieProb) {
        cout << "second" << endl;
    } else {
        cout << "tie" << endl;
    }

    return 0;
}