#include <iostream>
#include <string>

using namespace std;

int main() {
    int cant;
    cin >> cant;
    int index, service, arrival, patience, finalTime;
    string result;
    for (int i = 0; i < cant; i++) {
        cin >> index >> arrival >> service >> patience;
        if (index == 1) {
            finalTime = arrival + service;
            result.append(to_string(index));
            result.append("\n");
            continue;
        }
        if (arrival + patience >= finalTime) {
            finalTime = (arrival > finalTime ? arrival : finalTime) + service;
            result.append(to_string(index));
            result.append("\n");
        }
    }
    cout << result;

    return 0;
}