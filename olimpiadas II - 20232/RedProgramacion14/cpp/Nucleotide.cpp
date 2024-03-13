#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

struct Nucleotido {
    int cant;
    char ch;
    int importancia;
};


bool comp(const Nucleotido n1, const Nucleotido n2) {
    return n1.cant != n2.cant ? n1.cant > n2.cant : n1.importancia > n2.importancia;
}

int main() {
    string s;
    int n;
    if (!getline(cin, s))
        return 0;
    if (!(cin >> n))
        return 0;

    for (int x = 0; x < n; x++) {
        int min, max;
        int a = 0, t = 0, g = 0, c = 0;
        if (cin >> min >> max) {
            for (int i = min - 1; i < max; i++) {
                if (s[i] == 'A') a++;
                if (s[i] == 'T') t++;
                if (s[i] == 'G') g++;
                if (s[i] == 'C') c++;
            }
            vector<Nucleotido> mp = {
                    {a, 'A', 3},
                    {t, 'T', 2},
                    {g, 'G', 1},
                    {c, 'C', 0},
            };
            sort(mp.begin(), mp.end(), comp);
            for (int i = 0; i < 4; i++) cout << mp[i].ch;
            cout << endl;
        }
    }
    return 0;
}



