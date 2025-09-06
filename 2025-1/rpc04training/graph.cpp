#include <bits/stdc++.h>
using namespace std;

struct UniquePriorityQueue
{
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> s;

    void push(int x)
    {
        if (s.count(x))
            return; // ya existe, no inserto
        pq.push(x);
        s.insert(x);
    }

    void pop()
    {
        if (!pq.empty())
        {
            s.erase(pq.top());
            pq.pop();
        }
    }

    int top()
    {
        return pq.top();
    }

    bool empty()
    {
        return pq.empty();
    }

    int size()
    {
        return pq.size();
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<UniquePriorityQueue> v(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;

        cin >> x >> y;
        v[x - 1].push(y);
        v[y - 1].push(x);
    }

    cout << "------------------" << endl;
    vector<UniquePriorityQueue> bfs = v;

    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1;
        if (!bfs[i].empty())
        {
            cout << ": ";
            while (!bfs[i].empty())
            {
                int top = bfs[i].top();
                bfs[i].pop();
                cout << top << " ";
            }
        }
        else
            cout << " (empty)";
        cout << endl;
    }
    cout << "------------------" << endl;
    vector<UniquePriorityQueue> dfs = bfs;
    for (int i = 0; i < v.size(); i++)
    {
        cout << i + 1;
        if (!dfs[i].empty())
        {
        }
    }

    return 0;
}
