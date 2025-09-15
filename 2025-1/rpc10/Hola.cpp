#include <bits/stdc++.h>
using namespace std;

bool sameState(queue<int> q1, queue<int> q2)
{
    if (q1.size() != q2.size())
        return false;
    while (!q1.empty())
    {
        if (q1.front() != q2.front())
            return false;
        return true;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int nIzq, nDer;
    while (cin >> nIzq >> nDer)
    {
        queue<int> q1, q2, q1_init, q2_init;

        for (int i = 1; i <= nIzq; i++)
        {
            q1.push(i);
            q1_init.push(i);
        }
        for (int i = 1; i <= nDer; i++)
        {
            q2.push(nIzq + i);
            q2_init.push(nIzq + i);
        }

        set<pair<int, int>> pares;

        do
        {
            pares.insert({q1.front(), q2.front()});
            pares.insert({q2.front(), q1.front()});

            int front = q1.front();
            q1.pop();
            q2.push(front);

            pares.insert({q1.front(), q2.front()});
            pares.insert({q2.front(), q1.front()});

            int frontDer = q2.front();
            q2.pop();
            q1.push(frontDer);

        } while (!(sameState(q1, q1_init) && sameState(q2, q2_init)));

        cout << pares.size() / 2 << "\n";
    }

    return 0;
}