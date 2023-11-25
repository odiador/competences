#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        for (int test = 0; test < n; test++) {
            int f, cant = 0;
            cin >> f;
            for (int i = 0; i < f; i++) {
                int size, animals, env;
                std::cin >> size >> animals >> env;
                cant += size * env;
            }
            cout << cant << endl;
        }
    }

}