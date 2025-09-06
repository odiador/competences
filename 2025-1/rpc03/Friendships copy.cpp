#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n, amistades;
    cin >> n >> amistades;
    unordered_map<long int, unordered_set<long int>> mapa(n);
    for (long int i = 0; i < amistades; i++)
    {

        long int x, y;
        cin >> x >> y;
        if (x > y)
            swap(x, y);
        mapa[x].insert(x);
        mapa[x].insert(y);
        mapa[y].insert(y);
    }

    long int cnt = 0;
    for (auto &a : mapa)
    {
        unordered_set<long int> sett = a.second;
        for (auto cadaElm : sett)
        {
            unordered_set<long int> vectorAagregar = mapa[cadaElm];
            for (long int elem : vectorAagregar)
            {
                if (sett.count(elem) == 0)
                {
                    cout << cadaElm << ": " << elem << endl;
                    sett.insert(elem);
                    cnt++;
                }
            }
        }
        a.second = sett;
    }
    cout << cnt << endl;

    return 0;
}