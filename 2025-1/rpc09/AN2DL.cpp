#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> mat[i][j];

    int r, s;
    cin >> r >> s;

    // Paso 1: Ventana deslizante horizontal
    vector<vector<int>> horizMax(n, vector<int>(m - s + 1));
    for (int i = 0; i < n; ++i)
    {
        deque<int> dq;
        for (int j = 0; j < m; ++j)
        {
            while (!dq.empty() && mat[i][dq.back()] <= mat[i][j])
                dq.pop_back();
            dq.push_back(j);
            if (dq.front() <= j - s)
                dq.pop_front();
            if (j >= s - 1)
                horizMax[i][j - s + 1] = mat[i][dq.front()];
        }
    }

    // Paso 2: Ventana deslizante vertical sobre horizMax
    vector<vector<int>> result(n - r + 1, vector<int>(m - s + 1));
    for (int j = 0; j < m - s + 1; ++j)
    {
        deque<int> dq;
        for (int i = 0; i < n; ++i)
        {
            while (!dq.empty() && horizMax[dq.back()][j] <= horizMax[i][j])
                dq.pop_back();
            dq.push_back(i);
            if (dq.front() <= i - r)
                dq.pop_front();
            if (i >= r - 1)
                result[i - r + 1][j] = horizMax[dq.front()][j];
        }
    }

    int endJ = m - s + 1;
    // Imprimir el resultado
    for (int i = 0; i < n - r + 1; ++i)
    {
        for (int j = 0; j < endJ; ++j)
        {
            cout << result[i][j] << (j + 1 == endJ ? '\n' : ' ');;
        }
    }

    return 0;
}
