#include <iostream>
#include <vector>
#include <string>


using namespace std;

string getResult(vector<string> vector1, int n);

string geResultAux(vector<string> vector1, int n, int i);

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
        cin >> words[i];
    cout << getResult(words, n) << endl;
}

string getResult(vector<string> vector1, int n) {
    return geResultAux(vector1, n, 0);
}

string geResultAux(vector<string> vector1, int n, int i) {
    if (i == n)return "";
    return geResultAux(vector1, n, i + 1);
}
