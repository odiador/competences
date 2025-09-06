

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double vol, min = 1.1e9;
    cin >> n >> vol;
    vol /= 3.14159265358979323846;
    int idx = -1;
    int h, b;
    double v;
    for (int i = 0; i < n; i++)
    {
        cin >> h >> b;
        v = h * b * b;
        if (v >= vol && v < min)
        {
            idx = i + 1;
            min = v;
        }
    }
    cout << (idx == -1 ? "impossible" : to_string(idx)) << endl;
    return 0;
}
